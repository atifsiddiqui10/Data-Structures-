#include "BST.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

//********Constructor and Destructor and helper functions ***********//
BST::BST ()
{
  rootptr = nullptr;
}

BST::~BST()
{
  deleteTree(rootptr);
}

void BST::deleteTree(Node*root)
{
  if(!root)
  {
    return;
  }
  deleteTree(root -> getLeft());
  deleteTree(root -> getRight());
  delete root;
  root = nullptr;
  return;
}

int BST::getHeight(Node* subTreeptr)
{
  if( subTreeptr == nullptr)
  {
    return 0;
  }
  else
  {
    int left = getHeight(subTreeptr -> getLeft());
    int right = getHeight(subTreeptr -> getRight());

    if(left > right)
    {
      return (left + 1);
    }
    else
    {
      return (right + 1);
    }
  }
}

Node* BST::findkey(int key)
{
  Node* temp = rootptr;
  while(temp -> getValue() != key && temp != nullptr)
  {
    if(key > temp -> getValue())
    {
      temp = temp -> getRight();
    }
    else
    {
      temp = temp -> getLeft();
    }
    if (temp != nullptr)
    {
      return temp;
    }
    else
    {
      return nullptr;
    }
  }
}

bool BST::keyExists(int key)
{
  Node* temp = findkey(key);
  if (temp == nullptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool BST::isEmpty()
{
  if(rootptr == nullptr)
  {
    return true;
  }
  return false;
}

//************************* ADD Functions *******************************//

void BST::AddItem(int key)
{
  if(rootptr == nullptr)
  {
    rootptr = new Node(key);
    cout << rootptr -> getValue() <<" added as root\n";
  }
  else
  {
    balancedAdd(key, rootptr);
  }
}

void BST::balancedAdd(int key, Node* root)
{
  if( root -> getValue() > key)
  {
    if(root -> getLeft() == nullptr)
    {
      Node* temp = new Node(key);
      temp -> setParent(root);
      root -> setLeft(temp);
      cout << temp -> getValue() <<" added to left of " <<temp->getParent() -> getValue() <<"\n";
      temp = nullptr;
      delete temp;
    }
    else
    {
      balancedAdd(key, root -> getLeft());
    }
  }
  else if (root -> getValue() < key)
  {
    if(root -> getRight() == nullptr)
    {
      Node* temp = new Node(key);
      temp -> setParent(root);
      root -> setRight(temp);
      cout << temp -> getValue() <<" added to right of " <<temp->getParent() -> getValue() <<"\n";
      temp = nullptr;
      delete temp;
    }
    else
    {
      balancedAdd(key, root -> getRight());
    }
  }
  else if (root -> getValue() == key)
  {
    if(root -> getRight() == nullptr)
    {
      Node* temp = new Node(key);
      temp -> setParent(root);
      root -> setRight(temp);
      cout << temp -> getValue() <<" added to right of " <<temp->getParent() -> getValue() <<"\n" ;
      temp = nullptr;
      delete temp;
    }
    else
    {
      balancedAdd(key, root -> getRight());
    }
  }
}
//**************Printing options*******************//

void BST::LevelOrder()
{
  if(isEmpty())
  {
    cout <<"Nothing in tree\n";
  }
  else
  {
    int height = getHeight(rootptr);
    bool flag = true;
    for (int i = 1; i <= height; i++)
    {
      SpiralLevelOrder(rootptr, i, flag);
    }
  }
}

/*void BST::LevelOrder(Node *root, int level)
{
  if (root == nullptr)
  {
    return;
  }
  if (level == 1)
  {
    cout << root->getValue() << " ";
  }
  else if (level > 1)
  {
    LevelOrder(root->getLeft(), level - 1);
    LevelOrder(root->getRight(), level - 1);
  }
}
*/
void BST::LeftSideView()
{
  LeftSideView(rootptr, 1);
}

void BST::LeftSideView(Node* root, int level)
{
  if(root == nullptr)
  {
    return;
  }
  if(max_level < level)
  {
    cout << root -> getValue() <<",";
    max_level = level;
  }
  LeftSideView(root -> getLeft(), level + 1);
  LeftSideView(root -> getRight(), level + 1);
}

void BST::RightSideView()
{
  int max_level = 0;
  RightSideView(rootptr, 1, &max_level);
}

void BST::RightSideView(Node* root, int level, int* max_level)
{
  if(root == nullptr)
  {
    return;
  }
  if(*max_level < level)
  {
    cout << root -> getValue() <<",";
    *max_level = level;
  }
  RightSideView(root -> getRight(), level + 1, max_level);
  RightSideView(root -> getLeft(), level + 1, max_level);
}

void BST::SpiralLevelOrder()
{
  if(isEmpty())
  {
    cout <<"Tree is Empty\n";
  }
  int h = getHeight(rootptr);
  int i;
  bool flag = true;
  for(i = 1; i <= h; i++)
  {
    SpiralLevelOrder(rootptr, i,flag);
    flag = !flag;
  }
}
void BST::SpiralLevelOrder(Node* root, int level, bool flag)
{
  if(root == nullptr)
  {
    return;
  }
  if(level == 1)
  {
    cout <<root->getValue() <<" ";
  }
  else if(level > 1)
  {
    if(flag)
    {
      SpiralLevelOrder(root -> getLeft(), level-1, flag);
      SpiralLevelOrder(root -> getRight(), level-1, flag);
    }
    else
    {
      SpiralLevelOrder(root -> getRight(), level-1, flag);
      SpiralLevelOrder(root -> getLeft(), level-1, flag);
    }
  }
}

int BST::inorderSuccessor(int key)
{
  Node *temp = findkey(key);
  if (temp -> getRight() != nullptr)
  {
    Node* n = minValue(temp -> getRight());
    return(n -> getValue());
  }

  Node* p = temp -> getParent();
  while((p != nullptr) && (temp == p -> getRight()))
  {
    temp = p;
    p = p -> getParent();
  }
  return(p-> getValue());
/*
  if (temp->getRight() != nullptr)
  {
    temp = temp->getRight();

    if (temp->getLeft() == nullptr)
    {
      return temp->getValue();
    }
    else
    {
      while (temp->getLeft() != nullptr)
      {
        temp = temp->getLeft();
      }
      return temp->getValue();
    }
  }
  while (temp->getParent() != nullptr && temp->getParent()->getRight() == temp)
  {
    temp = temp->getParent();
  }

  return temp->getParent()->getValue();
  */
}


Node* BST::minValue(Node* root)
{
  Node* temp = root;
  while(temp ->getLeft() != nullptr)
  {
    temp = temp -> getLeft();
  }
  return temp;
}
//*****************Min and Max functions******************

int BST::FindMin()
{
  int min = FindMin(rootptr);
  return min;
}

int BST::FindMin(Node* root)
{
  while( root -> getLeft() != nullptr)
  {
    root = root->getLeft();
  }

  return (root->getValue());

}

int BST::FindMax()
{
  int max = FindMax(rootptr);
  return max;
}

int BST::FindMax(Node* root)
{
  while( root->getRight() != nullptr)
  {
    root = root->getRight();
  }
  return (root->getValue());
}


void BST::deleteMin()
{
  deleteMin(rootptr);
}
void BST::deleteMax()
{
  deleteMax(rootptr);
}
void BST::deleteMin(Node* root)
{
  if(root == nullptr)
  {
    return;
  }
  else
  {
    int min = FindMin();
    DeleteItem(min);
  }
}
void BST::deleteMax(Node* root)
{
  if(root == nullptr)
  {
    return;
  }
  else
  {
    int max = FindMax();
    DeleteItem(max);
  }
}
//***************************Delete********************************//
bool BST::DeleteItem(const int& key)
{
  bool success = false;
  {
    rootptr = removeValue(rootptr, key, success);
    cout <<"Key Deleted \n";
    return true;
  }
  if(success == false)
  {
    cout <<"key not found\n";
    return false;
  }
}

Node* BST::removeValue(Node* root, const int key, bool& success)
{
  if(root == nullptr)
  {
    success = false;
    return nullptr;
  }
  else if(root -> getValue() == key)
  {
    root = removeNode(root);
    success = true;
    return root;
  }
  else if(root -> getValue() > key)
  {
    Node* temp = removeValue(root -> getLeft(), key, success);
    root -> setLeft(temp);
    return root;
  }
  else
  {
    Node* temp = removeValue(root -> getRight(), key, success);
    root -> setRight(temp);
    return root;
  }
}

Node* BST::removeNode(Node* root)
{
  if(root -> isLeaf() == true)
  {
    delete root;
    root = nullptr;
    return root;
  }
  else if ((root -> getLeft() == nullptr && root -> getRight() != nullptr) || root -> getRight() == nullptr && root -> getLeft() != nullptr)
  {
    Node* temp ;
    if(root -> getLeft() != nullptr)
    {
      temp = root -> getLeft();
    }
    else
    {
      temp = root -> getRight();
    }
    delete root;
    root = nullptr;
    return temp;
  }
  else
  {
    int x;
    Node* temp = removeLeftmostNode(root -> getRight(), x);
    root -> setRight(temp);
    root -> setValue(x);
    return root;
  }
}

Node* BST::removeLeftmostNode(Node* root, int& x)
{
  if(root -> getLeft() == nullptr)
  {
    x = root -> getValue();
    Node* temp = removeNode(root);
    return (temp);
  }
  else
  {
    root -> setLeft(removeLeftmostNode(root -> getLeft(), x));
    return root;
  }
}

//***********Experimental Profilling ***************
void BST::ExperimentalProfiling()
{
  // // decleartion
 int m = 100003; // BSTsize
 clock_t buildStart, buildFinish;
 clock_t findMinStart, findMinFinish;
 clock_t findMaxStart, findMaxFinish;
 clock_t deleteMinStart, deleteMinFinish;
 clock_t deleteMaxStart, deleteMaxFinish;

 int index = 1;
 string demension[6][6];
 demension[0][0] = "Input size";
 demension[0][1] = "10,000";
 demension[0][2] = "20,000";
 demension[0][3] = "30,000";
 demension[0][4] = "40,000";
 demension[0][5] = "50,000";
 demension[1][0] = "Build(s)";
 demension[2][0] = "FindMin(s)";
 demension[3][0] = "FindMax(s)";
 demension[4][0] = "DeleteMin(s)";
 demension[5][0] = "DeleteMax(s)";

 for (double i = 0.1; i <= 0.5; i = i + 0.1)
 {
   int inputSize = m * i;
   int num;
   srand(time(NULL));
   int max = 5 * m;
   //step 1
   buildStart = clock();
   for (int i = 0; i < 10000; i++)
   {
     num = rand() % max + 1;
     AddItem(num);
   }

   buildFinish = clock();
   string time = to_string((double)(buildFinish - buildStart) / CLOCKS_PER_SEC);
   cout << "\n";
   demension[1][index] = time;

   //step 2
   findMinStart = clock();
   FindMin();
   findMinFinish = clock();
   string time01 = to_string((double)(findMinFinish - findMinStart) / CLOCKS_PER_SEC);
   demension[2][index] = time01;

   //step 3
   findMaxStart = clock();
   FindMax();
   findMaxFinish = clock();
   string time02 = to_string((double)(findMaxFinish - findMaxStart) / CLOCKS_PER_SEC);
   demension[3][index] = time02;

   //step 4
   deleteMinStart = clock();
   deleteMin();
   deleteMinFinish = clock();
   string time03 = to_string((double)(deleteMinFinish - deleteMinStart) / CLOCKS_PER_SEC);
   demension[4][index] = time03;

   //step 5
   deleteMaxStart = clock();
   deleteMin();
   deleteMaxFinish = clock();
   string time04 = to_string((double)(deleteMaxFinish - deleteMaxStart) / CLOCKS_PER_SEC);
   demension[5][index] = time04;
   index++;
 }

 // Print
 for (int i = 0; i < 6; i++) {
   for (int j = 0; j < 6; j++) {
     cout << demension[i][j] << "    ";
   }
   cout << "\n\n\n";
 }
}

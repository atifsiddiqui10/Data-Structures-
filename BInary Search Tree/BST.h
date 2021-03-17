#ifndef BST_H
#define BST_H
#include "Node.h"
#include <iostream>
using namespace std;

class BST
{
private:
  Node *rootptr;
  int max_level = 0;

public:
  BST(); // done
  ~BST(); // done

  void AddItem(int key);
  int getHeight(Node* subTreeptr);
  Node* findkey(int key);
  bool isEmpty();
  void LevelOrder();
  void SpiralLevelOrder();
  void LeftSideView();
  void RightSideView();
  int FindMin();
  int FindMax();
  bool DeleteItem(const int& key);
  int inorderSuccessor(int key);
  void deleteMin();
  void deleteMax();
  void ExperimentalProfiling();
  void deleteTree(Node* root);
  bool keyExists(int key);
  Node* minValue(Node* root);

protected:

  void balancedAdd(int key, Node* root);
  void LevelOrder(Node* root, int level);
  void SpiralLevelOrder(Node* root, int level, bool FLAG);
  void LeftSideView(Node* root, int level);
  void RightSideView(Node* root, int level, int* max_level);
  int FindMin(Node* root);
  int FindMax(Node* root);
  //Node* DeleteItem(int key, Node* root);
  void deleteMin(Node* root);
  void deleteMax(Node* root);
  Node* removeValue(Node* root, const int key, bool& success);
  Node* removeNode(Node* root);
  Node* removeLeftmostNode(Node* root, int& x);







};
#endif

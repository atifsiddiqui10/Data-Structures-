#include "Executive.h"
using namespace std;

Executive::Executive(string filename)
{
  ifstream dataFile;
  dataFile.open(filename);
  int data;

  if(dataFile.is_open())
  {
    while (dataFile >> data)
    {
      myBST.AddItem(data);
    }
  }
  else
  {
    cout << "File cannot be open\n";
  }
  dataFile.close();
  run();
}

Executive::~Executive()
{

}

void Executive::run()
{
  int choice = 0;

  do
  {
    cout <<"Please choose one of the following commands\n";
    cout <<" 1) AddItem\n 2) DeleteItem\n 3) FindMin\n 4) FindMax\n 5) DeleteMin\n 6) DeleteMax\n 7) InorderSuccessor\n 8) LevelOrder\n 9) SpiralLevelOrder\n 10) LeftSideView\n 11) RightSideView\n 12) ExperimentalProfiling\n 13) Exit\n";
    cout <<"Choice: ";
    cin >> choice;

    if(choice == 1)
    {
      cout <<" Enter key to add: ";
      int key = 0;
      cin >> key;
      myBST.AddItem(key);
    }

    else if(choice == 2)
    {
      cout <<"Enter a key to delete:";
      int key = 0;
      cin >> key;
      myBST.DeleteItem(key);
    }


    else if(choice == 3)
    {
      cout << "Min value: ";
      cout << myBST.FindMin();
      cout <<"\n";
    }

    else if(choice == 4)
    {
      cout <<"Max value: ";
      cout << myBST.FindMax();
      cout <<"\n";
    }

    else if(choice == 5)
    {
      myBST.deleteMin();
    }
    else if(choice == 6)
    {
      myBST.deleteMax();
    }

    else if(choice == 7)
    {
      cout <<"Enter key: ";
      int key = 0;
      cin >> key;
      cout << myBST.inorderSuccessor(key);
      cout <<"\n";

    }

    else if (choice == 8 )
    {
      cout <<"Level Order:\n";
      myBST.LevelOrder();
      cout <<"\n";
    }

    else if (choice == 9)
    {
      cout <<"Spiral Order:";
      myBST.SpiralLevelOrder();
      cout <<"\n";
    }

    else if (choice == 10)
    {
      cout << "Left Side View: ";
      myBST.LeftSideView();
      cout <<"\n";
    }

    else if(choice == 11)
    {
      cout <<"Right Side View: ";
      myBST.RightSideView();
      cout <<"\n";
    }

    else if(choice == 12)
    {
      myBST.ExperimentalProfiling();
    }

  } while(choice != 13);
}

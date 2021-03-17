#include "Executive.h"
#include <iostream>
#include <fstream>
using namespace std;




void Executive::run()
{ int choice= 0;
  do
  {
    cout <<"==============================================\n";
    cout << "Choose one of the following commands \n";
    cout <<"==============================================\n";
    cout << " 1) isEmpty()\n 2) Length()\n 3) Insert()\n 4) Delete()\n 5) Find()\n 6) FindPrev()\n 7) AppendList()\n 8) ForwardTraverse()\n 9) BackwardTraverse()\n 10) Exit()\n";
    cout <<"==============================================\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1 )
    {
      if (List -> isEmpty())
      {
        cout << "List is empty.\n";
      }
      else
      {
        cout << "List is not empty.\n";
      }
      cout << "==============================================\n\n";
    }

    else if (choice == 2)
    {
      cout << "List has a lenght of " << List-> getLength() <<".\n";
      cout << "==============================================\n\n";

    }

    else if (choice == 3)
    {
      int num;
      cout << "Enter a number to insert: ";
      cin >> num;
      List -> insert(num);
      cout << "==============================================\n\n";
    }

    else if (choice == 4)
    {
      int num = 0;
      cout << "Enter a number to delete: ";
      cin >> num;
      List -> remove(num);
      cout << "==============================================\n\n";

    }


    else if (choice == 5)
    {
      int num = 0;
      cout <<"Enter the number to search in the List: " ;
      cin >> num;
      if (List -> find(num))
      {
        cout << "List contains this number\n";
        cout << "==============================================\n\n";
      }
      else
      {
        cout << "Number doesn't existin the list\n";
        cout << "==============================================\n\n";
      }
    }

    else if (choice == 6)
    {
      int num = 0;
      cout << " Enter a number to find the previous off: ";
      cin >> num;
      if (List -> find(num))
      {
        List -> findPrev(num);
        cout << "==============================================\n\n";
      }
    }

    else if (choice == 7)
    {
      int size;
      int num;
      cout << "What is the size of your new List?: ";
      cin >> size;

      for(int i = 0; i < size; i++)
      {
        cout <<" enter num to insert in new list: ";
        cin >> num;
        List2 -> insert(num);
      }



      Node* temp = nullptr;
      for ( temp = List2-> getHead(); temp != nullptr; temp = temp -> getNext())
      {
        if(List -> find(temp -> getItem()))
        {
          cout <<"ERROR! Number exists in list already\n";
          cout << "==============================================\n\n";
          return;
        }
        else
        {
          List -> appendList(temp -> getItem());
        }

      }
      cout <<"List appended\n";
      cout << "==============================================\n\n";
    }

    else if (choice == 8)
    {
      cout << "List: ";
      List -> forwardTraverse();
      cout << "==============================================\n\n";
    }

    else if (choice == 9)
    {
      cout << "List: ";
      List -> backwardTraverse();
      cout << "==============================================\n\n";
    }

    else
    {
      cout <<"ERROR!";
      return;
    }

  }while(choice != 10);

}


Executive::Executive(string filename)
{

  ifstream dataFile;
  dataFile.open(filename);
  if (dataFile.is_open())
  {
    while(dataFile >> data)
    {
      List -> insert(data);
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
  delete List;
  delete List2;
}

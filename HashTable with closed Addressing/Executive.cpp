/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Implementation File for Executive Class
*/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "Executive.h"

using namespace std;

Executive::Executive(string filename)
{

  ifstream dataFile;
  dataFile.open(filename);
  int data;

  if (dataFile.is_open())
  {
    while(dataFile >> data)
    {
      cout <<"Inserting in Double Hash Table: ";
      DH.insert(data);
      cout <<"Inserting in Quadratic Probing table: ";
      QP.insert(data);
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
  //delete DH;
  //delete QP;
}

void Executive::run()
{
  int choice = 0;
  do
  {
    cout <<"==================================================================\n";
    cout <<"Please choice one of the following commands\n";
    cout <<" 1) Insert\n 2) Delete\n 3) Find\n 4) Print\n 5) Exit\n ";
    cout <<"Choice: ";
    cin >> choice;
    cout <<"==================================================================\n";

    if(choice == 1 )
    {
      int value;
      cout <<"Enter Value to insert in table: ";
      cin >> value;
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      cout << "Double Hashing:\n";
      DH.insert(value);
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      cout << "Quadratic Probing:\n";
      QP.insert(value);
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    }

    else if (choice == 2)
    {
      int value;
      cout <<"Enter the value to remove from the table: ";
      cin >> value;
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

      cout <<"Double Hashing:\n";
      DH.remove(value);
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

      cout <<"Quadratic Probing:\n";
      QP.remove(value);
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    }

    else if (choice == 3)
    {
      int value;
      cout <<"Enter the value to find: ";
      cin >> value;
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

      cout <<"Double Hashing:\n";
      if(DH.find(value))
      {
        cout <<"Value Exists\n";
        cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      }
      else
      {
        cout <<"Value doesn't exists\n";
        cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      }

      cout <<"Quadratic Probing:\n";
      if(QP.find(value))
      {
        cout <<"Value Exists\n";
        cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
      }
      else
      {
        cout <<"Value doesn't exists\n";
      }

    }

    else if (choice == 4)
    {
      cout <<"Double Hashing:\n";
      DH.print();
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

      cout <<"Quadratic Probing:\n";
      QP.print();
      cout <<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    }







  }while(choice != 5);
}

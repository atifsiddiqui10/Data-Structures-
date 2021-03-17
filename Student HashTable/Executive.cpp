#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "Executive.h"

using namespace std;
Executive::Executive(string filename)
{
  ifstream inFile(filename);

  if(!inFile.is_open())
  {
    cout <<"ERROR!";
  }
  else
  {
    string line, name, dummy;
    int id;
    cout <<"==============================================\n";
    while(getline(inFile, line))
    {
      istringstream iss1(line);

      iss1 >> id;
      cout << id;
      iss1 >> dummy;
      cout << dummy;
      iss1 >> name;
      cout << name <<"\n";
      HashList -> Add(id,name);

    }
    inFile.close();
    cout <<"==============================================\n";
    run();
  }
}

Executive::~Executive()
{
  delete HashList;
}

void Executive::run()
{
  int choice = 0;
  do
  {
    cout <<"==============================================\n";
    cout <<"Choose one of the following commands \n";
    cout << " 1) AddStudent\n 2) RemoveStudent\n 3) PrintStudentList\n 4) FindStudent\n 5) Exit\n";
    cout <<"==============================================\n";
    cout << "Choice: ";
    cin >> choice;

    if(choice == 1)
    {
      int id;
      string name;
      cout <<"==============================================\n";
      cout <<"Insert a new student\n";
      cout <<"Student ID(5 digit) = ";
      cin >> id;
      int length = to_string(id).length();
      if(length != 5)
      {
        cout <<"ID can only be 5\n";
        return;
      }

      cout <<"Student name(lower case) = ";
      cin >> name;
      cout <<"==============================================\n";
      HashList -> Add(id, name);
    }


    else if(choice == 2)
    {
      int id;
      string name;
      cout <<"==============================================\n";
      cout <<"Remove a student\n";
      cout <<"Student ID(5 digit) = ";
      cin >> id;
      cout <<"Student name(lower case) = ";
      cin >> name;
      cout <<"==============================================\n";
      HashList -> Remove(id, name);
    }

    else if(choice == 3)
    {
      HashList -> Print();
    }

    else if(choice == 4)
    {
      int id;
      string name;
      cout <<"==============================================\n";
      cout <<" Find a Student\n";
      cout <<" Enter student ID: ";
      cin >> id;
      cout <<"Student name(lower case) = ";
      cin >> name;
      cout <<"==============================================\n";
      HashList -> Find(id,name);

    }
  }while(choice != 5);

}

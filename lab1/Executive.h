/**
  @Douly Linked List
  @File - Executive.h
  @Author M. Atif Siddiqui

*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "LinkedList.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

/**
  Executive class for Doubly Linked List
*/
class Executive
{
public:
  /**
    Executive constructor
    @param string filename
    @return none
  */
  Executive(string filename);

  /**
    Executive destructor
    @param none
    @return none
  */
  ~Executive();

  /**
    function to show the handle the menu
    @param none
    @return none
  */
  void run();

private:
  int data;
  string m_filename;
  ifstream inFile;
  LinkedList *List = new LinkedList();
  LinkedList *List2 = new LinkedList();
};
#endif

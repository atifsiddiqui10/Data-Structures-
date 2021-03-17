/**
  @Douly Linked List
  @File - LinkedList.h
  @Author M. Atif Siddiqui

*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <stdexcept>
using namespace std;

/**
	LinkedList class for Doubly Linked List
*/

class LinkedList
{
private:
  Node* m_head;
  Node* m_tail;
  int itemCount;
  int m_length;
  bool m_isEmpty;

public:
  /**
    LinkedList constructor
    @param none
    @return none
  */
  LinkedList();

  /**
    LinkedList destructor
    @param none
    @return none
  */
  ~ LinkedList();

  /**
    Function to find if the List is empty
    @param none
    @return bool: true if empty; false if not empty
  */
  bool isEmpty();

  /**
    Function to get the lenght of the List
    @param none
    @return interger value
  */
  int getLength();

  /**
    Function to insert a node to an exsiting doubly linked list
    @param interger value
    @return none
  */
  void insert(int value);

  /**
    Function to delete a node to an exsiting doubly linked list
    @param interger value
    @return none
  */
  void remove(int value);

  /**
    Function to find a node of a given value in an exsiting linked list
    @param interger value
    @return bool: if value found return true; if not found return false
  */
  bool find (int value);

  /**
    Function to find a previous node of a node
    @param interger value
    @return none
  */
  void findPrev(int value);

  /**
    Function to append a List to an exsiting list
    @param interger value
    @return none
  */
  void appendList(int value);

  /**
    Function to traverse the Linked List from head to tail
    @param none
    @return none
  */
  void forwardTraverse();

  /**
    Function to traverse the Linked List from tail to head
    @param none
    @return none
  */
  void backwardTraverse();

  Node* getHead();
  Node* getTail();

  void setHead(Node* nodePtr);
  void setTail(Node* nodePtr);
};
#endif

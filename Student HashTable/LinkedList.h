#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <stdexcept>
using namespace std;

class LinkedList
{
private:
  Node* m_head;
  int itemCount;
  int m_length;
  bool m_isEmpty;

public:
  LinkedList();
  ~LinkedList();
  bool isEmpty();
  int getLength();
  void insert(int id, string name);
  void remove(int id, string name);
  bool find(int id, string name);
  void print();
  Node* getHead();
  void setHead(Node* nodePtr);

};
#endif

#ifndef NODE_H
#define NODE_H
//#include <iostream>
using namespace std;

class Node
{
private:
  Node* m_left;
  Node* m_right;
  Node* m_parent;
  int m_value;

public:
  Node(int key);
  ~Node();

  Node* getLeft();
  void setLeft(Node* leftptr);
  Node* getRight();
  void setRight(Node* rightptr);
  Node* getParent();
  void setParent(Node* parentptr);

  int getValue();
  void setValue(int x);
  bool isLeaf();
  bool isEmpty();


};
#endif

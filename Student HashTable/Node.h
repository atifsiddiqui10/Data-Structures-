#ifndef NODE_H
#define NODE_H
#include <stdexcept>
#include <string>
using namespace std;

class Node
{
private:
  int m_id;
  string m_Fname;
  Node* next;

public:
   Node(int id, string name);
   int getID() const;
   void setID(int id);
   string getFname() const;
   void setFname(string name);
   Node* getNext() const;
   void setNext(Node* nodePtr);


};

#endif

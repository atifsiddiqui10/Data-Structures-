#include "Node.h"


Node::Node(int id, string name)
{
  id = m_id;
  name = m_Fname;
  next = nullptr;
}


int Node::getID() const
{
  return m_id;
}

void Node::setID(int id)
{
  m_id = id;
}

string Node::getFname() const
{
  return m_Fname;
}

void Node::setFname(string name)
{
  m_Fname = name;
}

Node* Node::getNext() const
{
  return next;
}

void Node::setNext(Node* nodePtr)
{
  next = nodePtr;
}

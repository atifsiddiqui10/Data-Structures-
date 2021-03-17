#include "Node.h"
Node::Node(int key)
{
  m_left = nullptr;
  m_right = nullptr;
  m_parent = nullptr;
  m_value = key;
}

Node::~Node()
{

}

Node* Node::getLeft()
{
  return m_left;
}

void Node::setLeft(Node* leftptr)
{
  m_left = leftptr;
}

Node* Node::getRight()
{
  return m_right;
}

void Node::setRight(Node* rightptr)
{
  m_right = rightptr;
}

Node* Node::getParent()
{
  return m_parent;
}

void Node::setParent(Node* parentptr)
{
  m_parent = parentptr;
}

int Node::getValue()
{
  return m_value;
}

void Node::setValue(int x)
{
  m_value = x;
}

bool Node::isLeaf()
{
  if(m_left == nullptr && m_right == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Node::isEmpty()
{
  if(m_parent == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

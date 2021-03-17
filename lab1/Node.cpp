/**
  @Douly Linked List
  @File - Node.cpp
  @Author M. Atif Siddiqui

*/

#include "Node.h"
Node::Node(int anItem)
{
  item = anItem;
  next = nullptr;
  prev = nullptr;
}

int Node::getItem() const
{
  return item;
}

void Node::setItem(int newItem)
{
  item = newItem;
}

Node* Node::getNext() const
{
  return next;
}

void Node::setNext(Node* nodePtr)
{
  next = nodePtr;
}

Node* Node::getPrev() const
{
  return prev;
}

void Node::setPrev(Node* nodePtr)
{
  prev = nodePtr;
}

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
  m_head = nullptr;
  m_isEmpty = true;
  m_length = 0;
}

LinkedList::~LinkedList()
{
  Node* temp = m_head;
  while(temp != nullptr)
  {
    Node* temp1 = temp;
    temp = temp -> getNext();
    delete temp1;
  }
}

bool LinkedList::isEmpty()
{
  if(m_length == 0)
  {
    return true;
  }
    return false;
}

int LinkedList::getLength()
{
  return m_length;
}

void LinkedList::insert(int id, string name)
{

  if(find (id, name))
  {
    cout << "Value already exists in the list.\n";
    return;
  }

 if (m_length == 0)
  {
    Node* temp = new Node(id, name);
    temp -> setID(id);
    temp -> setFname(name);
    m_head = temp;
    m_head -> setNext(nullptr);
    cout <<"Student Added\n";

  }

  else if(m_length == 1 )
  {
    Node* temp = new Node(id, name);
    temp -> setID(id);
    temp -> setFname(name);
    m_head ->setNext(temp);
    temp -> setNext(nullptr);
    cout <<"Student Added\n";
  }

  else if (m_length > 1)
  {
    Node* newNode = new Node(id, name);
    newNode -> setID(id);
    newNode -> setFname(name);
    Node* temp0 = m_head;
    for (int i = 0; i < m_length -1; i ++)
    {
      temp0 = temp0 -> getNext();
    }
    temp0 -> setNext(newNode);
    newNode -> setNext(nullptr);
    cout <<"Student Added\n";
  }

  m_isEmpty = false;
  m_length ++;

}

/*
void LinkedList::remove(int id, string name)
{
  if(!find(id,name))
  {
    cout <<"Student doesnt exist";
    return;
  }

  Node* temp = m_head;
  while(temp != nullptr)
  {
    if(temp -> getID() == id)
    {


          if ( temp == m_head)
          {
            m_head = m_head -> getNext();
            delete temp;
            m_length --;
            return;
          }

    }
    else if (temp -> getNext()-> getID() == id)
    {
      Node* temp0 = temp -> getNext();
      Node* temp1 = temp -> getNext()-> getNext();
      temp -> setNext(temp1);
      delete temp0;
      m_length --;
      return;
    }
    else
    {
      temp = temp -> getNext();
    }
  }
}
*/
void LinkedList::remove(int id, string name)
{
  if(!find(id,name))
  {
    cout <<"Student doesnt exist";
    return;
  }

  Node* temp = m_head;

  for(temp = m_head; temp != nullptr; temp = temp -> getNext())
  {
    if(temp == m_head && temp -> getID() == id)
    {
      m_head = m_head -> getNext();
      delete temp;
      m_length --;
      return;
    }

    else if(temp -> getNext() -> getID() == id)
    {
      Node* temp0 = temp -> getNext();
      Node* temp1 = temp -> getNext()-> getNext();
      temp -> setNext(temp1);
      delete temp0;
      m_length --;
      return;
    }
  }
}



bool LinkedList::find(int id, string name)
{
  Node* temp = m_head;
  while(temp != nullptr)
  {
    if(temp -> getID() == id && temp -> getFname() == name)
    {
      return true;
    }
    else
    {
      temp = temp -> getNext();
    }
  }
  return false;
}

void LinkedList::print()
{

  Node* temp= m_head;
  while(temp != nullptr)
  {

    cout << temp->getID()  << " " << temp->getFname() << " -> ";

    temp = temp -> getNext();
  }
  cout << "\n";

}

Node* LinkedList::getHead()
{
  return m_head;
}

void LinkedList::setHead(Node* nodePtr)
{
  m_head = nodePtr;
}

/**
  @Douly Linked List
  @File - LinkedList.cpp
  @Author M. Atif Siddiqui

*/


#include <iostream>
#include "LinkedList.h"


LinkedList::LinkedList()
{
  m_head = nullptr;
  m_tail = nullptr;
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

void LinkedList::insert(int value)
{
  if (find(value))
  {
    cout << "Value already exists in the list.\n";
    return;
  }

  if (m_length == 0)
  {
    Node* temp = new Node(value);
    m_head = temp;
    m_tail = m_head;
    m_head -> setNext(nullptr);
    m_tail -> setPrev(nullptr);

  }
  else if (m_length == 1)
  {
    Node *temp = new Node(value);
    m_head -> setNext(temp);
    temp -> setPrev(m_head);
    temp -> setNext(nullptr);
    m_tail = temp;

  }
  else if (m_length > 1)
  {
    Node* temp = new Node(value);
    m_tail -> setNext(temp);
    temp -> setPrev(m_tail);
    temp -> setNext(nullptr);
    m_tail = temp;
  }
  m_isEmpty = false;
  //cout <<value <<" inserted to list.\n";
  m_length++;

}

void LinkedList::remove(int value)
{
  if (!find(value))
  {
    cout << "Value doesn't exist.\n";
    return;
  }

  Node* temp = m_head;
  while( temp != nullptr)
  {
    if (temp-> getItem() == value)
    {
      if (temp == m_head)
      {
        m_head = m_head -> getNext();
        m_head -> setPrev(nullptr);
        delete temp;
        m_length = m_length - 1 ;
        cout << " Deleted\n";
        return;
      }
      else if ( temp == m_tail)
      {
        m_tail = m_tail -> getPrev();
        m_tail -> setNext(nullptr);
        delete temp;
        m_length = m_length - 1 ;
        cout << " Deleted\n";
        return;
      }
      else
      {
        temp-> getPrev()-> setNext(temp -> getNext());
        temp -> getNext()-> setPrev(temp -> getPrev());
        delete temp;
        m_length = m_length - 1 ;
        cout << " Deleted\n";
        return;
      }

    }
    else
      temp = temp -> getNext();
  }


}

bool LinkedList::find(int value)
{
  Node* temp = m_head;
  while(temp != nullptr)
  {
    if (temp -> getItem() == value)
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

void LinkedList::findPrev(int value)
{

  if (find(value))
  {
    Node* temp = m_head;
    while(temp != nullptr)
    {
      if (temp -> getItem() == value)
      {
        if (temp == m_head)
        {
          cout << "The value is at the head of the list.\n ";
        }
        else
        {
          cout << temp -> getPrev() -> getItem() << " is the previous of " << value <<endl;
        }
        break;
      }
      else
      {
        temp = temp -> getNext();
      }

    }
  }
  else
  {
    cout << value <<"doesn't exist.\n";
  }
}

void LinkedList::appendList(int value)
{
  insert(value);
}


void LinkedList::forwardTraverse()
{
  Node* temp= m_head;
  while(temp != nullptr)
  {

    cout << temp-> getItem() << " ";

    temp = temp -> getNext();
  }
  cout << "\n";

}

void LinkedList::backwardTraverse()
{
  Node* temp = nullptr;
  temp = m_tail;
  while(temp != nullptr)
  {
    cout << temp -> getItem() << " ";
    temp = temp -> getPrev();
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

Node* LinkedList::getTail()
{
  return m_tail;
}

void LinkedList::setTail(Node* nodePtr)
{
  m_tail = nodePtr;
}

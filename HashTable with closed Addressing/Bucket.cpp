/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Implementation File for Bucket Class
*/

#include "Bucket.h"

Bucket::Bucket()
{
  m_value = 0;
  m_isEmpty = true;
  m_flag = false;
}

Bucket::~Bucket()
{

}

int Bucket::getValue()
{
  return m_value;
}

void Bucket::setValue(int value)
{
  m_value = value;
}

bool Bucket::get_isEmpty()
{
  return m_isEmpty;
}

void Bucket::set_isEmpty(bool isEmpty)
{
  m_isEmpty = isEmpty;
}

bool Bucket::get_flag()
{
  return m_flag;
}

void Bucket::set_flag(bool flag)
{
  m_flag = flag;
}

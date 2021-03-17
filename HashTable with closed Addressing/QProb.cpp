/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Implementation File for Quadratic Probing Hash Class
*/
#include "QProb.h"

QProb::QProb()
{
  m_bucketSize = 0;
  m_mod = 11;
  QPtable = new Bucket[m_mod];
}

QProb::~QProb()
{
  delete[] QPtable;
}

int QProb:: HashFunction(int value, int mod)
{
  m_key = value % mod;
  return m_key;
}

bool QProb::isPrime(int x)
{
  for(int i = 2; i <= x/2 ; i++)
  {
    if(x % i == 0)
    {
      return false;
    }
  }

  return true;
}

int QProb::findNextPrime(int x)
{
  while(!isPrime(x))
  {
    x++;
  }

  return x;
}

void QProb::Rehash()
{
  int second_prime = findNextPrime(m_mod*2);
  Bucket* temp = new Bucket[second_prime];

  for(int i = 0; i < m_mod; i ++)
  {
    if(!(QPtable[i].get_isEmpty()))
    {
      int value = QPtable[i].getValue();
      int x = HashFunction(value, second_prime);
      int y = HashFunction(value, second_prime);

      for (int j =0; j <second_prime; j++)
      {
        if(!(temp[y].get_isEmpty()))
        {
          y = (x + (j*j))% second_prime;
        }
        else
        {
          temp[y].setValue(value);
          temp[y].set_isEmpty(false);
          break;
        }
      }
    }
  }
  delete[] QPtable;
  m_mod = second_prime;
  QPtable = temp;
}


void QProb::insert(int value)
{
    if(find(value))
    {
      cout <<"Value already exists\n";
      return;
    }

    if(m_bucketSize > 0.5 * m_mod)
    {
      cout <<"Rehashed!!\n";
      Rehash();
    }
    int x = HashFunction(value, m_mod);
    int y = HashFunction(value, m_mod);

    for(int i = 0; i < m_mod; i ++)
    {
      if(!(QPtable[y].get_isEmpty()))
      {

        y = (x + (i*i))% m_mod;
      }
      else
      {
        QPtable[y].setValue(value);
        QPtable[y].set_isEmpty(false);
        m_bucketSize++;
        cout <<" Value added at bucket " << y <<".\n";
        return;

      }
    }
    cout <<"Error value not added\n";
    return;


}

void QProb::remove(int value)
{
  if(!find(value))
  {
    cout <<"Value doesn't exist\n";
  }
  int x = HashFunction(value, m_mod);
  int y = HashFunction(value, m_mod);
  for (int i =0; i <m_mod; i++)
  {
    if(QPtable[y].get_isEmpty()&& QPtable[y].get_flag())
    {
      cout <<"Error! can't add value\n";
      return;
    }
    else if(QPtable[y].getValue() == value)
    {
      QPtable[y].set_isEmpty(true);
      QPtable[y].set_flag(false);
      m_bucketSize --;
      cout <<"Value removed from bucket " << y <<".\n";
      return;
    }
    y = (x + (i*i))% m_mod;
  }
  return;

}

bool QProb::find(int value)
{
  int x = HashFunction(value, m_mod);
  int y = HashFunction(value, m_mod);
  for (int i =0; i <m_mod; i++)
  {
    if(QPtable[y].get_isEmpty() && QPtable[y].get_flag())
    {
      return false;
    }
    else if(QPtable[y].getValue()==value)
    {
      return true;
    }
    y = (x + (i*i))% m_mod;
  }
  return false;
}

void QProb::print()
{
  for(int i =0 ; i<m_mod; i++)
  {
    if(QPtable[i].get_isEmpty() != true)
    {
      cout << i << ": " <<QPtable[i].getValue()<<endl;
    }
    else
    {
        cout<< i << ": \n";
    }
  }
}

/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Implementation File for Double Hashing Class
*/

#include "DHash.h"

DHash::DHash()
{
  m_bucketSize = 0;
  m_mod = 11;
  m_k = 5;
  DHtable = new Bucket[m_mod];
}

DHash::~DHash()
{
  delete[] DHtable;
}

int DHash:: HashFunction(int value, int mod)
{
  m_key = value % mod;
  return m_key;
}

bool DHash::isPrime(int x)
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

int DHash::findNextPrime(int x)
{
  while(!isPrime(x))
  {
    x++;
  }

  return x;
}

void DHash::Rehash()
{
  int second_prime = findNextPrime(m_mod*2);
  Bucket* temp = new Bucket[second_prime];

  for(int i = 0; i < m_mod; i ++)
  {
    if(!(DHtable[i].get_isEmpty()))
    {
      int value = DHtable[i].getValue();
      int x = HashFunction(value, second_prime);
      int y = HashFunction(value, second_prime);

      for (int j =0; j <second_prime; j++)
      {
        if(!(temp[y].get_isEmpty()))
        {
          y = (x + (j*(m_k-(value%m_k))))% second_prime;
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
  delete[] DHtable;
  m_mod = second_prime;
  DHtable = temp;
}

void DHash::insert(int value)
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
      if(!(DHtable[y].get_isEmpty()))
      {
        /*
        if(DHtable[y].getValue() == value)
        {
          return false;
        }
        */
          y = (x + (i * (m_k - (value%m_k)))) % m_mod;
      }
      else
      {
        DHtable[y].setValue(value);
        DHtable[y].set_isEmpty(false);
        m_bucketSize++;
        cout <<" Value added at bucket " << y <<".\n";
        return;
        //return true;
      }
    }
    cout <<"Error value not added\n";
    return;
    //return false;

}

void DHash::remove(int value)
{
  if(!find(value))
  {
    cout <<"Value doesn't exist\n";
  }
  int x = HashFunction(value, m_mod);
  int y = HashFunction(value, m_mod);
  for (int i =0; i <m_mod; i++)
  {
    if(DHtable[y].get_isEmpty()&& DHtable[y].get_flag())
    {
      cout <<"Error! can't add value\n";
      return;
      //return false;
    }
    else if(DHtable[y].getValue() == value)
    {
      DHtable[y].set_isEmpty(true);
      DHtable[y].set_flag(false);
      m_bucketSize --;
      cout <<"Value removed from bucket " << y <<".\n";
      return;
      //return true;
    }
    y = (x + (i*(m_k-(value % m_k))))% m_mod;
  }
  //cout << "Error can't add value\n";
  return;
  //return false;
}

bool DHash::find(int value)
{
  int x = HashFunction(value, m_mod);
  int y = HashFunction(value, m_mod);
  for (int i =0; i <m_mod; i++)
  {
    if(DHtable[y].get_isEmpty() && DHtable[y].get_flag())
    {
      return false;
    }
    else if(DHtable[y].getValue()==value)
    {
      return true;
    }
    y = (x + (i*(m_k-(value%m_k))))% m_mod;
  }
  return false;
}

void DHash::print()
{
  for(int i =0 ; i<m_mod; i++)
  {
    if(DHtable[i].get_isEmpty() != true)
    {
      cout << i << ": " <<DHtable[i].getValue()<<endl;
    }
    else
    {
        cout<< i << ": \n";
    }
  }
}

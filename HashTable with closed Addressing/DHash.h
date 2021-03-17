/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Header File for Double Hashing Class
*/
#ifndef DHASH_H
#define DHASH_H
#include "Bucket.h"
#include <iostream>
using namespace std;

class DHash
{
private:
  Bucket* DHtable;
  int m_mod;
  int m_bucketSize;
  int m_k;
  int m_key;

public:
  /*
    Constructor for Double Hashing  Class
    @param None
    @return None
  */
  DHash();
  /*
    Destructor for Double Hashing Class
    @param None
    @return None
  */
  ~DHash();
  /*
    Function to insert in the Double Hash Table
    @param interger value
    @return None
  */
  void insert(int value);
  /*
    Function to remove from the Double Hash Table
    @param interger value
    @return None
  */
  void remove(int value);
  /*
    Function to find a value in the Double Hash Table
    @param interger value
    @return Boolean, return true if found, false if not found
  */
  bool find(int value);
  /*
    Function to find the Hash Fuction for the Double Hash Table
    @param interger value and integer mod
    @return integer Hash Fuction
  */
  int HashFunction(int value, int mod);
  /*
    Function to Rehash the Double Hash Table. If Load Factor is greater than 0.5 rehash
    @param None
    @return None
  */
  void Rehash();
  /*
    Function to find if the int is a prime
    @param interger value
    @return Boolean, true if int is a prime, false if int is not a prime
  */
  bool isPrime(int x);
  /*
    Function to find the next closest prime number to int
    @param interger value
    @return next closest prime
  */
  int findNextPrime(int x);
  /*
    Function to print the hash table
    @param None
    @return None
  */
  void print();

};
#endif

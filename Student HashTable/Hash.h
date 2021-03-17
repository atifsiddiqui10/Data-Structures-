#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Node.h"


using namespace std;

class Hash
{
private:
  LinkedList **HashLink;
  int m_bucketSize = 11;
  int m_items;
  int m_index;

public:
  Hash(int size = 11);
  ~Hash();
  void Add(int id, string name);
  void Remove(int id, string name);
  void Print();
  void Find(int id, string name);
  int HashFunction(string name, int bucketSize );
  bool FindStudent(int id, string name);

};
#endif

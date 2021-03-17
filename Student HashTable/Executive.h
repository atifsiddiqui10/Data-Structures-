
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Node.h"
#include "LinkedList.h"
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

class Executive
{
public:
  Executive(string filename);
  ~Executive();
  void run();
private:
  int fname;
  int size = 11;
  int id;
  ifstream inFile;
  Hash *HashList = new Hash(size);

};
#endif

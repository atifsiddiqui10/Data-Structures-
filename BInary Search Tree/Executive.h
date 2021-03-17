#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "BST.h"
#include "Node.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>


class Executive
{
public:
  Executive(string filename);
  ~Executive();
  void run();
private:
  ifstream inFile;
  BST myBST; 
};
#endif

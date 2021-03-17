/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Header File for Executive Class
*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "DHash.h"
#include "QProb.h"
#include "Bucket.h"

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
  DHash DH;
  QProb QP;
  int input ;



};
#endif

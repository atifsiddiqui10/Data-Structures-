/*
  M.Atif Siddiqui
  EECS 560 Lab 3
  Header File for Bucket Class
*/
#ifndef BUCKET_H
#define BUCKET_H

class Bucket
{
private:
  int m_value;
  bool m_isEmpty;
  bool m_flag;
public:
  /*
    Bucket constructor
  */
  Bucket();
  /*
    Bucket destructor
  */
  ~Bucket();

  /*
    Function to get the value of the bucket
    @param None
    @return integer value
  */
  int getValue();
  /*
    Function to set the value of the bucket
    @param integer value
    @return none
  */
  void setValue(int value);

  /*
    Function to find if the bucket is empty
    @param None
    @return bool; true if bucket is empty, false if bucket is not empty
  */
  bool get_isEmpty();
  /*
    Function to set the value of bucket as empty
    @param bool isEmpty
    @return none
  */
  void set_isEmpty(bool isEmpty);

  /*
    Function to see if the bucket has been previously set
    @param None
    @return boolean
  */
  bool get_flag();

  /*
    Function to set the flag
    @param bool flag
    @return none
  */
  void set_flag(bool flag);

};
#endif

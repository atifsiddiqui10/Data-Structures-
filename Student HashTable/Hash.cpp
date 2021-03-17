#include "Hash.h"
#include "LinkedList.h"

Hash::Hash (int size)
{
  m_bucketSize = size;
  HashLink = new LinkedList*[size];
  for (int i =0; i< size; i++)
  {
    HashLink[i] = new LinkedList();
  }

}

Hash::~Hash()
{
  for(int i =0; i< 11; i++)
  {
    delete(HashLink[i]);
  }
  delete HashLink;
}

int Hash::HashFunction(string name, int bucketSize)
{
  int sum = 0;
  for (int i =0; i < name.size(); i++)
  {
    sum = sum + (int)name[i];
  }

  int index = sum % bucketSize;
  return index;

}

void Hash::Add(int id, string name)
{
  if(FindStudent(id, name))
  {
      cout << "Cannot add, ID or name already exists\n";
      return;
  }

  int key = HashFunction(name, m_bucketSize);
  HashLink[key] -> insert(id, name);
  cout << id <<":" << name <<" added to key " <<key <<"\n";

}


void Hash::Remove(int id, string name)
{

  if(FindStudent(id, name))
  {
    
    int key = HashFunction(name, m_bucketSize);

    HashLink[key] -> remove(id, name);
    cout <<id <<":" <<name << " deleted from key" << key << "\n";
  }
  else
  {
    cout <<"Student not found \n";
    return;

  }


}


void Hash::Find(int id, string name)
{
  if(!FindStudent(id, name))
  {
      cout << "No student with this ID and name exist.\n";
      return;
  }
  else
  {
    int key = HashFunction(name, m_bucketSize);
    cout <<" Student exists at key " << key <<"\n";
  }


}

void Hash::Print()
{
  for(int i= 0; i < 11; i++)
  {
    cout << i <<":->";
    HashLink[i] -> print();
    cout << "\n";
  }

}

bool Hash::FindStudent(int id, string name)
{

  for (int i = 0; i < 11; i++)
  {
    if(HashLink[i] -> find(id, name))
    {
      return true;
    }
  }
    return false;
}

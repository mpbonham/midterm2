#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include "MyHashTable.h"

using namespace std;

// Default constructor. Do not modiify.
MyHashTable::MyHashTable() {
  for (size_t i = 0; i < CAPACITY; i++) {
    table[i] = new vector<pair<string, int>>;
  }
}

// Simple hash function. Do not modify.
size_t MyHashTable::hash(string name) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < name.size(); i++) {
		accumulator += name.at(i);
	}
	return accumulator % CAPACITY;
}

void MyHashTable::insertItem(string name, int perm) {
		
	size_t index = hash(name);
	this->table[index]->push_back(make_pair(name,perm));
	// inserts a string and an int into the table vector at location index
}

void MyHashTable::deleteItem(string name) {
  
  size_t index = hash(name); // finds the index of the string that needs to be deleted
  vector<pair<string,int>>:: iterator iter; // vector pair iterator

  for(iter = this->table[index]->begin(); iter != this->table[index]->end(); iter++)
  {
    if(iter->first == name)
    {
      break;
    }
  }
 
  if(iter != this->table[index]->end())
  {
      this->table[index]->erase(iter); // erases the string that needs to be deleted
  }

}

string MyHashTable::toString() const { 

  
  string result = "";
  stringstream ss; // creates a stringstream to hold the hashtable information
  size_t vol = this->CAPACITY;

  vector<pair<string,int>>:: iterator iter; //vector pair iterator

  for (size_t i = 0; i < vol; i++)
  {
      ss << i << ":[" ;

      for(iter = this->table[i]->begin(); iter != this->table[i]->end(); iter++)
      {  
	      ss << "(" << iter->first << "," << iter->second << ")";
      }
    ss << "]\n";
  }

  result = ss.str(); // string result holds the stringstream ss information
  return result;


}


MyHashTable::MyHashTable(const MyHashTable &orig) {

  size_t vol = this->CAPACITY;
  for (size_t i = 0; i < vol; i++) {
    table[i] = new vector<pair<string, int>> ;
   }
  // this for loop creates the vector pairs needed to copy into
  

  vector<pair<string,int>>:: iterator iter; // vector pair iterator

  for (size_t i = 0; i < vol; i++) //iterates enough times to fill the new MyHashTable
  {
    for(iter = orig.table[i]->begin(); iter != orig.table[i]->end(); iter++)
    {
            this->insertItem(iter->first, iter->second); 
	    // insertItem is used to insert the original MyHashtable
	    // strings and names into a new MyHashTable
    }

  }
}

MyHashTable::~MyHashTable() {
  size_t vol = this->CAPACITY;

  for (size_t i = 0; i < vol; i++)
  {
      if(this->table[i])
      {
        this->table[i]->clear(); // uses the clear member function to remove all elements of table[i]
        delete this->table[i]; // deletes the pointer to the table
      }
  }
  
}

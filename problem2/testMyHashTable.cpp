#include "MyHashTable.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;
int main() {

  // A sample test.
  MyHashTable ht;
  ht.insertItem("Peter Parker", 27437);
  ht.insertItem("Tony Stark", 49872);
  ht.insertItem("Bruce Banner", 39857);
  ht.insertItem("Steven Rogers", 12984);
  string expected = "0:[(Tony Stark,49872)]\n1:[]\n2:[(Peter Parker,27437)(Bruce Banner,39857)(Steven Rogers,12984)]\n3:[]\n4:[]\n";
  ASSERT_EQUALS(expected, ht.toString());
  // Write your own tests below.

  MyHashTable pl;
  pl.insertItem("Super Man", 55783);
  pl.insertItem("Wonder Women", 33465);
  pl.insertItem("Green Lantern", 94375);
  pl.insertItem("James Stienfield", 28456);
  pl.deleteItem("Super Man");
  pl.deleteItem("Wonder Women");
  pl.deleteItem("DOESNT EXIST"); // to test if the key does not exist
  pl.deleteItem("James Stienfield");
  pl.insertItem("Aqua Manoplert", 45342);
  string expected2 = "0:[(Aqua Manoplert,45342)]\n1:[]\n2:[]\n3:[(Green Lantern,94375)]\n4:[]\n";

  ASSERT_EQUALS(expected2, pl.toString());

  MyHashTable xp(ht); // testing the copy constructor
  ASSERT_EQUALS(expected, xp.toString());

  MyHashTable yx = pl; // again testing the copy constructor
  ASSERT_EQUALS(expected2, yx.toString());

  ASSERT_EQUALS(expected2, pl.toString());

  MyHashTable ep;
  ep.insertItem("Beanie boy", 48265);
  ep.insertItem("Evan typhoon", 39645);
  ep.insertItem("Helen Hunt",55284 );
  ep.insertItem("Bertha james",92771);
  ep.insertItem("paul giamatti",30389);

  string expected3 = "0:[]\n1:[(Evan typhoon,39645)]\n2:[(Beanie boy,48265)]\n3:[(Bertha james,92771)]\n4:[(Helen Hunt,55284)(paul giamatti,30389)]\n";

  ASSERT_EQUALS(expected3, ep.toString());
  ep.deleteItem("Evan typhoon");
  ep.deleteItem("Helen Hunt");

  string expected4 = "0:[]\n1:[]\n2:[(Beanie boy,48265)]\n3:[(Bertha james,92771)]\n4:[(paul giamatti,30389)]\n";
  ASSERT_EQUALS(expected4, ep.toString());

  MyHashTable empty;
  string expected5 = "0:[]\n1:[]\n2:[]\n3:[]\n4:[]\n";
  ASSERT_EQUALS(expected5 ,empty.toString());



  return 0;
}

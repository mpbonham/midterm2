#include "MySorting.h"
#include "tddFuncs.h"
using namespace std;

int main() {


  // Test case #1
  string a[] {"If", "music", "be", "the", "food", "of", "love", "play", "on"};
  size_t a_size = 9;
  string expected_1 = "BE,IF,OF,ON,THE,FOOD,LOVE,PLAY,MUSIC";
 ASSERT_EQUALS(expected_1, customSort(a, a_size));
	customSort(a, a_size);
  // Test case #2
  string b[] {"Shall", "I" ,"compare", "thee", "to" ,"a" ,"summers", "day"};
  size_t b_size = 8;
  string expected_2 = "A,I,TO,DAY,THEE,SHALL,COMPARE,SUMMERS";
  ASSERT_EQUALS(expected_2, customSort(b, b_size));

  // Write your own test cases below

  string c[] {"However", "Italy", "Super", "Faltering", "pretenTious", "I", "vornado", 
	  "jbl", "chAiN" , "Baller" , "compute"};
  size_t c_size = 11;
  string expected_3 = "I,JBL,CHAIN,ITALY,SUPER,BALLER,COMPUTE,HOWEVER,VORNADO,FALTERING,PRETENTIOUS";
  ASSERT_EQUALS(expected_3, customSort(c, c_size));

  string d[0];
  size_t d_size= 0;
  string expected_4 = "";
  ASSERT_EQUALS(expected_4, customSort(d, d_size));


  string e[]{"Windows", "XP", "value", "Wallet", "Wart", "Walrus", "afterburner", "stats", "anamoly"};
  size_t e_size = 9;
  string expected_5 = "XP,WART,STATS,VALUE,WALLET,WALRUS,ANAMOLY,WINDOWS,AFTERBURNER";
  ASSERT_EQUALS(expected_5, customSort(e, e_size));



  return 0;
}

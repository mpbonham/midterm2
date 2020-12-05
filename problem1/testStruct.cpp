#include "MyStructs.h"
#include "structFuncs.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {

  // Sample
  CreditCard1 a;
  unsigned long sizeCreditCard1 = 40;
  ASSERT_EQUALS(sizeof(a), sizeCreditCard1);
  
  //You should write your own tests below.
  
  // Test to test size of CreditCard2
  CreditCard2 b;
  unsigned long sizeCreditCard2 = 48;
  ASSERT_EQUALS(sizeof(b), sizeCreditCard2);

  // Test to test size of CreditCard3
  CreditCard3 c;
  unsigned long sizeCreditCard3 = 32;
  ASSERT_EQUALS(sizeof(c), sizeCreditCard3);

  cout << "Testing the padding of the values" << endl;
  
  // tests the padding of CreditCard1
  unsigned long sizePadding1 = 12;
  ASSERT_EQUALS(getPadding(a), sizePadding1);

  // tests the padding of CreditCard2
  unsigned long sizePadding2 = 20;
  ASSERT_EQUALS(getPadding(b), sizePadding2);

  // tests the padding of CreditCard3
  unsigned long sizePadding3 = 4 ;
  ASSERT_EQUALS(getPadding(c), sizePadding3);

  return 0;
}

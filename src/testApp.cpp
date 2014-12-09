// Local includes:
#include "TestLib.hpp"
#include "ExtLib.hpp"

// Compiler includes:
#include <iostream>

using namespace std;

int main()
{
  cout << "Hello world from testApp!" << endl;
  
  cout << "Calling local TestLib print from testApp..." << endl;
  test::testLibPrint();

  cout << "Calling external ExtLib print from testApp..." << endl;
  other_test::testExtLibPrint();

  cout << endl << "Test completed." << endl;

  return 0;
}

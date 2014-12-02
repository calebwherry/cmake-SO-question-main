// Local includes:
#include "TestLib.hpp"
#include "ExtLib.hpp"

// Compiler includes:
#include <iostream>

using namespace std;

int main()
{
  cout << "Hello world!" << endl;

  // Function from local lib:
  test::testLibPrint();

  // Function from external lib:
  //other_test::testExtLibPrint();

  return 0;
}

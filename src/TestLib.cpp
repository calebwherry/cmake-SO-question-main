// Local includes:
#include "ExtLib.hpp"

// Compiler incudes:
#include <iostream>

using namespace std;

namespace test
{
  void testLibPrint()
  {
    cout << "Hello world from TestLib!" << endl;
    cout << "Calling external ExtLib print from TestLib..." << endl;
		other_test::testExtLibPrint();
  }
}

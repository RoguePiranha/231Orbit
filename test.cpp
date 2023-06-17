/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testSatellite.h"
#include "testPhysics.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   testSatellite().run();
   testPhysics().run();

   cout << "All Tests have passed.  Success!!!" << endl;
}

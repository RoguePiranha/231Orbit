#pragma once
#include "physics.h"
#include "cassert"
#include <iostream>
using namespace std;

class TestPhysics
{
public:
   void run()
   {
      TestSeaLevelGravity();
      TestGravityAboveEarth();

      TestGravityDirectionTop();
      TestGravityDirectionRight();
      TestGravityDirectionBottom();

      TestComputeHeightAboveEarthTop();
      TestComputeHeightAboveEarthRight();
      TestComputeHeightAboveEarthMiddle();
   }


private:
   bool Range(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   void TestGravityAboveEarth()
   {

      double height = 35768000.0;
      double gHeight;
      //exercise
      gHeight = gravityHeight(height);
      //verify
      assert( Range(-0.2244, gHeight, 0.1));

   } // teardown

   void TestSeaLevelGravity()
   {
      //setup
      double height = 0.0;
      double gHeight;
      //exercise
      gHeight = gravityHeight(height);
      //verify
      assert( Range(-9.8067, gHeight, 0.1));

   } // teardown


   void TestGravityDirectionTop()
   {
      //setup
      double x = 0.0;
      double y = 1000.0;
      double gDirection;
      //exercise
      gDirection = gravityDirection(x, y);

      //verify
      assert(x == 0.0);
      assert(y == 1000.0);
      assert(Range(0.0, gDirection, 0.1));
   } // teardown

   void TestGravityDirectionRight()
   {
      //setup
      double x = 1000.0;
      double y = 0.0;
      double gDirection;
      //exercise
      gDirection = gravityDirection(x, y);
      //verify
      assert(x == 1000.0);
      assert(y == 0.0);
      assert(Range(1.571, gDirection, 0.1));
   } // teardown

   void TestGravityDirectionBottom()
   {
      //setup
      double x = 0.0;
      double y = -1000.0;
      double gDirection;
      //exercise
      gDirection = gravityDirection(x, y);
      //verify
      assert(x == 0.0);
      assert(y == -1000.0);
      assert(Range(3.14159265, gDirection, 0.1));
   } // teardown

   void TestComputeHeightAboveEarthTop()
   {
      //setup
      double x = 0.0;
      double y = 6379000.0; 
      double height;
      //exercise
      height = computeHeightAboveEarth(x, y);
      //verify
      assert(x == 0.0);
      assert(y == 6379000.0);
      assert(Range(1000.0, height, 0.1));
   } // teardown

   void TestComputeHeightAboveEarthRight()
   {
      //setup
      double x = 6379000.0;
      double y = 0.0; 
      double height;
      //exercise
      height = computeHeightAboveEarth(x, y);
      //verify
      assert(x == 6379000.0);
      assert(y == 0.0);
      assert(Range(1000.0, height, 0.1));
   } // teardown

   void TestComputeHeightAboveEarthMiddle()
   {
      //setup
      double x = 6379000.0;
      double y = 6379000.0; 
      double height;
      //exercise
      height = computeHeightAboveEarth(x, y);
      //verify
      assert(x == 6379000.0);
      assert(y == 6379000.0);
      assert(Range(2643268.3, height, 1.0));
   } // teardown
};

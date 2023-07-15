#pragma once
#pragma once
#include "physics.h"
#include "cassert"
#include <iostream>
using namespace std;

class testPhysics
{
public:
    void run()
    {
        testGravityHeightSeaLevel();
        testGravityHeightAboveEarth();

        testGravityDirectionTop();
        testGravityDirectionRight();
        testGravityDirectionBottom();

        testComputeHeightAboveEarthTop();
        testComputeHeightAboveEarthRight();
        testComputeHeightAboveEarthMiddle();
    }


private:
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }

    void testGravityHeightAboveEarth()
    {

        double height = 35768000.0;
        double gHeight;
        //exercise
        gHeight = gravityHeight(height);
        //verify
        assert(closeEnough(-0.2244, gHeight, 0.1));

    } // teardown

    void testGravityHeightSeaLevel()
    {
        //setup
        double height = 0.0;
        double gHeight;
        //exercise
        gHeight = gravityHeight(height);
        //verify
        assert(closeEnough(-9.8067, gHeight, 0.1));

    } // teardown


    void testGravityDirectionTop()
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
        assert(closeEnough(0.0, gDirection, 0.1));
    } // teardown

    void testGravityDirectionRight()
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
        assert(closeEnough(1.571, gDirection, 0.1));
    } // teardown

    void testGravityDirectionBottom()
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
        assert(closeEnough(3.14159265, gDirection, 0.1));
    } // teardown

    void testComputeHeightAboveEarthTop()
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
        assert(closeEnough(1000.0, height, 0.1));
    } // teardown

    void testComputeHeightAboveEarthRight()
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
        assert(closeEnough(1000.0, height, 0.1));
    } // teardown

    void testComputeHeightAboveEarthMiddle()
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
        assert(closeEnough(2643268.3, height, 1.0));
    } // teardown
};
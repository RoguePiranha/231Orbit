#pragma once
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;

const double radius = 6378000.0;
const double gravity = -9.8067;

inline double computeHeightAboveEarth(double x, double y)
{
   return sqrt((x * x) + (y * y)) - radius;
}

inline double gravityHeight(double height)
{
   return gravity * ((radius / (radius + height)) * (radius / (radius + height)));
}

inline double gravityDirection(double x, double y)
{
    return atan2(x,y);
}


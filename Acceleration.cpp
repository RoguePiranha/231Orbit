#include "Acceleration.h"

 /***********************************************************************
  * Acceleration
  * A non-default constructor that takes in a ddx and ddy
  ************************************************************************/
Acceleration::Acceleration(double ddx, double ddy)
{
   this->ddx = ddx;
   this->ddy = ddy;
}

/***********************************************************************
 * Acceleration COMPUTE HORIZONTAL COMP
 * Uses dx to calculate ddx.
 ************************************************************************/
double Acceleration::computeHorizontalComp(double angle, double gravityHeight) const
{
   // Compute x componenent of acceleration
   return sin(angle) * gravityHeight;
}

/***********************************************************************
 * Acceleration COMPUTE VERTICAL COMP
 * Uses dy to calculate ddy.
 ************************************************************************/
double Acceleration::computeVerticalComp(double angle, double gravityHeight) const
{
   // Compute y componenent of acceleration
   return (cos(angle) * gravityHeight);
}

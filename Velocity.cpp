#include "Velocity.h"
#include <cmath> // for sqrt
#define _USE_MATH_DEFINES
#include <math.h> 


/***********************************************************************
 * Velocity
 * Adds velocity based off of a given angle and speed
 ************************************************************************/
void Velocity::setVelocity(double angle, double speed)
{
   dx = sin(angle) * speed;
   dy = cos(angle) * speed;
}

/***********************************************************************
 * Velocity UPDATE VELOCITY
 * Adds acceleration to the velocity
 ************************************************************************/
void Velocity::updateVelocity(const Acceleration &accel, double time)
{
   dx = (dx + accel.getDDX() * time);
   dy = (dy + accel.getDDY() * time);
}


void Velocity::addVelocity(Velocity vel)
{
   dx += vel.getDX();
   dy += vel.getDY();
}

/******************************************
 * VELOCITY : ASSIGNMENT
 * Assign a point
 *****************************************/
Velocity& Velocity::operator = (const Velocity& vel)
{
   dx = vel.dx;
   dy = vel.dy;
   return *this;
}

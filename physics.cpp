/***********************************************************************
 * Header File:
 *   Physics : The representation of the physics of the game
 * Authors:
 *   Dallin Olson, Andrew Swayze
 * Summary:
 *  This is the code that will be used to calculate the physics of the game.
 *  It determines everything from the time dilation to the relative position
 *  of a satellite to the Earth.
 ************************************************************************/

#include "physics.h"
#include <cmath>

#define pi 3.14159265358979323846

/********************************************/
/*                   TIME                   */
/********************************************/

/**********************************
* Time Dilation
* Equation:
*   td = hoursDay x minutesHour
* Variables:
*   td - Time dilation, which is the
*        ratio of simulated time to
*        real time.
*   hoursDay - Hours in a day.
*   minutesHour - Minutes in an hour.
**********************************/
void Physics::timeDilation(double hoursDay, double minutesHour){
	double td = hoursDay * minutesHour;
};

/**********************************
* Time Per Frame
* Equation:
*   tpf = td / frameRate
* Variables:
*   tpf - Time per frame, which is 
*         the real time that passes
*         per second for each frame
*         of the simulation.
*   td - Time dilation
*   frameRate - Frames per second (30)
**********************************/
void Physics::timePerFrame(double frameRate){
	double tpf = td / frameRate;
};

/********************************************/
/*                   EARTH                  */
/********************************************/

/**********************************
* Rotation Speed
* Equation:
*   r˅f = -(2 pi / frameRate) * (td / secondsDay)
* Variables:
*   r˅f - Rotation of the earth in radians per frame.
*   pi - 3.14159265358979323846
*   frameRate - Frames per second (30)
*   td - Time dilation
*   secondsDay - Number of seconds for the Earth to
*                complete one rotation (86400)
**********************************/
double Physics::rotationSpeed(double frameRate, double secondsDay){
	return -(2 * pi / frameRate) * (td / secondsDay);
};

/**********************************
* Gravity Equation
* Equation:
*   g˅h = g(r / (r + h))ˆ2
* Variables:
*   g˅h - magnitude of acceleration due to 
*         gravity at an altitude (h)
*   g - gravity at sea level (9.8 m/sˆ2)
*   r - radius of the Earth (6,378,000 m)
**********************************/
double Physics::gravityEquation(double g, double r, double h){
	return g * std::pow((r / (r + h)), 2);
};

/**********************************
* Height Above Earth
* Equation:
*   h =  √(x^2 + y^2) - r
* Variables:
*   h - Height above the Earth's surface (m)
*   x - Horizontal position of the satellite
*       relative to the center of the Earth (0)
*   y - Vertical position of the satellite
*       relative to the center of the Earth (0)
*   r - Radius of the Earth (6,378,000 m)
**********************************/
double Physics::HtAboveEarth(double x, double y, double r){
	return std::sqrt(std::pow(x, 2) + std::pow(y, 2)) - r;
};

/**********************************
* Direction of Gravity Pull
* Equation:
*   atan(x˅e - x˅s, y˅e - y˅s)
* Variables:
*   atan - Arc tangent function
*   d = direction of the pull of gravity, in radians
*   x˅e = horizontal position of the center of the earth: 0 m
*   y˅e = vertical position of the center of the earth: 0 m
*   x˅s = horizontal position of the satellite in meters
*   y˅s = vertical position of the satellite in meters
**********************************/
double Physics::DirectionOfGravity(double xe, double ye, double xs, double ys){
	return std::atan2((ye - ys), (xe - xs));
};

/**********************************
* Horizontal Component of Acceleration
* Equation:
*   ddx = a sin(angle)
* Variables:
*   ddx = horizontal component of acceleration
*   a = total acceleration
*   angle = angle (0° is up) of the direction of acceleration
**********************************/
double Physics::HorizontalCompAcceleration(double a, double angle){
	return a * std::sin(angle);
};

/**********************************
* Vertical Component of Acceleration
* Equation:
*   ddy = a cos(angle)
* Variables:
*   ddy = vertical component of acceleration
*   a = total acceleration
*   angle = angle (0° is up) of the direction of acceleration
**********************************/
double Physics::VerticalCompAcceleration(double a, double angle){
	return a * std::cos(angle);
};

/********************************************/
/*                 MOTION                   */
/********************************************/

/*****************************
* NEWTONS FIRST LAW
* Equation:
*	S˅t = S˅o
* Variables:
*	S˅t - Distance at a given time t.
* This is a position on a coordinate plane
*	S˅o - Initial position.
*****************************/
double Physics::NewtonsFirstLaw(double S0)
{
	double St = S0;
	return St;
}


/*****************************
* MOTION WITH CONSTANT VELOCITY
* Equation:
*	s = s˅0 + V * t
* Variables:
*	s	- Distance in meters (m).
*	s˅0 - Initial distance (m)
*	v   - Velocity (m/s).
*	t   - Time (s).
*****************************/
double Physics::MotionWConstVel(double s0, double v, double t)
{
	double s = s0 + (v * t);
	return s;
}


/*****************************
* HORIZONTAL POSITION CONSTANT VELOCITY
* Equation:
*	x˅t = x˅0 + dx * t
* Variables:
*	x˅t	- Horizontal position at time t (m).
*	x˅0 - Initial horizontal position (m).
*	dx  - Horizontal component of velocity (m/s).
*	t   - Time (s).
*****************************/


double Physics::HorizontalPosConstVel(double x0, double dx, double t)
{
	double xt = x0 + (dx * t);
	return xt;
}


/*****************************
* VERTICAL POSITION CONSTANT VELOCITY
* Equation:
*	y˅t = y˅0 + dy * t
* Variables:
*	y˅t	- Horizontal position at time t (m).
*	y˅0 - Initial horizontal position (m).
*	dy  - Horizontal component of velocity (m/s).
*	t   - Time (s).
*****************************/
double Physics::VerticalPosConstVel(double y0, double dy, double t)
{
	double yt = y0 + (dy * t);
	return yt;
}

/*****************************
* DISTANCE FORMULA
* Equation:
*   s = s˅0 + v t + ½ a t˅2
* Variables:
*   s - Distance in meters (m)
*   s˅0 - Initial distance (m)
*   v - Velocity (m/s)
*   t - Time (s)
*   a - Acceleration (m/s˅2)
*****************************/
double Physics::DistanceFormula(double s0, double v, double t, double a)
{
	return s0 + (v * t) + (0.5 * a * std::pow(t, 2));
}

/*****************************
* VELOCITY WITH CONSTANT ACCELERATION
* Equation:
*   v = v˅0 + a t
* Variables:
*   v - Velocity in meters per second (m/s)
*   v˅0 - Initial velocity (m/s)
*   a - Acceleration (m/s˅2)
*   t - Time (s)
*****************************/
double Physics::VelocityWConstAccel(double v0, double a, double t)
{
	return v0 + (a * t);
}

/*****************************
* HORIZONTAL DISTANCE FORMULA
* Equation:
*   x˅t = x˅0 + dx t + ½ ddx t^2
* Variables:
*   x˅t - Horizontal position at time t (m)
*   x˅0 - Initial horizontal position (m)
*   dx - Horizontal component of velocity (m/s)
*   ddx - Horizontal component of acceleration (m/s˅2)
*   t - Time (s)
*****************************/
double Physics::HorizontalDisFormula(double x0, double dx, double ddx, double t)
{
	return x0 + (dx * t) + (0.5 * ddx * std::pow(t, 2));
}

/*****************************
* VERTICAL DISTANCE FORMULA
* Equation:
*   y˅t = y˅0 + dy t + ½ ddy t^2
* Variables:
*   y˅t - Vertical position at time t (m)
*   y˅0 - Initial vertical position (m)
*   dy - Vertical component of velocity (m/s)
*   ddy - Vertical component of acceleration (m/s˅2)
*   t - Time (s)
****************************/
double Physics::VerticalDisFormula(double y0, double dy, double ddy, double t)
{
	return y0 + (dy * t) + (0.5 * ddy * std::pow(t, 2));
}

/*****************************
* HORIZONTAL VELOCITY WITH CONSTANT ACCELERATION
* Equation:
*   dx˅t = dx˅0 + ddx t
* Variables:
*   dx˅t - Horizontal component of velocity at time t (m/s)
*   dx˅0 - Initial horizontal component of velocity (m/s)
*   ddx - Horizontal component of acceleration (m/s˅2)
*   t - Time (s)
*****************************/
double Physics::HorizontalVelWConstAccel(double dx0, double ddx, double t)
{
	return dx0 + (ddx * t);
}

/*****************************
* VERTICAL VELOCITY WITH CONSTANT ACCELERATION
* Equation:
*   dy˅t = dy˅0 + ddy t
* Variables:
*   dy˅t - Vertical component of velocity at time t (m/s)
*   dy˅0 - Initial vertical component of velocity (m/s)
*   ddy - Vertical component of acceleration (m/s˅2)
*   t - Time (s)
***************************/
double Physics::VerticalVelWConstAccel(double dy0, double ddy, double t)
{
	return dy0 + (ddy * t);
}

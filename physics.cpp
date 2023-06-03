#include "physics.h"


/********************************************/
/*                   TIME                   */
/********************************************/

/**********************************
* Time Dilation
* Equation:
*    td = hoursDay x minutesHour
* Variables:
*    td - Time dilation, which is the
*         ratio of simulated time to
*         real time.
*    hoursDay - Hours in a day.
*    minutesHour - Minutes in an hour.
**********************************/
void Physics::timeDilation();

/**********************************
* Time Per Frame
* Equation:
*    tpf = td / frameRate
* Variables:
*    tpf - Time per frame, which is 
*          the real time that passes
*          per second for each frame
*          of the simulation.
*    td - Time dilation
*    frameRate - Frames per second (30)
**********************************/
void Physics::timePerFrame();

/********************************************/
/*                   EARTH                  */
/********************************************/

/**********************************
* Rotation Speed
* Equation:
*    r˅f = -(2 pi / frameRate) * (td / secondsDay)
* Variables:
*    r˅f - Rotation of the earth in radians per frame.
*    pi - 3.14159265358979323846
*    frameRate - Frames per second (30)
*    td - Time dilation
*    secondsDay - Number of seconds for the Earth to
*                 complete one rotation (86400)
**********************************/
double Physics::rotationSpeed();

/**********************************
* Gravity Equation
* Equation:
*    g˅h = g(r / (r + h))ˆ2
* Variables:
*    g˅h - magnitude of acceleration due to 
*          gravity at an altitude (h)
*    g - gravity at sea level (9.8 m/sˆ2)
*    r - radius of the Earth (6,378,000 m)
**********************************/
double Physics::gravityEquation();

/**********************************
* Height Above Earth
* Equation:
*    h =  √(x^2 + y^2) - r
* Variables:
*    h - Height above the Earth's surface (m)
*    x - Horizontal position of the satellite
*        relative to the center of the Earth (0)
*    y - Vertical position of the satellite
*        relative to the center of the Earth (0)
*    r - Radius of the Earth (6,378,000 m)
**********************************/
double Physics::HtAboveEarth();
double Physics::DirectionOfGravity();
double Physics::HorizontalCompAcceleration();
double Physics::VerticalCompAcceleration();

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
double Physics::NewtonsFirstLaw(double So)
{
	double St = So;
	return St;
}


/*****************************
* MOTION WITH CONSTANT VELOCITY
* Equation:
*	s = s˅o + V * t
* Variables:
*	s	- Distance in meters (m).
*	s˅o - Initial distance (m)
*	v   - Velocity (m/s).
*	t   - Time (s).
*****************************/
double Physics::MotionWConstVel(double so, double v, double t)
{
	double s = so + (v * t);
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


double Physics::HorizontalPosConstVel(double xo, double dx, double t)
{
	double xt = xo + (dx * t);
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
double Physics::VerticalPosConstVel(double yo, double dy, double t)
{
	double yt = yo + (dy * t);
	return yt;
}


double Physics::DistanceFormula();
double Physics::VelocityWConstAccel();
double Physics::HorizontalDisFormula();
double Physics::VerticalDisFormula();
double Physics::HorizontalVelWConstAccel();
double Physics::VerticalVelWConstAccel();

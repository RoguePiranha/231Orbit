#include "sputnik.h"

/***************************************
* NON DEFAULT CONSTRUCTOR
* Set up the satellites position and
* velocity.
****************************************/
Sputnik::Sputnik(double x, double y, double dx, double dy)
{
	pos.setMetersX(x);
	pos.setMetersY(y);
	velocity.setDX(dx);
	velocity.setDY(dy);
	status = ALIVE;
	type = SATELLITE;
}
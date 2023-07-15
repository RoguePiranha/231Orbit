#include "gps.h"

/***************************************
* NON DEFAULT CONSTRUCTOR
* Set up the satellites position and
* velocity.
****************************************/
GPS::GPS(double x, double y, double dx, double dy)
{
    pos.setMetersX(x);
    pos.setMetersY(y);
    velocity.setDX(dx);
    velocity.setDY(dy);
}


/***************************************
* SPAWN PARTS
* Spawn the parts of the broken satellite
****************************************/
void GPS::spawnParts(list<Satellite*>& satellites)
{
    GPSCenter* pGPSCenter = new GPSCenter(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    GPSRight* pGPSRight = new GPSRight(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    GPSLeft* pGPSLeft = new GPSLeft(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());

    satellites.push_back(pGPSCenter);
    satellites.push_back(pGPSRight);
    satellites.push_back(pGPSLeft);
}
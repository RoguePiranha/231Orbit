/***********************************************************************
 * Source File:
 *    StarLink
 * Author:
 *    Ben, Star, and Mike
 * Summary:
 * A type of satellite
 ************************************************************************/

#include "starlink.h"

 /***************************************
 * NON DEFAULT CONSTRUCTOR
 * Set up the satellites position and
 * velocity.
 ****************************************/
Starlink::Starlink(double x, double y, double dx, double dy) 
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
void Starlink::spawnParts(list<Satellite*>& satellites)
{
    StarlinkArray*  pStarlinkArray = new StarlinkArray(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY()  + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());
    StarlinkBody*   pStarlinkBody  = new StarlinkBody(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());

    satellites.push_back(pStarlinkArray);
    satellites.push_back(pStarlinkBody);
}
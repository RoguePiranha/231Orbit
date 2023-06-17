#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "satellitePart.h"

class Dragon : public Satellite
{
public:
   Dragon() {}
   Dragon(double x, double y, double dx, double dy);

   void  draw()  const {drawCrewDragon(pos, angle); }
   void spawnParts(list<Satellite*>& satellites); 

};


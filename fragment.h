#pragma once
#include "satellite.h"
#include "uiDraw.h"

class Fragment : public Satellite
{
public:
   Fragment() {}
   Fragment(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); decayTime = 50; type = DECAYABLE; }
   void draw() const { drawFragment(pos, 0.1); }

};


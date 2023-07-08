#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Ship : public Satellite
{
public:

   Ship() {  }
   Ship(double x, double y) {pos.setMetersX(x);  pos.setMetersY(y); type = SHIP;}

   void drawSpaceShip(const Interface *pUI)  const {drawShip(pos, angle, pUI->isUp()); }
   void moveShip(double time, const Interface* pUI);
   void satelliteInput(const Interface * pUI, list<Satellite*> &satellites);
};


#pragma once
#include "satellite.h"
#include "uiDraw.h"

class DragonRight : public Satellite
{
public:
   DragonRight() {}
   DragonRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawCrewDragonRight(pos, angle); }
};

class DragonLeft : public Satellite
{
public:
   DragonLeft() {}
   DragonLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawCrewDragonLeft(pos, angle); }
};

class DragonCenter : public Satellite
{
public:
   DragonCenter() {}
   DragonCenter(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawCrewDragonCenter(pos, angle); }
};

class GPSCenter : public Satellite
{
public:
   GPSCenter() {}
   GPSCenter(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawGPSCenter(pos, angle); }
};

class GPSRight : public Satellite
{
public:
   GPSRight() {}
   GPSRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawGPSRight(pos, angle); }
};

class GPSLeft : public Satellite
{
public:
   GPSLeft() {}
   GPSLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawGPSLeft(pos, angle); }
};

class StarlinkBody : public Satellite
{
public:
   StarlinkBody() {}
   StarlinkBody(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawStarlinkBody(pos, angle); }
};

class StarlinkArray : public Satellite
{
public:
   StarlinkArray() {}
   StarlinkArray(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawStarlinkArray(pos, angle); }
};

class HubbleComputer : public Satellite
{
public:
   HubbleComputer() {}
   HubbleComputer(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawHubbleComputer(pos, angle); }
};

class HubbleTelescope : public Satellite
{
public:
   HubbleTelescope() {}
   HubbleTelescope(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawHubbleTelescope(pos, angle); }
};

class HubbleLeft : public Satellite
{
public:
   HubbleLeft() {}
   HubbleLeft(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART;}
   void  draw()  const { drawHubbleLeft(pos, angle); }
};

class HubbleRight : public Satellite
{
public:
   HubbleRight() {}
   HubbleRight(double x, double y, double dx, double dy) { pos.setMetersX(x);  pos.setMetersY(y); velocity.setDX(dx); velocity.setDY(dy); type = PART; }
   void  draw()  const { drawHubbleRight(pos, angle); }
};
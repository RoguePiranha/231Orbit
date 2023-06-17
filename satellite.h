#pragma once
#include "position.h"
#include "uiInteract.h"
#include "Velocity.h"
#include "physics.h"
#include <iostream>
#include <list>
using namespace std;

enum Status { ALIVE, DEAD, BROKEN };
enum Type { SHIP, SATELLITE, PART, DECAYABLE };

class Satellite
{
   friend class testSatellite;
   friend class DummySatellite;
   friend class StubSatellite;

protected:
   Position pos;
   Status status = ALIVE;
   Type type = SATELLITE;
   Velocity velocity;
   double angularVelocity;
   double radius;
   double decayTime = 0.0;
   double angle = 0.1;
   

public:
   Satellite(){}
   Satellite(double x, double y) {pos.setMetersX(x);  pos.setMetersY(y);}
   Satellite(double x, double y, double dx, double dy);
   Status getStatus()      { return status; }
   Type getType()          { return type; }
   Position getPosition()  { return pos; }
   double getRadius()      { return radius; }
   double getDecayTime()   { return decayTime; }
   void setDeadStatus() { status = DEAD; }
   void setBrokenStatus() { status = BROKEN; }
   void setPosition(Position position) { pos = position; }
   void setVelocity(Velocity vel) { velocity = vel;}
   bool updateAngle() { return angle+= 25; }
   void updateDecayTime() {decayTime--; }
   virtual void satelliteInput(const Interface* pUI, list<Satellite*> &satellites) {}
   virtual void draw() const {}
   virtual void drawSpaceShip(const Interface *pUI) const {}
   virtual void spawnFragments(list<Satellite*>& satellites);
   virtual void spawnProjectile(list<Satellite*>& satellites);
   virtual void spawnParts(list<Satellite*>& satellites) {}
   virtual void move(double time);
   virtual void moveShip(double time, const Interface* pUI){}
};


#include "satellite.h"

<<<<<<< Updated upstream
/*********************************************
 *  GET ALTITUDE
 *  Computes the distance from the center of the
 *  earth to the satellite's current position.
 *********************************************/
double Satellite::getAltitude() const
{
 
	float distance = sqrt(pos.getMetersX() * pos.getMetersX()
						  + pos.getMetersY() * pos.getMetersY());
=======
Satellite::Satellite(double x, double y, double dx, double dy) 
{ 
   pos.setMetersX(x);  
   pos.setMetersY(y); 
   velocity.setDX(dx); 
   velocity.setDY(dy); 
}

void Satellite::spawnFragments(list<Satellite*>& satellites)
{
   Fragment*  pFragment1 = new Fragment(pos.getMetersX() + random(-6000000.0, 6000000.0), pos.getMetersY() + 3000000 + random(-6000000.0, 6000000.0), velocity.getDX(), velocity.getDY());

   satellites.push_back(pFragment1);

}

void Satellite::spawnProjectile(list<Satellite*>& satellites)
{
   //Step 1: Set Bullet to Ship Position
   Projectile* pProjectile = new Projectile(pos.getMetersX(), pos.getMetersY());

   //Step 2: Give Velocity
   Velocity projectileVel;
   projectileVel.setVelocity(angle, 50000.0);
   projectileVel.addVelocity(velocity);
   pProjectile->setVelocity(projectileVel);
   pProjectile->move(100);
   
   satellites.push_back(pProjectile);
>>>>>>> Stashed changes

	return distance - EARTH_RADIUS;
}

/*********************************************
 * GET GRAVITY
 * Computes amount and direction of gravity
 * at a given altitude
 *********************************************/
Acceleration Satellite::getGravity()
{
<<<<<<< Updated upstream
	// altitude = height above the earth
	double altitude = getAltitude();
	double gravity = 9.8067;
	
	// direction of gravity points down
	Direction dirGravity;
	dirGravity.setDxDy(-pos.getMetersX(), -pos.getMetersY());
=======
   Acceleration accel;
   // Compute physicss
   double gravity = gravityDirection(pos.getMetersX(), pos.getMetersY());
>>>>>>> Stashed changes

	double tmp = EARTH_RADIUS / (EARTH_RADIUS + altitude);
	double aGravity = GRAVITY * pow(tmp, 2);
	
	return Acceleration(aGravity, dirGravity);
}

/*********************************************
 *  UPDATE POSITION
 *  Updates the satellite's position based on its current
 *  position, velocity, and time.
 *********************************************/
void Satellite::updatePosition(const Acceleration &aGravity, double time)
{
	pos.addMetersX(velocity.getDx() * time + (0.5 * aGravity.getDDx()) * (time * time));
	pos.addMetersY(velocity.getDy() * time + (0.5 * aGravity.getDDy()) * (time * time));
}

/*********************************************
 *  SHIFT POSITION
 *  Shifts a satellite from its original position using
 *  a given distance in meters and direction of travel.
 *********************************************/
void Satellite::shiftPosition(double distance)
{
	double shiftX = distance * direction.getDx();
	double shiftY = distance * direction.getDy();
	
	pos.addMetersX(shiftX);
	pos.addMetersY(shiftY);
}
/*********************************************
 * 	EXPLODE
 *  Makes a Satellite object "shoot off" in a random
 *  direction upon collosion.
 *********************************************/
void Satellite::explode()
{
	// moves satelliteFragment 4px. from its point of creation
	double distance = pos.convertToMeters(4.0);
	
	shiftPosition(distance);
	velocity.setSpeed(velocity.getDx() + random(5000, 9000), velocity.getDy() + random(5000, 9000));

}

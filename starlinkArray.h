
#ifndef starlinkRight_h
#define starlinkRight_h

#include "satellitePiece.h"

class StarlinkArray : public SatellitePiece
{
public:
 
	StarlinkArray() : SatellitePiece() {}
	StarlinkArray(const Satellite &s, double degrees) : SatellitePiece(s, degrees, 7.0) // radius = 7 px.
	{
		setInvisible(true);
		explode();
	}

	virtual ~StarlinkArray() {}
	
	virtual bool isShip()       const { return false; }
	virtual bool isProjectile() const { return false; }
	virtual bool isPiece()      const { return true;  }
	virtual bool isFragment()   const { return false; }
	
	virtual void move(double time)
	{
		if (age >= 3)
			setInvisible(false);
		
		Acceleration aGravity = getGravity();
		velocity.updateVelocity(aGravity, time);
		updatePosition(aGravity, time);
		
		increaseAge();
	}
	
	// breaks into 3 fragments
	virtual void destroy(list<Satellite*> &satellites)
	{
		SatelliteFragment *sFragment1 = new SatelliteFragment(*this, random(0, 120));
		satellites.push_back(sFragment1);
		
		SatelliteFragment *sFragment2 = new SatelliteFragment(*this, random(250, 330));
		satellites.push_back(sFragment2);
		
		SatelliteFragment *sFragment3 = new SatelliteFragment(*this, random(130, 240));
		satellites.push_back(sFragment3);
	}
	
	virtual void draw(ogstream & gout)
	{
		gout.drawStarlinkArray(getPos(), getAngularVelocity());
	}
};

#endif /* starlinkArray_h */

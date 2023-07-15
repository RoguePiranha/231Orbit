#pragma once
#include "uiDraw.h"      
#include "uiInteract.h"
#include "position.h"
#include "gps.h"
#include "hubble.h"
#include "sputnik.h"
#include "starlink.h"
#include "dragon.h"
#include "star.h"
#include "ship.h"
#include "physics.h"
#include <list>

class Game
{
public:
	Game(Position ptUpperRight);


	void input(const Interface* pUI);
	void update(const Interface* pUI);
	void display(const Interface* pUI);
	void collision();
	void destroy();
	Position ptUpperRight;
	Position ptEarth;
	Star star;
	list<Satellite*> satellites;
	Star* pStars[200];
	unsigned char phaseStar;
	double angleEarth = 0.0;
	int timeToBreak = 0;

private:
	void moveSatellites(const Interface* pUI);
	void updateStars();
	void updateEarthAngle();
	void breakSatellite();
	void spinBrokenSatellite();
	void updateDecayTime();
};
#pragma once
#include "satellite.h"
#include "uiDraw.h"
#include "satellitePiece.h"

class Starlink : public Satellite
{
public:
	Starlink() {}
	Starlink(double x, double y, double dx, double dy);

	void  draw()  const { drawStarlink(pos, angle); }
	void spawnParts(list<Satellite*>& satellites);
};
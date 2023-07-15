#pragma once
#include "satellite.h"
#include "satellitePiece.h"
#include "uiDraw.h"

class GPS : public Satellite
{
public:
	GPS() {}
	GPS(double x, double y, double dx, double dy);

	void  draw()  const { drawGPS(pos, angle); }
	void spawnParts(list<Satellite*>& satellites);
};
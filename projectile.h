#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Projectile : public Satellite
{
public:
	Projectile() {}
	Projectile(double x, double y);
	void draw() const { drawProjectile(pos); }
};
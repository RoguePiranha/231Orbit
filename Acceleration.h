#pragma once
#include <math.h>

/***********************************************************************
 * Acceleration
 * Uses dX and dY to calculate the vertical
 * and horizontal components.
 ************************************************************************/
class Acceleration
{
private:
	double ddx;
	double ddy;

public:
	Acceleration() : ddx(0.0), ddy(0.0) {}
	Acceleration(double ddx, double ddy);
	double getDDX() const { return ddx; }
	double getDDY() const { return ddy; }
	void setDDX(const double  ddx) { this->ddx = ddx; }
	void setDDY(const double  ddy) { this->ddy = ddy; }
	double computeHorizontalComp(double angle, double velocity) const;
	double computeVerticalComp(double angle, double velocity) const;
};
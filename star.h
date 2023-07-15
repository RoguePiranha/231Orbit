#pragma once
#include "uiDraw.h"
#include "position.h"

class Star
{
public:
	unsigned char phaseStar;
	Position position;

	Star() {};
	Star(Position position, char phase) { this->position = position; phaseStar = phase; };

	void reset(double width, double height);
	void drawStars() { drawStar(position, phaseStar); }
	void updatePhase() { phaseStar++; }

};
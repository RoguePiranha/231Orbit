#ifndef star_h
#define star_h

#include "position.h"
#include "uiDraw.h"


class Star
{
public:
<<<<<<< Updated upstream
	Star(): pos(0.0, 0.0), phaseStar(0) {}
	Star(const Position &ptUpperRight): pos(0.0, 0.0), phaseStar(0) {
		
		phaseStar = random(0, 254);
		pos.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		pos.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
		
	}
	 
	void draw(ogstream & gout)
	{
		if (phaseStar == 255)
			phaseStar = random(0, 254);
		
		gout.drawStar(getPos(), getPhaseStar());
		advancePhaseStar();
	}
	 
	Position      getPos()       const { return pos;       }
	unsigned char getPhaseStar() const { return phaseStar; }
	
	void advancePhaseStar() { this->phaseStar += 1; }
	
private:
	Position pos;
	unsigned char phaseStar; // within 0 - 255 range
	
=======
   unsigned char phaseStar;
   Position position;

   Star() {};
   Star(Position position, char phase) { this->position = position; phaseStar = phase;};

   void reset(double width, double height);
   void drawStars() { drawStar(position, phaseStar); }
   void updatePhase() {phaseStar++;}
   
>>>>>>> Stashed changes
};

#endif /* star_h */

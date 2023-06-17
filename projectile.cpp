#include "projectile.h"

Projectile::Projectile(double x, double y) 
{ 
   pos.setMetersX(x);  
   pos.setMetersY(y); 
   decayTime = 20; 
   type = DECAYABLE; 
}
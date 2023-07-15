#include "ship.h"


/***************************************
* SATELLITE INPUT
* Move the Ship
****************************************/
void Ship::satelliteInput(const Interface* pUI, list<Satellite*>& satellites)
{
    if (pUI->isLeft())
        angle -= 0.1;
    if (pUI->isRight())
        angle += 0.1;
    if (pUI->isSpace())
        spawnProjectile(satellites);
}

/***************************************
* MOVE SHIP
* Calculate the math to move ship
****************************************/
void Ship::moveShip(double time, const Interface* pUI)
{
    Acceleration accel;

    // Compute physicss
    double gravity = gravityDirection(pos.getMetersX(), pos.getMetersY());

    double height = computeHeightAboveEarth(pos.getMetersX(), pos.getMetersY());

    double gHeight = gravityHeight(height);

    accel.setDDX(accel.computeHorizontalComp(gravity, gHeight));
    accel.setDDY(accel.computeVerticalComp(gravity, gHeight));

    if (pUI->isUp())
    {
        accel.setDDX(accel.getDDX() + accel.computeHorizontalComp(angle, 1.5));
        accel.setDDY(accel.getDDY() + accel.computeVerticalComp(angle, 1.5));
    }

    velocity.updateVelocity(accel, time);

    pos.setMetersX(distanceFormula(pos.getMetersX(), velocity.getDX(), accel.getDDX(), time));
    pos.setMetersY(distanceFormula(pos.getMetersY(), velocity.getDY(), accel.getDDY(), time));

}
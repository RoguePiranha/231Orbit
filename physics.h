/***********************************************************************
 * Header File:
 *   Physics : The representation of the physics of the game
 * Authors:
 *   Dallin Olson, Andrew Swayze
 * Summary:
 *  This is the code that will be used to calculate the physics of the game.
 *  It determines everything from the time dilation to the relative position
 *  of a satellite to the Earth.
 ************************************************************************/

class Physics
{
public:
    Physics();
    
    // Time
    void timeDilation();
    void timePerFrame();
    
    // Earth
    double rotationSpeed();
    double gravityEquation();
    double HtAboveEarth();
    double DirectionOfGravity();
    double HorizontalCompAcceleration();
    double VerticalCompAcceleration();

    // Motion
    double NewtonsFirstLaw(double S0);
    double MotionWConstVel(double S0, double V, double t);
    double HorizontalPosConstVel(double x0, double dx, double t);
    double VerticalPosConstVel(double y0, double dy, double t);
    double DistanceFormula();
    double VelocityWConstAccel();
    double HorizontalDisFormula();
    double VerticalDisFormula();
    double HorizontalVelWConstAccel();
    double VerticalVelWConstAccel();

};
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
private:
    double td; // Time dilation
    double tpf; // Time per frame

public:
    Physics();
    
    // Time
    void timeDilation(double hoursDay, double minutesHour);
    void timePerFrame(double frameRate);
    
    // Earth
    double rotationSpeed(double frameRate, double secondsDay);
    double gravityEquation(double g, double r, double h);
    double HtAboveEarth(double x, double y, double r);
    double DirectionOfGravity(double xe, double ye, double xs, double ys);
    double HorizontalCompAcceleration(double a, double angle);
    double VerticalCompAcceleration(double a, double angle);

    // Motion
    double NewtonsFirstLaw(double S0);
    double MotionWConstVel(double S0, double V, double t);
    double HorizontalPosConstVel(double x0, double dx, double t);
    double VerticalPosConstVel(double y0, double dy, double t);
    double DistanceFormula(double s0, double v, double t, double a);
    double VelocityWConstAccel(double v0, double a, double t);
    double HorizontalDisFormula(double x0, double dx, double ddx, double t);
    double VerticalDisFormula(double y0, double dy, double ddy, double t);
    double HorizontalVelWConstAccel(double dx0, double ddx, double t);
    double VerticalVelWConstAccel(double dy0, double ddy, double t);

};
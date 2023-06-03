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
    double NewtonsFirstLaw(double So);
    double MotionWConstVel(double So, double V, double t);
    double HorizontalPosConstVel(double xo, double dx, double t);
    double VerticalPosConstVel(double yo, double dy, double t);
    double DistanceFormula();
    double VelocityWConstAccel();
    double HorizontalDisFormula();
    double VerticalDisFormula();
    double HorizontalVelWConstAccel();
    double VerticalVelWConstAccel();

};
#pragma once

#include <iostream>
#include "cassert"
#include "satellite.h"
#include <list>
using namespace std;

class testSatellite
{
public:
    void run()
    {
        ConstructorTest();
        IsDeadTest();
        GetRadiusTest();
        GetPositionTest();

        DescendTest();
        AscendTest();
        YawLeftTest();
        YawRightTest();

        DestroyTest();
        DecayTimeTest();
        DecayTimeDeathTest();
    }

private:

    bool Range(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }

    void ConstructorTest()
    {
        //  setup
        // exercise
        Satellite satellite(0.0, 42164000.0);
        // verify
        assert(satellite.getPosition().getMetersX() == 0.0);
        assert(satellite.getPosition().getMetersY() == 42164000.0);
    }   //teardown

    void IsDeadTest() 
        {
        //  setup
        Satellite satellite;
        satellite.status = ALIVE;
        // exercise
        satellite.setDeadStatus();
        // verify
        assert(satellite.status == DEAD);
    }   // teardown

    void GetRadiusTest() const
    {
        // setup
        Satellite satellite;
        satellite.radius = 2.5;
        double satelliteradius;
        // exercise
        satelliteradius = satellite.getRadius();
        // verify
        assert(satelliteradius == 2.5);
    }  // teardown

    void GetPositionTest() const
    {
        // setup
        Satellite satellite;
        Position position(100.0, 100.0);
        satellite.pos = position;
        Position testpos;
        // exercise
        testpos = satellite.getPosition();
        // verify
        assert(testpos.getMetersX() == 100.0);
        assert(testpos.getMetersY() == 100.0);
    }  // teardown

    void DescendTest() const
    {
        // setup
        Satellite satellite;
        Position newposition(0.0, 6378000.0);
        Velocity vel(0.0, 0.0);
        satellite.pos = newposition;
        satellite.velocity = vel;
        double time = 1;
        // exercise
        satellite.move(time);
        // verify
        assert(Range(0.0, satellite.pos.getMetersX(), 0.1));
        assert(Range(6377990.2, satellite.pos.getMetersY() , 5.0));
        assert(Range(0.0, satellite.velocity.getDX(),  0.1));
        assert(Range(-9.8,  satellite.velocity.getDY(), 0.1));
    }  // teardown

    void AscendTest() const
    {
        // setup
        Satellite satellite;
        Position newposition(0.0, -6378000.0);
        Velocity vel(0.0, 0.0);
        satellite.pos = newposition;
        satellite.velocity = vel;
        double time = 1;
        // exercise
        satellite.move(time);
        // verify
        assert(Range(0.0, satellite.pos.getMetersX() , 0.1));
        assert(Range(-6377990.2, satellite.pos.getMetersY() , 5.0));
        assert(Range(0.0, satellite.velocity.getDX(),  0.1));
        assert(Range(9.8,  satellite.velocity.getDY(), 0.1));
    }   // teardown

    void YawLeftTest() const
    {
        // setup
        Satellite satellite;
        Position newposition(6378000.0, 0.0);
        Velocity vel(0.0, 0.0);
        satellite.pos = newposition;
        satellite.velocity = vel;
        double time = 1;
        // exercise
        satellite.move(time);
        // verify
        assert(Range(6377990.2, satellite.pos.getMetersX(), 5.0));
        assert(Range(0.0, satellite.pos.getMetersY(), 0.1));
        assert(Range(-9.8,  satellite.velocity.getDX(), 0.1));
        assert(Range(0.0, satellite.velocity.getDY(),  0.1));
    }   // teardown

    void YawRightTest() const
    {
        // setup
        Satellite satellite;
        Position newposition(-6378000.0, 0.0);
        Velocity vel(0.0, 0.0);
        satellite.pos = newposition;
        satellite.velocity = vel;
        double time = 1;
        // exercise
        satellite.move(time);
        // verify
        assert(Range(0.0, satellite.pos.getMetersY() , 0.1));
        assert(Range(-6377990.2, satellite.pos.getMetersX() , 5.0));
        assert(Range(9.8,  satellite.velocity.getDX(), 0.1));
        assert(Range(0.0, satellite.velocity.getDY(),  0.1));
    }   // teardown


    void DestroyTest() const
    {
        // setup
        Satellite satellite(0.0, 42164000.0);
        list<Satellite*> satellites;
        satellites.push_back(&satellite);
        // exercise
        satellite.spawnFragments(satellites);
        // verify
        assert(satellites.size() == 2);
    }   // teardown


    void DecayTimeTest()
    {
        // setup
        Satellite satellite;
        satellite.decayTime = 2;
      
        // exercise
        satellite.updateDecayTime();

        // verify
        assert(satellite.decayTime == 1);
    }

    void DecayTimeDeathTest()
    {
        // setup
        Satellite satellite;
        //satellite.dead = false;
        satellite.decayTime = 1;

        // exercise
        satellite.updateDecayTime();

        // verify
        assert(satellite.decayTime == 0);
        //assert(satellite.dead == true);
    }
};
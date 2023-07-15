#pragma once
#pragma once

#include <iostream>
#include "cassert"
#include "satellite.h"
#include <list>
using namespace std;

/***************************************
* DUMMY SATELLITE
****************************************/
class dummysatellite : public Satellite
{
public:
    dummysatellite() {}
    virtual float getradius() { assert(false); return 0.0; }
    virtual bool isdead() { assert(false); return false; }
    virtual Position getposition() { assert(false); Position pos; return pos; }
    virtual void  draw() const { assert(false); }
    virtual void destroy(list<dummysatellite>& satellites, list<dummysatellite>& decay) { assert(false); }
    virtual void move(float time) { assert(false); }
    virtual void input(Interface ui) { assert(false); }
};

/***************************************
 * STUB SATELLITE
 ****************************************/
class stubsatellite : public dummysatellite
{
public:
    stubsatellite() {}
    float getradius() { return 2.0; }
    //bool isDead() { return dead; }
    Position getposition() { Position pos; return pos; }
    void destroy(list<stubsatellite>& satellites, list<stubsatellite>& decay);
};

class testSatellite
{
public:
    void run()
    {
        nonDefaultConstructorTest();
        isdeadtest();
        getradiustest();
        getpositiontest();

        movetestfalldown();
        movetestfallup();
        movetestfallright();
        movetestfallleft();

        destroytest();
        decayTimeTest();
        decayTimeDeathTest();
    }

private:

    // utility funciton because floating point numbers are approximations
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }

    void nonDefaultConstructorTest()
    {
        //  setup
        // exercise
        Satellite satellite(0.0, 42164000.0);
        // verify
        assert(satellite.getPosition().getMetersX() == 0.0);
        assert(satellite.getPosition().getMetersY() == 42164000.0);
    }   //teardown

    void isdeadtest()
    {
        //  setup
        Satellite satellite;
        satellite.status == ALIVE;
        // exercise
        satellite.setDeadStatus();
        // verify
        assert(satellite.status == DEAD);
    }   // teardown

    void getradiustest() const
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

    void getpositiontest() const
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

    void movetestfalldown() const
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
        assert(closeEnough(0.0, satellite.pos.getMetersX(), 0.1));
        assert(closeEnough(6377990.2, satellite.pos.getMetersY(), 5.0));
        assert(closeEnough(0.0, satellite.velocity.getDX(), 0.1));
        assert(closeEnough(-9.8, satellite.velocity.getDY(), 0.1));
    }  // teardown

    void movetestfallup() const
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
        assert(closeEnough(0.0, satellite.pos.getMetersX(), 0.1));
        assert(closeEnough(-6377990.2, satellite.pos.getMetersY(), 5.0));
        assert(closeEnough(0.0, satellite.velocity.getDX(), 0.1));
        assert(closeEnough(9.8, satellite.velocity.getDY(), 0.1));
    }   // teardown

    void movetestfallleft() const
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
        assert(closeEnough(6377990.2, satellite.pos.getMetersX(), 5.0));
        assert(closeEnough(0.0, satellite.pos.getMetersY(), 0.1));
        assert(closeEnough(-9.8, satellite.velocity.getDX(), 0.1));
        assert(closeEnough(0.0, satellite.velocity.getDY(), 0.1));
    }   // teardown

    void movetestfallright() const
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
        assert(closeEnough(0.0, satellite.pos.getMetersY(), 0.1));
        assert(closeEnough(-6377990.2, satellite.pos.getMetersX(), 5.0));
        assert(closeEnough(9.8, satellite.velocity.getDX(), 0.1));
        assert(closeEnough(0.0, satellite.velocity.getDY(), 0.1));
    }   // teardown


    void destroytest() const
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


    void decayTimeTest()
    {
        // setup
        Satellite satellite;
        satellite.decayTime = 2;

        // exercise
        satellite.updateDecayTime();

        // verify
        assert(satellite.decayTime == 1);
    }

    void decayTimeDeathTest()
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
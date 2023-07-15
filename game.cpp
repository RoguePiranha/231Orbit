#include "game.h"
#include "cassert"

Game::Game(Position ptUpperRight) :
    ptUpperRight(ptUpperRight)
{
    Ship* pShip = new Ship(-36515095.13, 42164000.0);
    Hubble* pHubble = new Hubble(0.0, -42164000.0, 3100.0, 0.0);
    Sputnik* pSputnik = new Sputnik(-36515095.13, 21082000.0, 2050.0, 2684.68);
    Starlink* pStarlink = new Starlink(0.0, -13020000.0, 5800.0, 0.0);
    Dragon* pDragon = new Dragon(0.0, 8000000.0, -7900.0, 0.0);
    GPS* pGPS1 = new GPS(0.0, 26560000.0, -3880.0, 0.0);
    GPS* pGPS2 = new GPS(23001634.72, 13280000.0, -1940.00, 3360.18);
    GPS* pGPS3 = new GPS(23001634.72, -13280000.0, 1940.00, 3360.18);
    GPS* pGPS4 = new GPS(0.0, -26560000.0, 3880.0, 0.0);
    GPS* pGPS5 = new GPS(-23001634.72, -13280000.0, 1940.00, -3360.18);
    GPS* pGPS6 = new GPS(-23001634.72, 13280000.0, -1940.00, -3360.18);


    //Add to Satellite List
    satellites.push_back(pShip);
    satellites.push_back(pGPS1);
    satellites.push_back(pGPS2);
    satellites.push_back(pGPS3);
    satellites.push_back(pGPS4);
    satellites.push_back(pGPS5);
    satellites.push_back(pGPS6);
    satellites.push_back(pHubble);
    satellites.push_back(pSputnik);
    satellites.push_back(pStarlink);
    satellites.push_back(pDragon);

    //Phase Stars
    for (int i = 0; i < 200; i++)
    {
        Position ptStar(random(-60000000.0, 60000000.0), random(-60000000.0, 60000000.0));
        phaseStar = random(1, 224);
        Star* pStar = new Star(ptStar, phaseStar);
        pStars[i] = pStar;
    }
}


/***************************************
* INPUT
* Get User Input to move the ship
****************************************/
void Game::input(const Interface* pUI)
{
    satellites.front()->satelliteInput(pUI, satellites);
}

/***************************************
* UPDATE
* This will update all the objects of the
* Game.
****************************************/
void Game::update(const Interface* pUI)
{

    collision();
    destroy();

    moveSatellites(pUI);
    updateStars();
    updateEarthAngle();

    //Randomly break a Satellite
    breakSatellite();

    //Spin Broken Parts and Update Decay Time
    spinBrokenSatellite();
    updateDecayTime();
}

/***************************************
* DISPLAY
* Display everything to the user.
****************************************/
void Game::display(const Interface* pUI)
{
    // Set the Earths Position
    ptEarth.setMeters(0.0, 0.0);

    //Draw Earth
    drawEarth(ptEarth, angleEarth);

    //Draw Satellites
    for (auto sat : satellites)
    {
        if (sat->getType() != SHIP)
            sat->draw();
        else
            sat->drawSpaceShip(pUI);
    }

    //Draw Stars
    for (int star = 0; star < 200; star++)
        pStars[star]->drawStars();
}

/***************************************
* COLLISION
* This will update all the objects of the
* Game.
****************************************/
void Game::collision()
{
    for (auto sat : satellites)
    {
        if (computeHeightAboveEarth(sat->getPosition().getMetersX(), sat->getPosition().getMetersY()) < 0.0)
            sat->setDeadStatus();

        //If we hit other Floating Objects
        for (auto sat2 : satellites)
        {
            if (sat != sat2 && computeDistance(sat->getPosition(), sat2->getPosition()) < 3000000.0)
            {
                //Set the Collided Satellites as Dead
                sat->setDeadStatus();
                sat2->setDeadStatus();
            }
        }
    }
}

/***************************************
* DESTROY
* This will delete the pointers to the
* satellites and the satellites themselves
* from the list when needed.
****************************************/
void Game::destroy()
{

    for (auto it = satellites.begin(); it != satellites.end(); )
    {
        if ((*it)->getStatus() == DEAD)
        {
            if ((*it)->getType() != DECAYABLE)
            {
                (*it)->spawnFragments(satellites);
                (*it)->spawnParts(satellites);
            }
            delete* it;
            it = satellites.erase(it);
        }
        else
            ++it;
    }
}

/***************************************
* MOVE SATELLITES
* Move all satellites in the game
****************************************/
void Game::moveSatellites(const Interface* pUI)
{
    for (auto sat : satellites)
    {

        if (sat->getType() != SHIP)
            sat->move(48);
        else
            sat->moveShip(48, pUI);
    }
}

/***************************************
* UPDATE STARS
* Update the phases of the star
****************************************/
void Game::updateStars()
{
    for (int star = 0; star < 200; star++)
        pStars[star]->updatePhase();
}

/***************************************
* UPDATE ANGLE OF EARTH
* Update Angle of the earth as it spins
****************************************/
void Game::updateEarthAngle()
{
    angleEarth -= 0.00349;
}

/***************************************
* BREAK SATELLITES
* Randomly Break a satellite
****************************************/
void Game::breakSatellite()
{
    if (timeToBreak > 500)
    {
        double randomPosition = random(0, satellites.size());

        list<Satellite*>::iterator it = satellites.begin();
        advance(it, randomPosition);
        if ((*it)->getType() == SATELLITE)
        {
            //(*it)->setBroken();
            (*it)->setBrokenStatus();

            timeToBreak = 0;
        }
    }
    else
        timeToBreak++;
}

/***************************************
* SPIN BROKEN SATELLITES
* Spin any broken satellites
****************************************/
void Game::spinBrokenSatellite()
{
    for (auto sat : satellites)
    {
        if (sat->getStatus())
            sat->updateAngle();
    }
}

/***************************************
* UPDATE DECAY TIME
* Update the decay time of fragments
* or bullets
****************************************/
void Game::updateDecayTime()
{
    for (auto it = satellites.begin(); it != satellites.end(); )
    {
        if ((*it)->getType() == DECAYABLE)
        {
            if ((*it)->getDecayTime() == 0)
                (*it)->setDeadStatus();
            else
                (*it)->updateDecayTime();
        }
        ++it;
    }
}
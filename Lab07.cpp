#include <cassert>        
#include "uiInteract.h"   
#include "uiDraw.h"       
#include "position.h"     
#include "test.h"
#include <cmath>
#include <math.h>
#include "game.h"

using namespace std;

#define _USE_MATH_DEFINES 
#define DEBUG

void callBack(const Interface* pUI, void* p)
{
    Game* pGame = (Game*)p;

    pGame->input(pUI);
    pGame->update(pUI);
    pGame->display(pUI);


}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
    ptUpperRight.setPixelsX(1000.0);
    ptUpperRight.setPixelsY(1000.0);
    Interface ui(0, NULL,
        "Satellite Orbit",   /* name on the window */
        ptUpperRight);

    // Initialize the demo
    Game game(ptUpperRight);

    //Run Unit Tests
#ifdef DEBUG
    testRunner();
    cout << "Tests Passed" << endl;
#endif

    // set everything into action
    ui.run(callBack, &game);

    return 0;
}



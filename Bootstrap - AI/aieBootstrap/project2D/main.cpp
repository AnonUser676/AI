/********************************************************************************************
								AI Pathfinding and Behavior Styles
										by Rouie Ortega
									  using AIE Boostrap

										  Main - cpp
*******************************************************************************************/

//Include Files to get External references
#include "Application2D.h"
#include <crtdbg.h>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;																//namespace for easier usage of std

/* Program main begins */
int main()
{
	srand((unsigned int)time(0));													//required to get true randomm values for rand() function
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);					//reequired for memeory checking

	Application2D* app = new Application2D();										//creates instance of Application 2d for running Bootstrap
	
	app->run("AIE", 1920, 1080, false);												//sets resolution of windowed program
	
	delete app;																		//deletes app afterwards to avoid memory leaks
	
	return 0;																		//returns 0 once program ends to confirm that program ended succesfully
}
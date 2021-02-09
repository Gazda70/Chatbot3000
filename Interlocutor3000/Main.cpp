#include "UI.h"

int main()
{
    RenderWindow mainWindow{ VideoMode(1600, 900), "My window" };
    UI myUI(mainWindow);
    myUI.eventsLoop();
	return 0;
}
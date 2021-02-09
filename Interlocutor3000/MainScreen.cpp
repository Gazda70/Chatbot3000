#include "MainScreen.h"

MainScreen::MainScreen(double mywidth, double myheight):Screen(mywidth,myheight)
{
	SettingsContainer::getInstance().readButtonInitializationFile("MainScreenDimensions.txt");
	ButtonInitializer init = SettingsContainer::getInstance().initsButtonFront();
	mainmenu[static_cast<int>(MenuScreen::Tytul)] = new Button(width*init.x, height*init.y, width*init.w,
		height*init.h, init.color, init.name, init.font, height*init.textsize, init.textcolor, {init.textx, init.texty});

	init = SettingsContainer::getInstance().initsButtonFront();
	mainmenu[static_cast<int>(MenuScreen::Rozpocznij)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	init = SettingsContainer::getInstance().initsButtonFront();
	mainmenu[static_cast<int>(MenuScreen::Wyjdz)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

}

MainScreen* MainScreen::getInstance(double mywidth, double myheight)
{
		static MainScreen* single = new MainScreen(mywidth, myheight);
		return single;
}

UIState MainScreen::manageMouse(Vector2f mousepos)
{
	UIState toReturn = UIState::Main;
	if (mainmenu[static_cast<int>(MenuScreen::Rozpocznij)]->contains(mousepos))
	{
		toReturn = UIState::Begin;
	}
	else if (mainmenu[static_cast<int>(MenuScreen::Wyjdz)]->contains(mousepos))
	{
		toReturn = UIState::Wyjdz;
	}
	return toReturn;
}

void MainScreen::manageKeyboard(sf::Uint32 entered)
{
}

void MainScreen::draw(RenderTarget& target, RenderStates states)
{
	for (auto iter : mainmenu)
	{
		iter->draw(target, states);
	}
}

MainScreen::~MainScreen()
{
	for (auto a : mainmenu)
		delete a;
}

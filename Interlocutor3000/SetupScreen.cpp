#include "SetupScreen.h"

SetupScreen::SetupScreen(double mywidth, double myheight):Screen(mywidth, myheight)
{
	SettingsContainer::getInstance().readButtonInitializationFile("SetupScreenDimensions.txt");
	ButtonInitializer init = SettingsContainer::getInstance().initsButtonFront();
	setupscreen[static_cast<int>(Setup::Wpisywanie)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	init = SettingsContainer::getInstance().initsButtonFront();
	setupscreen[static_cast<int>(Setup::Rozpocznij)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty },Text::Style::Regular,
		Text::Style::Regular, 3.0, Color::Black);

	init = SettingsContainer::getInstance().initsButtonFront();
	setupscreen[static_cast<int>(Setup::Powrot)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty },Text::Style::Regular,
		Text::Style::Regular, 3.0, Color::Black);
}
SetupScreen* SetupScreen::getInstance(double mywidth, double myheight)
{
	static SetupScreen* single = new SetupScreen(mywidth, myheight);
	return single;
}
UIState SetupScreen::manageMouse(Vector2f mousepos)
{
	UIState toReturn = UIState::Setup;
	if (setupscreen[static_cast<int>(Setup::Wpisywanie)]->contains(mousepos))
	{
		setupscreen[static_cast<int>(Setup::Wpisywanie)]->activate();
		toReturn = UIState::Setup;
	}
	else if (setupscreen[static_cast<int>(Setup::Rozpocznij)]->contains(mousepos))
	{
		setupscreen[static_cast<int>(Setup::Rozpocznij)]->activate();
		setupscreen[static_cast<int>(Setup::Wpisywanie)]->reset();
		toReturn = UIState::Chat;
	}
	else if (setupscreen[static_cast<int>(Setup::Powrot)]->contains(mousepos))
	{
		setupscreen[static_cast<int>(Setup::Powrot)]->activate();
		setupscreen[static_cast<int>(Setup::Wpisywanie)]->reset();
		toReturn = UIState::Begin;
	}
	return toReturn;
}

void SetupScreen::manageKeyboard(sf::Uint32 entered)
{
	setupscreen[static_cast<int>(Setup::Wpisywanie)]->modifyText(entered);
	SettingsContainer::getInstance().setUsername(setupscreen[static_cast<int>(Setup::Wpisywanie)]->getMyString());
	SettingsContainer::getInstance().setBotname("Bot");
}

void SetupScreen::draw(RenderTarget& target, RenderStates states)
{
		setupscreen[static_cast<int>(Setup::Wpisywanie)]->draw(target, states);
		setupscreen[static_cast<int>(Setup::Rozpocznij)]->draw(target, states);
		setupscreen[static_cast<int>(Setup::Powrot)]->draw(target, states);
}

SetupScreen::~SetupScreen()
{
	for (auto s : setupscreen)
		delete s;
}

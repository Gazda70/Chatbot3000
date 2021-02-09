#include "BeginScreen.h"

BeginScreen::BeginScreen(double mywidth, double myheight, ConvoManager* manager) :Screen(mywidth, myheight)
{
	SettingsContainer::getInstance().readButtonInitializationFile("BeginScreenDimensions.txt");
	ButtonInitializer init = SettingsContainer::getInstance().initsButtonFront();
	beginscreen[static_cast<int>(Begin::RozpocznijNowa)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	init = SettingsContainer::getInstance().initsButtonFront();
	beginscreen[static_cast<int>(Begin::WrocDoPoprzedniej)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	init = SettingsContainer::getInstance().initsButtonFront();
	beginscreen[static_cast<int>(Begin::WrocDoMenu)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });
	myManager = manager;
}

BeginScreen* BeginScreen::getInstance(double mywidth, double myheight, ConvoManager* manager)
{
	 static BeginScreen* single = new BeginScreen(mywidth, myheight, manager);
	 return single;
}

UIState BeginScreen::manageMouse(Vector2f mousepos)
{
	UIState toReturn = UIState::Begin;
	if (beginscreen[static_cast<int>(Begin::RozpocznijNowa)]->contains(mousepos))
	{
		toReturn = UIState::Setup;
	}
	else if (beginscreen[static_cast<int>(Begin::WrocDoPoprzedniej)]->contains(mousepos))
	{
		myManager->reloadConv();
		myManager->setPrevious(true);
		toReturn = UIState::Chat;
	}
	else if (beginscreen[static_cast<int>(Begin::WrocDoMenu)]->contains(mousepos))
	{
		toReturn = UIState::Main;
	}
	return toReturn;
}

void BeginScreen::manageKeyboard(sf::Uint32 entered)
{
}
void BeginScreen::draw(RenderTarget& target, RenderStates states)
{
	for (auto iter : beginscreen)
	{
		iter->draw(target, states);
	}
}

BeginScreen::~BeginScreen()
{
	for (auto a : beginscreen)
		delete a;
	delete myManager;
}

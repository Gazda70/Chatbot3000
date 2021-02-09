#include "UI.h"

UI::UI(RenderWindow& window):myWindow(window), actual(UIState::Main), event(sf::Event())
{
    setConvLogic("Baza.csv");
	double width =static_cast<double>(window.getSize().x);
	double height = static_cast<double>(window.getSize().y);
    SettingsContainer::getInstance().setFont("times.ttf");
    SettingsContainer::getInstance().setSessionFile("Session.csv");
	screens[static_cast<int>(UIState::Main)] = MainScreen::getInstance(width, height);
	screens[static_cast<int>(UIState::Begin)] = BeginScreen::getInstance(width, height, myManager);
	screens[static_cast<int>(UIState::Setup)] = SetupScreen::getInstance(width, height);
	screens[static_cast<int>(UIState::Chat)] = ChatScreen::getInstance(width, height, myWindow, myManager);
}

void UI::eventsLoop()
{
    while (myWindow.isOpen())
    {
        while (myWindow.pollEvent(event))
        {
            manageEvents();
        }
        myWindow.clear(Color::White);
        draw();
        myWindow.display();
    }

}

void UI::manageEvents()
{
    switch (event.type)
    {
        case sf::Event::Closed:
            myWindow.close();
            break;

        case sf::Event::MouseButtonPressed:
            manageMouse(myWindow.mapPixelToCoords(Mouse::getPosition(myWindow)));
            break;

        case sf::Event::TextEntered:
            manageKeyboard(event.text.unicode);
            break;
        case sf::Event::MouseWheelScrolled:
            manageScroll(event.mouseWheelScroll.delta);
            break;

    }
}

void UI::manageMouse(Vector2f mousepos)
{
	changeState(screens[static_cast<int>(actual)]->manageMouse(mousepos));
}

void UI::manageKeyboard(sf::Uint32 entered)
{
	screens[static_cast<int>(actual)]->manageKeyboard(entered);
}

void UI::manageScroll(float delta)
{
    screens[static_cast<int>(actual)]->manageScroll(delta);
}

void UI::changeState(UIState newest)
{
	this->actual = newest;
}

void UI::draw()
{
	if (actual != UIState::Wyjdz)
	{
		screens[static_cast<int>(actual)]->draw(myWindow, RenderStates::Default);
	}
	else
	{
		myWindow.close();
	}
}

void UI::setConvLogic(const char* filename)
{
    myManager = new ConvoManager();
    myManager->trainBot(filename);
    myManager->printBase();
}

UI::~UI()
{
    delete screens[0];
    delete screens[1];
    delete screens[2];
    delete screens[3];
    delete myManager;
}



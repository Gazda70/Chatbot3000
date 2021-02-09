#include "ChatScreen.h"

ChatScreen::ChatScreen(double mywidth, double myheight, RenderTarget& target, ConvoManager* manager):Screen(mywidth, myheight), myTarget(target)
{
	SettingsContainer::getInstance().readButtonInitializationFile("ChatScreenDimensions.txt");
	ButtonInitializer init = SettingsContainer::getInstance().initsButtonFront();
	chatscreen[static_cast<int>(Chat::Wpisywanie)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	init = SettingsContainer::getInstance().initsButtonFront();
	chatscreen[static_cast<int>(Chat::Wysylanie)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	init = SettingsContainer::getInstance().initsButtonFront();
	chatscreen[static_cast<int>(Chat::Powrot)] = new Button(width * init.x, height * init.y, width * init.w,
		height * init.h, init.color, init.name, init.font, height * init.textsize, init.textcolor, { init.textx, init.texty });

	SettingsContainer::getInstance().readFieldInitializationFile("FieldDimensions.txt");
	FieldInitializer init2 = SettingsContainer::getInstance().initsFieldFront();
	myField = new ConversationField(width * init2.x_axis, height * init2.y_axis, width * init2.width, height * init2.height, init2.color);
	fieldView.reset(FloatRect({ float(width * init2.x_axis), float(height * init2.y_axis) }, { float(width * init2.width), float(height * init2.height) }));
	fieldView.setViewport(sf::FloatRect(init2.vx, init2.vy, init2.vw, init2.vh));
	myManager = manager;
	activeSession = false;
}


void ChatScreen::setSession(vector<pair<string, string>>& toSet)
{
	myManager->setSessionContent(toSet);
}

void ChatScreen::sendMessage(std::string msg)
{
	actualMessage = msg;
	actualResponse = myManager->sendMessage(msg);
}

UIState ChatScreen::manageMouse(Vector2f mousepos)
{
	UIState toReturn = UIState::Chat;
	if (chatscreen[static_cast<int>(Chat::Wpisywanie)]->contains(mousepos))
	{
		chatscreen[static_cast<int>(Chat::Wpisywanie)]->activate();
		toReturn = UIState::Chat;
	}
	else if (chatscreen[static_cast<int>(Chat::Wysylanie)]->contains(mousepos))
	{
		chatscreen[static_cast<int>(Chat::Wysylanie)]->activate();
		if (activeSession == false)
		{
			activeSession = true;
			myManager->startSession();
		}
		if (chatscreen[static_cast<int>(Chat::Wpisywanie)]->checkIfEntered())
		{
			sendMessage(chatscreen[static_cast<int>(Chat::Wpisywanie)]->getMyString());
			actualizeField();
		}
		chatscreen[static_cast<int>(Chat::Wpisywanie)]->reset();
	}
	else if (chatscreen[static_cast<int>(Chat::Powrot)]->contains(mousepos))
	{
		toReturn = UIState::Setup;
		resetField();
		activeSession = true;
		myManager->saveConv();
		myManager->endSession();
	}
	return toReturn;
}

void ChatScreen::manageKeyboard(sf::Uint32 entered)
{
	chatscreen[static_cast<int>(Chat::Wpisywanie)]->modifyText(entered);
}

void ChatScreen::manageScroll(float delta)
{
	myField->scrollView(delta, fieldView);
}
void ChatScreen::actualizeField()
{

	if (!actualMessage.empty())
	{
		myField->setUserAvatar(actualMessage, "UserAvatar.png");
	}
	if (!actualResponse.empty())
	{
		myField->setBotAvatar(actualResponse, "BotAvatar.png");
	}
}

void ChatScreen::resetConv()
{
	for (vector<pair<string, string>>::iterator iter = myManager->getSession().begin(); iter != myManager->getSession().end(); ++iter)
	{
		myField->setUserAvatar(iter->first, "UserAvatar.png");
		myField->setBotAvatar(iter->second, "BotAvatar.png");
	}
}

void ChatScreen::resetField()
{
	myField->reset();
	chatscreen[static_cast<int>(Chat::Wpisywanie)]->reset();
}

ChatScreen* ChatScreen::getInstance(double mywidth, double myheight, RenderTarget& target, ConvoManager* manager)
{
	static ChatScreen* single = new ChatScreen(mywidth, myheight, target, manager);
	return single;
}

void ChatScreen::draw(RenderTarget& target, RenderStates states)
{
	myTarget.setView(fieldView);
	if (myManager->isPrevious())
	{
		resetConv();
		myManager->setPrevious(false);
	}
	myTarget.draw(myField->drawField());
	myTarget.setView(myTarget.getDefaultView());
	chatscreen[static_cast<int>(Chat::Wpisywanie)]->draw(myTarget, states);
	chatscreen[static_cast<int>(Chat::Wysylanie)]->draw(myTarget, states);
	chatscreen[static_cast<int>(Chat::Powrot)]->draw(myTarget, states);
}

ChatScreen::~ChatScreen()
{
	for (auto a : chatscreen)
		delete a;
	delete myField;
	delete myManager;
}

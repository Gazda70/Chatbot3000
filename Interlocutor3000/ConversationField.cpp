#include "ConversationField.h"

ConversationField::ConversationField(float x_axis, float y_axis, float width, float height, 
	Color color)
{
	SettingsContainer::getInstance().readAvatarInitializationFile("AvatarConfigurationFile.txt");
	init = SettingsContainer::getInstance().initsAvatarFront();
	fieldX = width;
	fieldY = height;
	field = new RenderTexture();
	field->create(width, height * 5);
	scrollOffset = 0.0;
	username = SettingsContainer::getInstance().getUsername();
	botname = SettingsContainer::getInstance().getBotname();
}

void ConversationField::setUserAvatar(std::string usersaid, const char* avatarTexture)
{
	SettingsContainer::getInstance().readAvatarInitializationFile("AvatarConfigurationFile.txt");
	init = SettingsContainer::getInstance().initsAvatarFront();
	Vector2f userpos = getAvatarCoords(Interlocutors::Uzytkownik);
	userpos.y += float(float(userInstances.size()) * 350.0);
	Avatar* instance = new Avatar(userpos, avatarTexture,SettingsContainer::getInstance().getUsername());
	Vector2f balloonPos = { float(userpos.x - init.balluserx),float(userpos.y - init.ballusery)};
	instance->setBalloon(balloonPos, usersaid,"RightSpeechBalloon.png");
	userInstances.push_back(instance);
}

void ConversationField::setBotAvatar(std::string botsaid, const char* avatarTexture)
{
	SettingsContainer::getInstance().readAvatarInitializationFile("AvatarConfigurationFile.txt");
	init = SettingsContainer::getInstance().initsAvatarFront();
	Vector2f botpos = getAvatarCoords(Interlocutors::Bot);
	botpos.y += float(float(botInstances.size()) * 350.0);
	Avatar* instance = new Avatar(botpos, avatarTexture, SettingsContainer::getInstance().getBotname());
	Vector2f balloonPos = { float(botpos.x + init.ballbotx),float(botpos.y  - init.ballboty)};
	instance->setBalloon(balloonPos, botsaid, "LeftSpeechBalloon.png");
	botInstances.push_back(instance);
}

Vector2f ConversationField::getAvatarCoords(Interlocutors need)
{
	Vector2f toReturn;
		if (need == Interlocutors::Uzytkownik)
			toReturn = { float(fieldX * init.userx), float(fieldY * init.usery) };
		else if (need == Interlocutors::Bot)
			toReturn = { float(fieldX * init.botx), float(fieldY * init.boty)};
	return toReturn;
}

void ConversationField::scrollView(float delta, sf::View& myView)
{
	myView.move({0, delta * 10});
	scrollOffset += delta;
}


void ConversationField::reset()
{
	userInstances.clear();
	botInstances.clear();
}

void ConversationField::drawAvatars() const
{
	for(auto instance: userInstances)
		instance->draw(*field, RenderStates::Default);
	for (auto instance : botInstances)
		instance->draw(*field, RenderStates::Default);
}


sf::Sprite ConversationField::drawField()
{
	field->clear(Color::Yellow);
	drawAvatars();
	field -> display();
	const sf::Texture& texture = field->getTexture();
	sf::Sprite sprite(texture);
	return sprite;
}

ConversationField::~ConversationField()
{
	for (auto av : userInstances)
		delete av;
	for (auto av : botInstances)
		delete av;
	delete field;
}

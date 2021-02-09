#include "Avatar.h"

Avatar::Avatar(sf::Vector2f location, const char* textFile, std::string name)
{
	SettingsContainer::getInstance().readAvatarInitializationFile("AvatarConfigurationFile.txt");
	AvatarInitializer init = SettingsContainer::getInstance().initsAvatarFront();
	if (!texture.loadFromFile(textFile))
	{
		std::cout << "Nie znaleziono pliku" << std::endl;
	}
	myLook.setTexture(texture);
	myLook.setPosition(location);
	myName.setString(sf::String(name));
	myName.setFillColor(sf::Color::Black);
	myName.setFont(SettingsContainer::getInstance().getFont());
	myName.setCharacterSize(init.charsize);
	myName.setPosition(location + sf::Vector2f{ myLook.getGlobalBounds().width * init.posx,myLook.getGlobalBounds().height * init.posy});
	avatar_balloon = nullptr;
}

void Avatar::setBalloon(sf::Vector2f position, std::string mySpeech, const char* textureFile)
{
	avatar_balloon = new SpeechBalloon(position, mySpeech, textureFile);
}

void Avatar::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(myLook);
	target.draw(myName);
	avatar_balloon->draw(target, state);
}

Avatar::~Avatar()
{
	delete avatar_balloon;
}

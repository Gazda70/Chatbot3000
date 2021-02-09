#include "SpeechBalloon.h"


SpeechBalloon::SpeechBalloon(Vector2f position, sf::String mySpeech, const char* textFile)
{
	SettingsContainer::getInstance().readSpeechBalloonInitializationFile("SpeechBalloonSettings.txt");
	SpeechBalloonInitializer init = SettingsContainer::getInstance().initsSPFront();
	if (balloonTexture.loadFromFile(textFile))
	{
		balloonSprite.setTexture(balloonTexture);
		balloonSprite.setPosition(position);
		parent = FloatRect(position, Vector2f{init.parentx, init.parenty});
		textfieldActive = true;
		myFont.loadFromFile("times.ttf");
		myText.setFont(myFont);
		myText.setCharacterSize(parent.height * init.charsize);
		myText.setFillColor(Color::Black);	
		myText.setPosition(position.x + parent.width * init.posx, position.y + parent.height * init.posy);
	    fillBalloon(mySpeech, myText.getPosition());
	}
}
void SpeechBalloon::fillBalloon(sf::String written, sf::Vector2f startPos)
{
	for (auto letter : written)
		addTextInRange(letter);
}

void SpeechBalloon::draw(RenderTarget& window, RenderStates state) const
{
	window.draw(balloonSprite);
	window.draw(myText);
}

#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ContainText.h"
#include "SettingsContainer.h"

/**
* Enum do odró¿niania czy
* dany dymek jest lewo- czu prawostronny
*/
enum class Dir
{
	Left, Right
};

/**
* Klasa reprezentuj¹ca dymek czatu
*/
class SpeechBalloon : public ContainText
{
	/**
	* Tekstura dymku
	*/
	sf::Texture balloonTexture;

	/**
	* Obiekt klasy sprite bêd¹cy
	* graficzn¹ reprezentacj¹ dymku
	*/
	sf::Sprite balloonSprite;
public:

	/**
	* Konstruktor
	* @param position pozycja dymku
	* @param mySpeech tekst do wyœwietlenia w dymku
	* @param nazwa pliku z tekstur¹
	*/
	SpeechBalloon(sf::Vector2f position,sf::String mySpeech, const char* textureFile);

	/**
	* fillBallooon
	* @param written tekst do wyœwietlenia w dymku
	* @param startPos pozycja pocz¹tkowa tekstu
	*/
	void fillBalloon(sf::String written, sf::Vector2f startPos);

	/**
	* Metoda s³u¿ac¹ do wyrysowania obiektu
	* @param target obiekt na którym ma byæ narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(sf::RenderTarget& window, sf::RenderStates state)const;
};
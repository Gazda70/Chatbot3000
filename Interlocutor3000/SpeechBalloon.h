#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ContainText.h"
#include "SettingsContainer.h"

/**
* Enum do odr�niania czy
* dany dymek jest lewo- czu prawostronny
*/
enum class Dir
{
	Left, Right
};

/**
* Klasa reprezentuj�ca dymek czatu
*/
class SpeechBalloon : public ContainText
{
	/**
	* Tekstura dymku
	*/
	sf::Texture balloonTexture;

	/**
	* Obiekt klasy sprite b�d�cy
	* graficzn� reprezentacj� dymku
	*/
	sf::Sprite balloonSprite;
public:

	/**
	* Konstruktor
	* @param position pozycja dymku
	* @param mySpeech tekst do wy�wietlenia w dymku
	* @param nazwa pliku z tekstur�
	*/
	SpeechBalloon(sf::Vector2f position,sf::String mySpeech, const char* textureFile);

	/**
	* fillBallooon
	* @param written tekst do wy�wietlenia w dymku
	* @param startPos pozycja pocz�tkowa tekstu
	*/
	void fillBalloon(sf::String written, sf::Vector2f startPos);

	/**
	* Metoda s�u�ac� do wyrysowania obiektu
	* @param target obiekt na kt�rym ma by� narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(sf::RenderTarget& window, sf::RenderStates state)const;
};
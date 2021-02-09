#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SpeechBalloon.h"
#include "SettingsContainer.h"
#include <iostream>

/**
* Klasa reprezentuj¹ca awatary u¿ywane w konwersacji przez
* program i u¿ytkownika
*/

class Avatar
{
	/**
	* Obiekt klasy SpeechBallon reprezentuj¹cy dymek tekstu
	* w którym wyœwietlane s¹ wiadomoœci
	*/
	SpeechBalloon* avatar_balloon;
	sf::Texture texture;/**< Tekstura okreœlaj¹ca wygl¹d awatara */
	sf::Sprite myLook;/**< Sprite okreœlaj¹cy wygl¹d awatara */
	sf::Text myName;/**< Nazwa awatara */
public:
	/**
	* Konstruktor
	* @param location wektor okreœlaj¹cy po³o¿enie awatara 
	* @param textFile plik tekstury która ma byæ u¿yta dla danej instancji
	* @param name nazwa parametru
	*/
	Avatar(sf::Vector2f location, const char* textFile, std::string name);

	/**
	* Metoda s³u¿¹ca do ustawienia dymku tekstu
	* @param position wektor okreœlaj¹cy po³o¿enie dymku
	* @param mySpeech ³añcuch znaków reprezentuj¹cy informacjê maj¹c¹ byæ wyœwietlon¹ w dymku
	* @param textureFile nazwa pliku tekstury okreœlaj¹cej wygl¹d dymku
	*/
	void setBalloon(sf::Vector2f position, std::string mySpeech, const char* textureFile);

	/**
	* Metoda s³u¿ac¹ do wyrysowania obiektu
	* @param target obiekt na którym ma byæ narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates state)const;

	/**
	* Destruktor odpowiadaj¹cy za zwolnienie dynamicznie zaalokowanej pamiêci
	*/
	~Avatar();
};
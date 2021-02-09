#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "SpeechBalloon.h"
#include "SettingsContainer.h"
#include <iostream>

/**
* Klasa reprezentuj�ca awatary u�ywane w konwersacji przez
* program i u�ytkownika
*/

class Avatar
{
	/**
	* Obiekt klasy SpeechBallon reprezentuj�cy dymek tekstu
	* w kt�rym wy�wietlane s� wiadomo�ci
	*/
	SpeechBalloon* avatar_balloon;
	sf::Texture texture;/**< Tekstura okre�laj�ca wygl�d awatara */
	sf::Sprite myLook;/**< Sprite okre�laj�cy wygl�d awatara */
	sf::Text myName;/**< Nazwa awatara */
public:
	/**
	* Konstruktor
	* @param location wektor okre�laj�cy po�o�enie awatara 
	* @param textFile plik tekstury kt�ra ma by� u�yta dla danej instancji
	* @param name nazwa parametru
	*/
	Avatar(sf::Vector2f location, const char* textFile, std::string name);

	/**
	* Metoda s�u��ca do ustawienia dymku tekstu
	* @param position wektor okre�laj�cy po�o�enie dymku
	* @param mySpeech �a�cuch znak�w reprezentuj�cy informacj� maj�c� by� wy�wietlon� w dymku
	* @param textureFile nazwa pliku tekstury okre�laj�cej wygl�d dymku
	*/
	void setBalloon(sf::Vector2f position, std::string mySpeech, const char* textureFile);

	/**
	* Metoda s�u�ac� do wyrysowania obiektu
	* @param target obiekt na kt�rym ma by� narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates state)const;

	/**
	* Destruktor odpowiadaj�cy za zwolnienie dynamicznie zaalokowanej pami�ci
	*/
	~Avatar();
};
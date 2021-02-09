#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Button.h"
#include "SettingsContainer.h"

using namespace sf;
/**
* Enum do rozr�niania pomi�dzy stanami interfejsu
*/
enum class UIState
{
	Main, Begin, Setup, Ustawienia, Chat, Wyjdz
};

/**
* Klasa abstrakcyjna zapewniaj�ca interfejs do obs�ugi 
* scen interfejsu
*/
class Screen
{
protected:

	/**
	* Szeroko�� sceny
	*/
	double width;

	/**
	* Wysoko�� sceny
	*/
	double height;
public: 
	/**
	* Konstruktor bezargumentowy
	*/
	Screen() :width(1600.0), height(900.0) {};

	/**
	* Konstruktor 
	* @param mywidth szeroko�� sceny
	*/
	Screen(double mywidth, double myheight):width(mywidth), height(myheight) {};

	/**
	* Wirtualna metoda do obs�ugi myszki - naci�niecie klawisza
	* @param mousepos po�o�enie myszki
	* @return stan interfejsu wynikaj�cy z po�o�enia myszki przy klikni�ciu
	*/
	virtual UIState manageMouse(sf::Vector2f mousepos) = 0;

	/**
	* Wirtualna metoda do obs�ugi klawiatury
	* @param entered kod wci�ni�tego klawisza
	*/
	virtual void manageKeyboard(sf::Uint32 entered) = 0;

	/**
	* Wirtualna metoda do obs�ugi myszki - naci�niecie klawisza
	* @param delta przesuni�cie widoku
	*/
	virtual void manageScroll(float delta) = 0;

	/**
	* Metoda s�u�ac� do wyrysowania obiektu
	* @param target obiekt na kt�rym ma by� narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;


	virtual ~Screen();/**< wirtualny destruktor*/
};
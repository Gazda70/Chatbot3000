#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Button.h"
#include "SettingsContainer.h"

using namespace sf;
/**
* Enum do rozró¿niania pomiêdzy stanami interfejsu
*/
enum class UIState
{
	Main, Begin, Setup, Ustawienia, Chat, Wyjdz
};

/**
* Klasa abstrakcyjna zapewniaj¹ca interfejs do obs³ugi 
* scen interfejsu
*/
class Screen
{
protected:

	/**
	* Szerokoœæ sceny
	*/
	double width;

	/**
	* Wysokoœæ sceny
	*/
	double height;
public: 
	/**
	* Konstruktor bezargumentowy
	*/
	Screen() :width(1600.0), height(900.0) {};

	/**
	* Konstruktor 
	* @param mywidth szerokoœæ sceny
	*/
	Screen(double mywidth, double myheight):width(mywidth), height(myheight) {};

	/**
	* Wirtualna metoda do obs³ugi myszki - naciœniecie klawisza
	* @param mousepos po³o¿enie myszki
	* @return stan interfejsu wynikaj¹cy z po³o¿enia myszki przy klikniêciu
	*/
	virtual UIState manageMouse(sf::Vector2f mousepos) = 0;

	/**
	* Wirtualna metoda do obs³ugi klawiatury
	* @param entered kod wciœniêtego klawisza
	*/
	virtual void manageKeyboard(sf::Uint32 entered) = 0;

	/**
	* Wirtualna metoda do obs³ugi myszki - naciœniecie klawisza
	* @param delta przesuniêcie widoku
	*/
	virtual void manageScroll(float delta) = 0;

	/**
	* Metoda s³u¿ac¹ do wyrysowania obiektu
	* @param target obiekt na którym ma byæ narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) = 0;


	virtual ~Screen();/**< wirtualny destruktor*/
};
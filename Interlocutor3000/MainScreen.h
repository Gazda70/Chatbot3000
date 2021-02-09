#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Screen.h"

/**
* Enum do rozró¿niania elementów interfejsu w tablicy
*/
enum class MenuScreen
{
	Tytul, Rozpocznij, Wyjdz
};

/**
* Klasa-singleton do utworzenia i obs³ugi pocz¹tkowej sceny interfejsu
*/
class MainScreen:public Screen
{
private:

	/**
	* Tablica do przechowywania elementów interfejsu
	*/
	Button* mainmenu[3];

	/**
	* Konstruktor
	* @param mywidth szerokoœæ
	* @param myheight wysokoœæ
	*/
	MainScreen(double mywidth, double myheight);
public:

	/**
	* Metoda do uzyskiwania dostêpu do instancji
	* @param mywidth szerokoœæ
	* @param myheight wysokoœæ
	*/
	static MainScreen* getInstance(double mywidth, double myheight);

	/**
	* Metoda do obs³ugi myszki - naciœniecie klawisza
	* @param mousepos po³o¿enie myszki
	* @return stan interfejsu wynikaj¹cy z po³o¿enia myszki przy klikniêciu
	*/
	UIState manageMouse(Vector2f mousepos)override;

	/**
	* Metoda do obs³ugi klawiatury
	* @param entered kod wciœniêtego klawisza
	*/
	void manageKeyboard(sf::Uint32 entered)override;

	/**
	* Metoda do obs³ugi myszki - u¿ycie ko³a myszki
	* @param delta przesuniêcie widoku
	*/
	void manageScroll(float delta) {};

	/**
	* Metoda s³u¿ac¹ do wyrysowania obiektu
	* @param target obiekt na którym ma byæ narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(RenderTarget& target, RenderStates states);

	/**
	* Destruktor, zwalnia zaalokowan¹ dynamicznie pamiêæ
	*/
	~MainScreen();
};
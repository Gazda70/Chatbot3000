#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "SettingsContainer.h"

/**
* Enum do rozr�niania element�w interfejsu w tablicy
*/
enum class Setup
{
	Wpisywanie, Rozpocznij, Powrot
};

/**
* Klasa do utworzenia i obs�ugi  sceny interfejsu
* z wyborem nazwy u�ytkownika
*/
class SetupScreen : public Screen
{
private:

	/**
	* Tablica do przechowywania element�w interfejsu
	*/
	Button* setupscreen[3];

	/**
	* Konstruktor
	* @param mywidth szeroko��
	* @param myheight wysoko��
	*/
	SetupScreen(double mywidth, double myheight);
public:

	/**
	* Metoda do uzyskiwania dost�pu do instancji
	* @param mywidth szeroko��
	* @param myheight wysoko��
	*/
	static SetupScreen* getInstance(double mywidth, double myheight);

	/**
	* Metoda do obs�ugi myszki - naci�niecie klawisza
	* @param mousepos po�o�enie myszki
	* @return stan interfejsu wynikaj�cy z po�o�enia myszki przy klikni�ciu
	*/
	UIState manageMouse(Vector2f mousepos)override;

	/**
	* Metoda do obs�ugi klawiatury
	* @param entered kod wci�ni�tego klawisza
	*/
	void manageKeyboard(sf::Uint32 entered)override;

	/**
	* Metoda do obs�ugi myszki - u�ycie ko�a myszki
	* @param delta przesuni�cie widoku
	*/
	void manageScroll(float delta) {};

	/**
	* Metoda s�u�ac� do wyrysowania obiektu
	* @param target obiekt na kt�rym ma by� narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(RenderTarget& target, RenderStates states);

	/**
	* Destruktor, zwalnia zaalokowan� dynamicznie pami��
	*/
	~SetupScreen();
};
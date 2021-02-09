#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "ConvoManager.h"
using namespace sf;

/**
* Klasa enum odpowiadaj�ca za rozr�nianie pomi�dzy elementami interfejsu w BeginScreen
*/
enum class Begin
{
	RozpocznijNowa, WrocDoPoprzedniej, WrocDoMenu
};

/**
* Klasa-singleton reprezentuj�ca fragment interfejsu umo�liwiaj�cy wyb�r
* czy u�ytkownik chce powr�ci� do poprzedniej konwersacji czy rozpocza� kolejn�
*/
class BeginScreen : public Screen
{
private:
	/**
	* Tablica obiekt�w klasy Button tworz�cych przyciski widoczne na ekranie
	*/
	Button* beginscreen[3];
	/**
	* Wska�nik na obiekt klasy obsluguj�cej konwersacj�, konieczny przy decyzji czy rozpocz��
	* kolejn� konwersacj� czy wr�ci� do poprzedniej
	*/
	ConvoManager* myManager;
	/**
	* Konstruktor
	* @param mywidth szeroko�� sceny
	* @param myheight wysoko�� sceny
	* @param wska�nik na mened�era konwersacji
	*/
	BeginScreen(double mywidth, double myheight, ConvoManager* manager);

public:
	/**
	* metoda umo�liwiaj�ca dost�p do instancji klasy
	*/
	static BeginScreen* getInstance(double mywidth, double myheight, ConvoManager* manager);

	/**
	* metoda do obs�ugi informacji z myszki - wci�ni�cie klawisza
	* @param mousepos po�o�enie myszki w momencie naci�ni�cia klawisza
	*/
	UIState manageMouse(Vector2f mousepos);

	/**
	* metoda do obs�ugi informacji z klawiatury
	* @param entered kod znaku klawisza wci�ni�tego na klawiaturze
	*/
	void manageKeyboard(sf::Uint32 entered);

	/**
	* metoda do obs�ugi informacji z myszki - u�ycie ko�a myszki
	* @param delta odleg�o�� o jak� powinien si� przesun�� widok
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
	~BeginScreen();
};
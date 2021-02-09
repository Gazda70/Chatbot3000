#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "ConvoManager.h"
using namespace sf;

/**
* Klasa enum odpowiadaj¹ca za rozró¿nianie pomiêdzy elementami interfejsu w BeginScreen
*/
enum class Begin
{
	RozpocznijNowa, WrocDoPoprzedniej, WrocDoMenu
};

/**
* Klasa-singleton reprezentuj¹ca fragment interfejsu umo¿liwiaj¹cy wybór
* czy u¿ytkownik chce powróciæ do poprzedniej konwersacji czy rozpoczaæ kolejn¹
*/
class BeginScreen : public Screen
{
private:
	/**
	* Tablica obiektów klasy Button tworz¹cych przyciski widoczne na ekranie
	*/
	Button* beginscreen[3];
	/**
	* WskaŸnik na obiekt klasy obsluguj¹cej konwersacjê, konieczny przy decyzji czy rozpocz¹æ
	* kolejn¹ konwersacjê czy wróciæ do poprzedniej
	*/
	ConvoManager* myManager;
	/**
	* Konstruktor
	* @param mywidth szerokoœæ sceny
	* @param myheight wysokoœæ sceny
	* @param wskaŸnik na mened¿era konwersacji
	*/
	BeginScreen(double mywidth, double myheight, ConvoManager* manager);

public:
	/**
	* metoda umo¿liwiaj¹ca dostêp do instancji klasy
	*/
	static BeginScreen* getInstance(double mywidth, double myheight, ConvoManager* manager);

	/**
	* metoda do obs³ugi informacji z myszki - wciœniêcie klawisza
	* @param mousepos po³o¿enie myszki w momencie naciœniêcia klawisza
	*/
	UIState manageMouse(Vector2f mousepos);

	/**
	* metoda do obs³ugi informacji z klawiatury
	* @param entered kod znaku klawisza wciœniêtego na klawiaturze
	*/
	void manageKeyboard(sf::Uint32 entered);

	/**
	* metoda do obs³ugi informacji z myszki - u¿ycie ko³a myszki
	* @param delta odleg³oœæ o jak¹ powinien siê przesun¹æ widok
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
	~BeginScreen();
};
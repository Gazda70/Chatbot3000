#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Button.h"
#include "Screen.h"
#include "MainScreen.h"
#include "BeginScreen.h"
#include "SetupScreen.h"
#include "ChatScreen.h"
#include "SettingsContainer.h"

/**
* Klasa reprezentuj�ca interfejs graficzny
* "zarz�dca interfejsu"
*/
class UI
{
private:

	/**
	* Aktualny stan interfejsu
	*/
	UIState actual;

	/**
	* Obiekt kalsy Event
	* do obs�ugi zdarze� wywo�anych przez u�ytkownika
	*/
	sf::Event event;

	/**
	* Tablica wska�nik�w na wirtualn� klas�
	* reprezentujac� scen� interfejsu
	*/
	Screen* screens [5];

	/**
	* Wska�nik na zarz�dc� konwersacji
	*/
	ConvoManager* myManager;

	/**
	* Referencja do okna wy�wietlania
	*/
	RenderWindow& myWindow;
public:

	/**
	* Konstruktor
	* @param window okno wy�wietlania
	*/
	UI(RenderWindow& window);

	/**
	* Metoda do obs�ugi zdarze� zwi�zanych z akcjami
	* u�ytkownika (mysz, klawiatura); g��wna p�tla programu
	*/
	void eventsLoop();

	/**
	* Metoda do decydowania jakiego rodzaju interakcj�
	* u�ytkownik podj�� z interfejsem
	*/
	void manageEvents();

	/**
	* Metoda do obs�ugi myszki - naci�niecie klawisza
	* @param mousepos po�o�enie myszki
	*/
	void manageMouse(Vector2f mousepos);

	/**
	* Metoda do obs�ugi klawiatury
	* @param entered kod wci�ni�tego klawisza
	*/
	void manageKeyboard(sf::Uint32 entered);

	/**
	* Metoda do obs�ugi myszki - u�ycie ko�a myszki
	* @param delta przesuni�cie widoku
	*/
	void manageScroll(float delta);

	/**
	* Metoda do zmiany aktualnego stanu interfejsu
	* @param newest nowo ustawiony stan
	*/
	void changeState(UIState newest);

	/**
	* Metoda do narysowania interfejus
	*/
	void draw();

	/**
	* Metoda do pobrania informacji potrzebnych do dzia�ania programu
	* i stworzenia stosownych obiekt�w
	*/
	void setConvLogic(const char* filename);

	/**
	* Destruktor, zwalnia zaalokowan� dynamicznie pami��
	*/
	~UI();
};
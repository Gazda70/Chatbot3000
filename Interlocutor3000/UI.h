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
* Klasa reprezentuj¹ca interfejs graficzny
* "zarz¹dca interfejsu"
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
	* do obs³ugi zdarzeñ wywo³anych przez u¿ytkownika
	*/
	sf::Event event;

	/**
	* Tablica wskaŸników na wirtualn¹ klasê
	* reprezentujac¹ scenê interfejsu
	*/
	Screen* screens [5];

	/**
	* WskaŸnik na zarz¹dcê konwersacji
	*/
	ConvoManager* myManager;

	/**
	* Referencja do okna wyœwietlania
	*/
	RenderWindow& myWindow;
public:

	/**
	* Konstruktor
	* @param window okno wyœwietlania
	*/
	UI(RenderWindow& window);

	/**
	* Metoda do obs³ugi zdarzeñ zwi¹zanych z akcjami
	* u¿ytkownika (mysz, klawiatura); g³ówna pêtla programu
	*/
	void eventsLoop();

	/**
	* Metoda do decydowania jakiego rodzaju interakcjê
	* u¿ytkownik podj¹³ z interfejsem
	*/
	void manageEvents();

	/**
	* Metoda do obs³ugi myszki - naciœniecie klawisza
	* @param mousepos po³o¿enie myszki
	*/
	void manageMouse(Vector2f mousepos);

	/**
	* Metoda do obs³ugi klawiatury
	* @param entered kod wciœniêtego klawisza
	*/
	void manageKeyboard(sf::Uint32 entered);

	/**
	* Metoda do obs³ugi myszki - u¿ycie ko³a myszki
	* @param delta przesuniêcie widoku
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
	* Metoda do pobrania informacji potrzebnych do dzia³ania programu
	* i stworzenia stosownych obiektów
	*/
	void setConvLogic(const char* filename);

	/**
	* Destruktor, zwalnia zaalokowan¹ dynamicznie pamiêæ
	*/
	~UI();
};
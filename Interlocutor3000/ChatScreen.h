#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "ConversationField.h"
#include "Avatar.h"
#include "ConvoManager.h"


/**
* Klasa enum odpowiadaj�ca za rozr�nianie pomi�dzy elementami interfejsu w ChatScreen
*/
enum class Chat
{
	Wpisywanie, Wysylanie, Powrot
};

/**
* Klasa-singleton odpowiadaj�ca za interfejs sceny wysy�ania wiadomo�ci
*/
class ChatScreen : public Screen
{
private:
	/**
	* Tablica z elementami interfejsu
	*/
	Button* chatscreen[3];

	/**
	* Pole na do wy�wietlania awatar�w i wiadomo�ci
	*/
	ConversationField* myField;

	/**
	* Obiekt na kt�ry dana klasa zostaje wyrysowana
	*/
	RenderTarget& myTarget;

	/**
	* Obiekt umo�liwiaj�cy przesuwanie widoku podczas scrollowania
	*/
	sf::View fieldView;

	/**
	* Mened�er konwersacji
	*/
	ConvoManager* myManager;

	/**
	* Informacja o znajdywaniu si� w trakcie aktywnej sesji
	*/
	bool activeSession;

	/**
	* Aktualnie przetwarzana informacja od u�ytkownika
	*/
	string actualMessage;
	/**
	* Aktualnie przetwarzana odpowied� programu
	*/
	string actualResponse;

	/**
	* Konstruktor
	* @param mywidth szeroko�� sceny
	* @param myheight wysoko�� sceny
	* @param target obiekt do narysowania sceny
	* @param manager mened�er konwersacji
	*/
	ChatScreen(double mywidth, double myheight, RenderTarget& target, ConvoManager* manager);
public:
	/**
	* Metoda do ustawienia aktualnej sesji rozmowy,
	* potrzebna przy wczytywaniu starej rozmowy z pliku
	* @param toSet wektor par wiadomo�� u�ytkownika-odpowied� programu
	*/
	void setSession(vector<pair<string, string>>& toSet);

	/**
	* Metoda do przesy�ania wiadomo�ci u�ytkownika 
	* @param msg wiadomo�� u�ytkownika
	*/
	void sendMessage(std::string msg);

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
	void manageScroll(float delta);

	/**
	* metoda do aktualizacji zawarto�ci pola konwersacji - ustawianie awatar�w
	*/
	void actualizeField();

	/**
	* metoda do resetu konwersacji - potrzebna przy �adowaniu konwersacji z pliku
	*/
	void resetConv();

	/**
	* metoda do resetu pola konwersacji konwersacji
	*/
	void resetField();

	/**
	* Metoda do otrzymania dost�pu do jedynej instancji klasy
	* @param mywidth szeroko�� sceny
	* @param myheight wysoko�� sceny
	* @param target obiekt do narysowania sceny
	* @param manager mened�er konwersacji
	*/
	static ChatScreen* getInstance(double mywidth, double myheight, RenderTarget& target, ConvoManager* manager);

	/**
	* Metoda s�u�ac� do wyrysowania obiektu
	* @param target obiekt na kt�rym ma by� narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(RenderTarget& target, RenderStates states);

	/**
	* Destruktor, zwalnia zaalokowan� dynamicznie pami��
	*/
	~ChatScreen();
};
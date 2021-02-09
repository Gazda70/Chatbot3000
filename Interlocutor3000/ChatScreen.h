#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Screen.h"
#include "ConversationField.h"
#include "Avatar.h"
#include "ConvoManager.h"


/**
* Klasa enum odpowiadaj¹ca za rozró¿nianie pomiêdzy elementami interfejsu w ChatScreen
*/
enum class Chat
{
	Wpisywanie, Wysylanie, Powrot
};

/**
* Klasa-singleton odpowiadaj¹ca za interfejs sceny wysy³ania wiadomoœci
*/
class ChatScreen : public Screen
{
private:
	/**
	* Tablica z elementami interfejsu
	*/
	Button* chatscreen[3];

	/**
	* Pole na do wyœwietlania awatarów i wiadomoœci
	*/
	ConversationField* myField;

	/**
	* Obiekt na który dana klasa zostaje wyrysowana
	*/
	RenderTarget& myTarget;

	/**
	* Obiekt umo¿liwiaj¹cy przesuwanie widoku podczas scrollowania
	*/
	sf::View fieldView;

	/**
	* Mened¿er konwersacji
	*/
	ConvoManager* myManager;

	/**
	* Informacja o znajdywaniu siê w trakcie aktywnej sesji
	*/
	bool activeSession;

	/**
	* Aktualnie przetwarzana informacja od u¿ytkownika
	*/
	string actualMessage;
	/**
	* Aktualnie przetwarzana odpowiedŸ programu
	*/
	string actualResponse;

	/**
	* Konstruktor
	* @param mywidth szerokoœæ sceny
	* @param myheight wysokoœæ sceny
	* @param target obiekt do narysowania sceny
	* @param manager mened¿er konwersacji
	*/
	ChatScreen(double mywidth, double myheight, RenderTarget& target, ConvoManager* manager);
public:
	/**
	* Metoda do ustawienia aktualnej sesji rozmowy,
	* potrzebna przy wczytywaniu starej rozmowy z pliku
	* @param toSet wektor par wiadomoœæ u¿ytkownika-odpowiedŸ programu
	*/
	void setSession(vector<pair<string, string>>& toSet);

	/**
	* Metoda do przesy³ania wiadomoœci u¿ytkownika 
	* @param msg wiadomoœæ u¿ytkownika
	*/
	void sendMessage(std::string msg);

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
	void manageScroll(float delta);

	/**
	* metoda do aktualizacji zawartoœci pola konwersacji - ustawianie awatarów
	*/
	void actualizeField();

	/**
	* metoda do resetu konwersacji - potrzebna przy ³adowaniu konwersacji z pliku
	*/
	void resetConv();

	/**
	* metoda do resetu pola konwersacji konwersacji
	*/
	void resetField();

	/**
	* Metoda do otrzymania dostêpu do jedynej instancji klasy
	* @param mywidth szerokoœæ sceny
	* @param myheight wysokoœæ sceny
	* @param target obiekt do narysowania sceny
	* @param manager mened¿er konwersacji
	*/
	static ChatScreen* getInstance(double mywidth, double myheight, RenderTarget& target, ConvoManager* manager);

	/**
	* Metoda s³u¿ac¹ do wyrysowania obiektu
	* @param target obiekt na którym ma byæ narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void draw(RenderTarget& target, RenderStates states);

	/**
	* Destruktor, zwalnia zaalokowan¹ dynamicznie pamiêæ
	*/
	~ChatScreen();
};
#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Bot.h"
#include "CategoryCreator.h"
#include "Question.h"

/**
* Klasa zarz¹dzaj¹ca u¿yciem logiki do przeprowadzenia rozmowy
* i umo¿liwiaj¹ca zapis do pliku
*/
class ConvoManager
{
private:
	/**
	* Obiekt do zainicjalizowania bazy programu informacjami z pliku
	*/
	CategoryCreator creator;

	/**
	* Obiekt zawieraj¹cy implementacjê g³ównej czêœci algorytmu
	*/
	Bot interlocutor;

	/**
	* Wektor par wiadomoœæ u¿ytkownika - odpowiedŸ programu
	* umo¿liwiaj¹cy ³atwe rejestrowanie konwersacji i jej zapis
	* oraz odczyt z pliku
	*/
	vector<pair<string, string>> currentSession;

	/**
	* Zmienna okreœlaj¹ca czy nale¿y narysowaæ poprzedni¹, sczytan¹ z pliku konwersacjê
	*/
	bool drawPrevious;
public:

	/**
	* Metoda umo¿liwiaj¹ca wypisanie na wyjœcie konsolowe
	* zawartoœci bazy programu
	*/
	void printBase() { interlocutor.printBase(); };

	/**
	* Metoda sprawdzaj¹ca czy nale¿y narysowaæ poprzedni¹ konwersacjê
	* @return true - nale¿y, false - nie nale¿y
	*/
	bool isPrevious() { return drawPrevious; };

	/**
	* Metoda pozwalaj¹ca zdecydowaæ czy nale¿y narysowaæ poprzedni¹ konwersacjê
	* @param toSet parametr okreœlaj¹cy czy narysowaæ poprzedni¹ konwersacjê
	* true - nale¿y, false - nie nale¿y
	*/
	void setPrevious(bool toSet) { drawPrevious = toSet; };

	/**
	* Metoda zwracaj¹ca wektor w którym przechowywane s¹
	* pary wiadomoœæ - odpowiedŸ z aktualnej konwersacji
	* @return zwracany wektor
	*/
	vector<pair<string, string>>& getSession() { return currentSession; };

	/**
	* Metoda pozwalaj¹ca ustawiæ zawartoœæ wektora przechowuj¹cego
	* pary wiadomoœæ - odpowiedŸ z aktualnej konwersacji
	* @param toSet ustawiana zawartoœæ wektora
	*/
	void setSessionContent(vector<pair<string, string>>& toSet);

	/**
	* Metoda pozwalaj¹ca rozpocz¹æ aktualn¹ sesjê konwersacji
	*/
	void startSession();

	/**
	* Metoda pozwalaj¹ca zakoñczyæ aktualn¹ sesjê konwersacji
	*/
	void endSession();

	/**
	* Metoda pozwalaj¹ca za³adowaæ poprzedni¹ konwersacjê z pliku
	*/
	void reloadConv();

	/**
	* Metoda pozwalaj¹ca zapisaæ poprzedni¹ konwersacjê do pliku
	*/
	void saveConv();

	/**
	* Metoda zape³niaj¹ca bazê z pliku
	* @param filename nazwa pliku
	*/
	void trainBot(const char* filename);

	/**
	* Metoda wysy³aj¹ca wiadomoœæ u¿ytkownika
	* do implementacji algorytmu
	* @param message wiadomoœæ
	* @return uzyskana odpowiedŸ
	*/
	string sendMessage(string message);
	std::ostream& operator<<(std::ostream& os);/**< Operator wypisania*/
	ConvoManager& operator=(const ConvoManager& toCopy);/**< Kopiuj¹cy operator przypisania*/
};
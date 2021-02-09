#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Bot.h"
#include "CategoryCreator.h"
#include "Question.h"

/**
* Klasa zarz�dzaj�ca u�yciem logiki do przeprowadzenia rozmowy
* i umo�liwiaj�ca zapis do pliku
*/
class ConvoManager
{
private:
	/**
	* Obiekt do zainicjalizowania bazy programu informacjami z pliku
	*/
	CategoryCreator creator;

	/**
	* Obiekt zawieraj�cy implementacj� g��wnej cz�ci algorytmu
	*/
	Bot interlocutor;

	/**
	* Wektor par wiadomo�� u�ytkownika - odpowied� programu
	* umo�liwiaj�cy �atwe rejestrowanie konwersacji i jej zapis
	* oraz odczyt z pliku
	*/
	vector<pair<string, string>> currentSession;

	/**
	* Zmienna okre�laj�ca czy nale�y narysowa� poprzedni�, sczytan� z pliku konwersacj�
	*/
	bool drawPrevious;
public:

	/**
	* Metoda umo�liwiaj�ca wypisanie na wyj�cie konsolowe
	* zawarto�ci bazy programu
	*/
	void printBase() { interlocutor.printBase(); };

	/**
	* Metoda sprawdzaj�ca czy nale�y narysowa� poprzedni� konwersacj�
	* @return true - nale�y, false - nie nale�y
	*/
	bool isPrevious() { return drawPrevious; };

	/**
	* Metoda pozwalaj�ca zdecydowa� czy nale�y narysowa� poprzedni� konwersacj�
	* @param toSet parametr okre�laj�cy czy narysowa� poprzedni� konwersacj�
	* true - nale�y, false - nie nale�y
	*/
	void setPrevious(bool toSet) { drawPrevious = toSet; };

	/**
	* Metoda zwracaj�ca wektor w kt�rym przechowywane s�
	* pary wiadomo�� - odpowied� z aktualnej konwersacji
	* @return zwracany wektor
	*/
	vector<pair<string, string>>& getSession() { return currentSession; };

	/**
	* Metoda pozwalaj�ca ustawi� zawarto�� wektora przechowuj�cego
	* pary wiadomo�� - odpowied� z aktualnej konwersacji
	* @param toSet ustawiana zawarto�� wektora
	*/
	void setSessionContent(vector<pair<string, string>>& toSet);

	/**
	* Metoda pozwalaj�ca rozpocz�� aktualn� sesj� konwersacji
	*/
	void startSession();

	/**
	* Metoda pozwalaj�ca zako�czy� aktualn� sesj� konwersacji
	*/
	void endSession();

	/**
	* Metoda pozwalaj�ca za�adowa� poprzedni� konwersacj� z pliku
	*/
	void reloadConv();

	/**
	* Metoda pozwalaj�ca zapisa� poprzedni� konwersacj� do pliku
	*/
	void saveConv();

	/**
	* Metoda zape�niaj�ca baz� z pliku
	* @param filename nazwa pliku
	*/
	void trainBot(const char* filename);

	/**
	* Metoda wysy�aj�ca wiadomo�� u�ytkownika
	* do implementacji algorytmu
	* @param message wiadomo��
	* @return uzyskana odpowied�
	*/
	string sendMessage(string message);
	std::ostream& operator<<(std::ostream& os);/**< Operator wypisania*/
	ConvoManager& operator=(const ConvoManager& toCopy);/**< Kopiuj�cy operator przypisania*/
};
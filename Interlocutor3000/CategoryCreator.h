#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Bot.h"
#include "ProcessText.h"
#include <fstream>

/**
* Klasa odpowiedzialna za sczytanie pliku z danymi i stworzenie
* na ich podstawie kategorii do u¿ycia przez program
*/
class CategoryCreator : ProcessText
{
	string actualClass;/**< aktualnie przetwarzana kategoria*/
	vector<string> tokens;/**< aktualnie przetwarzane ³añcuchy znaków - s³owa*/
	vector<string> responses;/**< aktualnie przetwarzane ³añcuchy znaków - odpowiedzi*/
	ifstream trainingFile;/**< plik zawieraj¹cy dane potrzebne do stworzenia kategorii*/
public:
	/**
	* Metoda odpowiedzialna za zliczenie wyst¹pieñ s³ów
	* @param myWords wektor ze s³owami
	* @return wektor par s³owo-liczba wyst¹pieñ
	*/
	vector<pair<string, int>> countWords(vector<string> &myWords);
	/**
	* Metoda sprawdzaj¹ca czy podane s³owo zawiera siê w podanym przedziale wektora
	* @param vctr wektor ze s³owami
	* @param str szukany napis
	* @param border pozycja w wektorze ograniczaj¹ca obszar poszukiwañ
	* napisu od góry
	* @return informacja czy dany napis zosta³ znaleziony
	*/
	bool inVectorString(vector<string>& vctr, string str, vector<string>::iterator border);
	/**
	* Metoda sczytuj¹ca informacje z pliku
	* i na ich podstawie zape³niaj¹ca bazê kategorii obiektu klasy Bot
	* @param filename nazwa pliku
	* @param toFeed obiekt klasy Bot którego baza ma zostaæ utworzona
	*/
	void readFile(const char* filename, Bot& toFeed);
	/**
	* operator wpisania ze strumienia
	* jego zadaniem jest sczytanie jednej linii pliku
	*/
	istream& operator>> (istream& input);

};

/**
* struktura definiuj¹ca wyj¹tek przy sczytywaniu z pliku
*/
struct ReadException : public std::exception
{
	const char* what()const throw ()/**< zwraca informacjê o zaistnia³ym problemie*/
	{
		return "Sczytano niewlasciwy znak";
	}
};
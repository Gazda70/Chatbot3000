#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Bot.h"
#include "ProcessText.h"
#include <fstream>

/**
* Klasa odpowiedzialna za sczytanie pliku z danymi i stworzenie
* na ich podstawie kategorii do u�ycia przez program
*/
class CategoryCreator : ProcessText
{
	string actualClass;/**< aktualnie przetwarzana kategoria*/
	vector<string> tokens;/**< aktualnie przetwarzane �a�cuchy znak�w - s�owa*/
	vector<string> responses;/**< aktualnie przetwarzane �a�cuchy znak�w - odpowiedzi*/
	ifstream trainingFile;/**< plik zawieraj�cy dane potrzebne do stworzenia kategorii*/
public:
	/**
	* Metoda odpowiedzialna za zliczenie wyst�pie� s��w
	* @param myWords wektor ze s�owami
	* @return wektor par s�owo-liczba wyst�pie�
	*/
	vector<pair<string, int>> countWords(vector<string> &myWords);
	/**
	* Metoda sprawdzaj�ca czy podane s�owo zawiera si� w podanym przedziale wektora
	* @param vctr wektor ze s�owami
	* @param str szukany napis
	* @param border pozycja w wektorze ograniczaj�ca obszar poszukiwa�
	* napisu od g�ry
	* @return informacja czy dany napis zosta� znaleziony
	*/
	bool inVectorString(vector<string>& vctr, string str, vector<string>::iterator border);
	/**
	* Metoda sczytuj�ca informacje z pliku
	* i na ich podstawie zape�niaj�ca baz� kategorii obiektu klasy Bot
	* @param filename nazwa pliku
	* @param toFeed obiekt klasy Bot kt�rego baza ma zosta� utworzona
	*/
	void readFile(const char* filename, Bot& toFeed);
	/**
	* operator wpisania ze strumienia
	* jego zadaniem jest sczytanie jednej linii pliku
	*/
	istream& operator>> (istream& input);

};

/**
* struktura definiuj�ca wyj�tek przy sczytywaniu z pliku
*/
struct ReadException : public std::exception
{
	const char* what()const throw ()/**< zwraca informacj� o zaistnia�ym problemie*/
	{
		return "Sczytano niewlasciwy znak";
	}
};
#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Category.h"
#include "Question.h"

/**
* Klasa implementuj�ca algorytm wyboru odpowiedzi.
*
*/
class Bot: public Dictionary
{
private:
	/**
	* Wektor zawieraj�cy obiekty klasy reprezentuj�cej kategorie tematyczne
	* w zakresie kt�rych program mo�e udziela� odpowiedzi
	*/
	vector<Category> base;
	/**
	* Metoda zwracaj�ca �a�cuch znak�w zawieraj�cy
	* wybran� przez program odpowied� na wiadomo�� u�ytkownika
	* @return odpowied� wybrana przez algorytm
	*/
	string getResponse();
public:
	/**
	* Konstruktor domy�lny
	*/
	Bot() = default;
	/**
	* Metoda dodaj�ca nowy obiekt reprezentuj�cy kategori� odpowiedzi
	* do bazy lub wzbogacaj�ca istniej�cy obiekt o nowe skojarzone z nim s�owa
	* @param name to sczytana z pliku nazwa kategorii
	* @param actualResponse to wektor reprezentuj�cy zbi�r odpowiedzi dla danej kategorii sczytanych w danym kroku z pliku
	* @param associatedWords to wektor par napis-liczba ca�kowita reprezentuj�cy s�owa skojarzone
	* z dan� kategori� wraz z liczb� ich wyst�pie� sczytane w danym kroku z pliku
	*/
	void addToBase(string& name,vector<string>& actualResponse,vector<pair<string, int>>& associatedWords);

	/**
	* Metoda s�u��ca do wyszukiwania okre�lonego elementu w bazie kategorii
	* @param name to nazwa poszukiwanej kategorii
	* @param iterBase to iterator od pozycji kt�rego powinno rozpocz�� si� przeszukiwanie
	* wektora reprezentuj�cego baz�
	* @return iterator okre�laj�cy pozycj� znalezionego elementu
	*/
	vector<Category>::iterator& findClassInBase(string name, vector<Category>::iterator& iterBase);

	/**
	* Funkcja umo�liwiaj�ca wypisanie zawarto�ci bazy
	*/
	void printBase();

	/**
	* Metoda maj�ca za zadanie wyzerowa� wynik ka�dej z kategorii w bazie na koniec 
	* operacji wyszukiwania
	*/
	void zeroScore();

	/**
	* Metoda implementuj�ca g��wn� cz�� algorytmu udzielania odpowiedzi;
	* jej zadaniem dla ka�dego s�owa z wiadomo��i u�ytkownika jest okre�li�
	* kt�ra kategoria odpowiedzi zawiera je nawi�ksz� ilo�� razy i przyzna� jej punkt;
	* wybrana zostaje kategoria kt�ra po przeanalizowaniu wszystkich s��w w wiadomo�ci
	* u�ytkownika posiada najwi�ksz� ilo�� punkt�w
	* @param obiekt klasy Question zawieraj�cy przetworzony �a�cuch znak�w zawieraj�cy 
	* wiadomo�� u�ytkownika
	* @return �a�cuch znak�w b�d�cy odpowiedzi� programu na wiadomo�� u�ytkownika
	*/
	string respond(Question& toAnswer);

	/**
	* Metoda wywo�uj�ca metody do rozpocz�cia sesji w obiektach bazy
	*/
	void startSession();

	/**
	* Metoda wywo�uj�ca metody do zako�czenia sesji w obiektach bazy
	*/
	void endSession();
};
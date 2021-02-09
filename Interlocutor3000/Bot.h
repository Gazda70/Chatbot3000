#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Category.h"
#include "Question.h"

/**
* Klasa implementuj¹ca algorytm wyboru odpowiedzi.
*
*/
class Bot: public Dictionary
{
private:
	/**
	* Wektor zawieraj¹cy obiekty klasy reprezentuj¹cej kategorie tematyczne
	* w zakresie których program mo¿e udzielaæ odpowiedzi
	*/
	vector<Category> base;
	/**
	* Metoda zwracaj¹ca ³añcuch znaków zawieraj¹cy
	* wybran¹ przez program odpowiedŸ na wiadomoœæ u¿ytkownika
	* @return odpowiedŸ wybrana przez algorytm
	*/
	string getResponse();
public:
	/**
	* Konstruktor domyœlny
	*/
	Bot() = default;
	/**
	* Metoda dodaj¹ca nowy obiekt reprezentuj¹cy kategoriê odpowiedzi
	* do bazy lub wzbogacaj¹ca istniej¹cy obiekt o nowe skojarzone z nim s³owa
	* @param name to sczytana z pliku nazwa kategorii
	* @param actualResponse to wektor reprezentuj¹cy zbiór odpowiedzi dla danej kategorii sczytanych w danym kroku z pliku
	* @param associatedWords to wektor par napis-liczba ca³kowita reprezentuj¹cy s³owa skojarzone
	* z dan¹ kategori¹ wraz z liczb¹ ich wyst¹pieñ sczytane w danym kroku z pliku
	*/
	void addToBase(string& name,vector<string>& actualResponse,vector<pair<string, int>>& associatedWords);

	/**
	* Metoda s³u¿¹ca do wyszukiwania okreœlonego elementu w bazie kategorii
	* @param name to nazwa poszukiwanej kategorii
	* @param iterBase to iterator od pozycji którego powinno rozpocz¹æ siê przeszukiwanie
	* wektora reprezentuj¹cego bazê
	* @return iterator okreœlaj¹cy pozycjê znalezionego elementu
	*/
	vector<Category>::iterator& findClassInBase(string name, vector<Category>::iterator& iterBase);

	/**
	* Funkcja umo¿liwiaj¹ca wypisanie zawartoœci bazy
	*/
	void printBase();

	/**
	* Metoda maj¹ca za zadanie wyzerowaæ wynik ka¿dej z kategorii w bazie na koniec 
	* operacji wyszukiwania
	*/
	void zeroScore();

	/**
	* Metoda implementuj¹ca g³ówn¹ czêœæ algorytmu udzielania odpowiedzi;
	* jej zadaniem dla ka¿dego s³owa z wiadomoœæi u¿ytkownika jest okreœliæ
	* która kategoria odpowiedzi zawiera je nawiêksz¹ iloœæ razy i przyznaæ jej punkt;
	* wybrana zostaje kategoria która po przeanalizowaniu wszystkich s³ów w wiadomoœci
	* u¿ytkownika posiada najwiêksz¹ iloœæ punktów
	* @param obiekt klasy Question zawieraj¹cy przetworzony ³añcuch znaków zawieraj¹cy 
	* wiadomoœæ u¿ytkownika
	* @return ³añcuch znaków bêd¹cy odpowiedzi¹ programu na wiadomoœæ u¿ytkownika
	*/
	string respond(Question& toAnswer);

	/**
	* Metoda wywo³uj¹ca metody do rozpoczêcia sesji w obiektach bazy
	*/
	void startSession();

	/**
	* Metoda wywo³uj¹ca metody do zakoñczenia sesji w obiektach bazy
	*/
	void endSession();
};
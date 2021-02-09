#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ProcessText.h"
#include "Dictionary.h"
#include "Question.h"
#include "SettingsContainer.h"
#include <time.h>

/**
* Klasa reprezentuj¹ca kategoriê tematyczn¹ któr¹ zna program,
* zawiera zbiór skojarzonych ze sob¹ s³ów oraz odpowiedzi
*/

class Category :public ProcessText, public Dictionary
{
private:
	string name;/**< nazwa kategorii*/
	double score;/**< wynik który dana kategoria uzsyka³a w aktualnym procesie wyliczania*/

	/**
	* wektor zawieraj¹cy ³añcuchy znaków reprezentuj¹cych wszytkie mo¿liwe odpowiedzi
	* przewidziane dla tej kategorii
	*/
	std::vector<string> actualResponse;

	/**
	* aktualizowany w czasie sesji konwersacji wektor zawieraj¹cy ³añcuchy znaków reprezentuj¹ce odpowiedzi
	* nieu¿yte jeszcze podczas danej sesji
	*/
	std::vector<string> sessionResp;
public:
	Category() :score(0.0){};/**< konstruktor bezargumentowy*/
	/**
	* Konstruktor
	* @param myName nazwa kategorii
	* @param myRes wektor zawieraj¹cy mo¿liwe odpowiedzi w danej kategorii
	* @param myWords wektor par zawieraj¹cych s³owa skojarzone z dan¹ kategori¹ 
	* oraz liczbê ich wyst¹pieñ
	*/
	Category(string myName, vector<string>& myRes, vector<pair<string, int>>& myWords);
	Category(const Category& toCopy);/**< konstruktor kopiuj¹cy*/

	/**
	* Metoda zwracaj¹ca aktualny wynik kategorii
	*/
	double getScore() { return score; };

	/**
	* Metoda zwracaj¹ca liczbê wyst¹pien danego s³owa w bazie kategorii
	* @param given s³owo którego liczbê wyst¹pieñ nale¿y okreœliæ
	*/
	int getOccurences(std::string given);

	/**
	* Metoda rozpoczynaj¹ca sesjê konwersacji
	* kopiuje do wektora sessionResp zawartoœæ wektora actualResponse
	*/
	void startSession();

	/**
	* Metoda dodaj¹ca nowe odpowiedzi do wektora
	*/
	void addResponses(std::vector<std::string>& newResps);

	/**
	* Metoda koñcz¹ca sesjê konwersacji
	* opró¿nia wektor sessionResp
	*/
	void endSession();

	/**
	* Metoda inkrementuj¹ca wynik
	*/
	void incScore() { score++; };

	/**
	* Metoda zeruj¹ca wynik
	*/
	void zeroScore();

	/**
	* Metoda wypisuj¹ca odpowiedzi skojarzone z kategori¹
	*/
	void printResponses();

	/**
	* Metoda wypisuj¹ca s³owa skojarzone z kategori¹
	*/
	void printWords();

	/**
	* Metoda zwraca wylosowan¹ odpowiedŸ
	* @return odpowiedŸ
	*/
	string sayResponse();
	/**
	* Metoda zwraca nazwê kategorii
	* return nazwa
	*/
	string sayName();
	Category& operator=(Category&& toMove) noexcept;/**< przenosz¹cy operator przypisania*/
	Category& operator=(const Category& toCopy) noexcept;/**< kopiuj¹cy operator przypisania*/
};
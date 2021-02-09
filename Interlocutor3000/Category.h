#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ProcessText.h"
#include "Dictionary.h"
#include "Question.h"
#include "SettingsContainer.h"
#include <time.h>

/**
* Klasa reprezentuj�ca kategori� tematyczn� kt�r� zna program,
* zawiera zbi�r skojarzonych ze sob� s��w oraz odpowiedzi
*/

class Category :public ProcessText, public Dictionary
{
private:
	string name;/**< nazwa kategorii*/
	double score;/**< wynik kt�ry dana kategoria uzsyka�a w aktualnym procesie wyliczania*/

	/**
	* wektor zawieraj�cy �a�cuchy znak�w reprezentuj�cych wszytkie mo�liwe odpowiedzi
	* przewidziane dla tej kategorii
	*/
	std::vector<string> actualResponse;

	/**
	* aktualizowany w czasie sesji konwersacji wektor zawieraj�cy �a�cuchy znak�w reprezentuj�ce odpowiedzi
	* nieu�yte jeszcze podczas danej sesji
	*/
	std::vector<string> sessionResp;
public:
	Category() :score(0.0){};/**< konstruktor bezargumentowy*/
	/**
	* Konstruktor
	* @param myName nazwa kategorii
	* @param myRes wektor zawieraj�cy mo�liwe odpowiedzi w danej kategorii
	* @param myWords wektor par zawieraj�cych s�owa skojarzone z dan� kategori� 
	* oraz liczb� ich wyst�pie�
	*/
	Category(string myName, vector<string>& myRes, vector<pair<string, int>>& myWords);
	Category(const Category& toCopy);/**< konstruktor kopiuj�cy*/

	/**
	* Metoda zwracaj�ca aktualny wynik kategorii
	*/
	double getScore() { return score; };

	/**
	* Metoda zwracaj�ca liczb� wyst�pien danego s�owa w bazie kategorii
	* @param given s�owo kt�rego liczb� wyst�pie� nale�y okre�li�
	*/
	int getOccurences(std::string given);

	/**
	* Metoda rozpoczynaj�ca sesj� konwersacji
	* kopiuje do wektora sessionResp zawarto�� wektora actualResponse
	*/
	void startSession();

	/**
	* Metoda dodaj�ca nowe odpowiedzi do wektora
	*/
	void addResponses(std::vector<std::string>& newResps);

	/**
	* Metoda ko�cz�ca sesj� konwersacji
	* opr�nia wektor sessionResp
	*/
	void endSession();

	/**
	* Metoda inkrementuj�ca wynik
	*/
	void incScore() { score++; };

	/**
	* Metoda zeruj�ca wynik
	*/
	void zeroScore();

	/**
	* Metoda wypisuj�ca odpowiedzi skojarzone z kategori�
	*/
	void printResponses();

	/**
	* Metoda wypisuj�ca s�owa skojarzone z kategori�
	*/
	void printWords();

	/**
	* Metoda zwraca wylosowan� odpowied�
	* @return odpowied�
	*/
	string sayResponse();
	/**
	* Metoda zwraca nazw� kategorii
	* return nazwa
	*/
	string sayName();
	Category& operator=(Category&& toMove) noexcept;/**< przenosz�cy operator przypisania*/
	Category& operator=(const Category& toCopy) noexcept;/**< kopiuj�cy operator przypisania*/
};
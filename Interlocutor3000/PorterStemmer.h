#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <regex>

/**
* Klasa implementuj¹ca algorytm Portera
* s³u¿¹cy do redukcji wyrazów w j. angielskim
* do ich tematów (usuwanie koñcówek)
*/
class PorterStemmer
{
	/**
	* S³owo do zredukowania przez algorytm
	*/
	std::string toStem;

	/**
	* D³ugoœæ s³owa 
	*/
	int wordLen;

	/**
	* Indeks pocz¹tku s³owa 
	*/
	int wordBeg;

	/**
	* Parametr okreœlaj¹cy iloœæ samog³osek i spó³g³osek
	* w tekœcie
	*/
	int paramVC;

	/**
	* Parametr okreœlaj¹cy iloœæ samog³osek i spó³g³osek
	* w tekœcie
	*/
	void setparamVC();

	/**
	* Metody od step1a do step5b implementuj¹ kolejne kroki
	* algorytmu, polegaj¹ce na odnalezieniu w tekœcie okreœlonych
	* uk³adów liter (g³ównie kolejnoœci wystêpowañ samog³osek i spó³g³osek) i w zale¿noœci od nich
	* usuniêcia odpowiednich koncówek
	*/
	void step1a();
	void step1bfirst();
	void step1bsecond();
	void step1c();
	void step2();
	void step3();
	void step4();
	void step5a();
	void step5b();

	/**
	* Metoda usuwaj¹ca okreœlon¹ liczbê liter
	* z koñca s³owa
	* @param toerase liczba liter do usuniêcia z koñca
	*/
	void eraseLast(int toerase);
public:

	/**
	* Metoda obs³uguj¹ca algorytm
	* @param tostem s³owo do modyfikacji przez algorytm
	*/
	void stem(std::string& tostem);
};
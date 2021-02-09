#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <regex>

/**
* Klasa implementuj�ca algorytm Portera
* s�u��cy do redukcji wyraz�w w j. angielskim
* do ich temat�w (usuwanie ko�c�wek)
*/
class PorterStemmer
{
	/**
	* S�owo do zredukowania przez algorytm
	*/
	std::string toStem;

	/**
	* D�ugo�� s�owa 
	*/
	int wordLen;

	/**
	* Indeks pocz�tku s�owa 
	*/
	int wordBeg;

	/**
	* Parametr okre�laj�cy ilo�� samog�osek i sp�g�osek
	* w tek�cie
	*/
	int paramVC;

	/**
	* Parametr okre�laj�cy ilo�� samog�osek i sp�g�osek
	* w tek�cie
	*/
	void setparamVC();

	/**
	* Metody od step1a do step5b implementuj� kolejne kroki
	* algorytmu, polegaj�ce na odnalezieniu w tek�cie okre�lonych
	* uk�ad�w liter (g��wnie kolejno�ci wyst�powa� samog�osek i sp�g�osek) i w zale�no�ci od nich
	* usuni�cia odpowiednich konc�wek
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
	* Metoda usuwaj�ca okre�lon� liczb� liter
	* z ko�ca s�owa
	* @param toerase liczba liter do usuni�cia z ko�ca
	*/
	void eraseLast(int toerase);
public:

	/**
	* Metoda obs�uguj�ca algorytm
	* @param tostem s�owo do modyfikacji przez algorytm
	*/
	void stem(std::string& tostem);
};
#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "PorterStemmer.h"
using namespace std;

/**
* Klasa zapewniaj¹ca obróbkê tekstu
*/
class ProcessText
{
protected:

	/**
	* Metoda rozbijaj¹ca ³añuch znaków z³o¿ony z wyrazów  i znaków specjalnych
	* na pojedyncze s³owa z³o¿one z ma³ych liter
	* @param text s³owo do rozbicia
	* @return wektor uzyskanych wyrazów
	*/
	vector<string> tokenize(string text);

	/**
	* Metoda usuwaj¹ca koñcówkê s³owa i zwracaj¹ca jego temat
	* @param toStem s³owo do pozbawienia z koncówki
	*/
	void stem(vector<string>& toStem);

	/**
	* Metoda sprawdzaj¹ca czy s³owo zawiera wy³¹cznie
	* dozwolone znaki
	* @param toTest s³owo do sprawdzenia
	* @return true - ³añcuch znaków jest poprawny,
	* false - ³añcuch znaków jest niepoprawny
	*/
	bool testString(string toTest);
};
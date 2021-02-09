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
* Klasa zapewniaj�ca obr�bk� tekstu
*/
class ProcessText
{
protected:

	/**
	* Metoda rozbijaj�ca �a�uch znak�w z�o�ony z wyraz�w  i znak�w specjalnych
	* na pojedyncze s�owa z�o�one z ma�ych liter
	* @param text s�owo do rozbicia
	* @return wektor uzyskanych wyraz�w
	*/
	vector<string> tokenize(string text);

	/**
	* Metoda usuwaj�ca ko�c�wk� s�owa i zwracaj�ca jego temat
	* @param toStem s�owo do pozbawienia z konc�wki
	*/
	void stem(vector<string>& toStem);

	/**
	* Metoda sprawdzaj�ca czy s�owo zawiera wy��cznie
	* dozwolone znaki
	* @param toTest s�owo do sprawdzenia
	* @return true - �a�cuch znak�w jest poprawny,
	* false - �a�cuch znak�w jest niepoprawny
	*/
	bool testString(string toTest);
};
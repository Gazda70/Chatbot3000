#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ProcessText.h"
using namespace std;

/**
* Klasa reprezentuj�ca wiadomo�� wys�an� przez u�ytkownika
* do programu
*/
class Question : public ProcessText
{
public:

	/**
	* Wektor s��w zawartych w wiadomo�ci
	*/
	vector<string> words;

	/**
	* Konstruktor bezargumentowy
	*/
	Question() = default;

	/**
	* Konstruktor 
	* @param toTokenize
	*/
	Question(string toTokenize);

	/**
	* Wypisz przechowywane wyrazy
	*/
	void printTokens();
};

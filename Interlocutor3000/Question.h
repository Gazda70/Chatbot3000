#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ProcessText.h"
using namespace std;

/**
* Klasa reprezentuj¹ca wiadomoœæ wys³an¹ przez u¿ytkownika
* do programu
*/
class Question : public ProcessText
{
public:

	/**
	* Wektor s³ów zawartych w wiadomoœci
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

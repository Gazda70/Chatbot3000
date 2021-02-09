#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
using namespace sf;
using namespace std;

/**
* Klasa do przechowywania i rejestrowania ilo�ci s��w
*/
class Dictionary
{
protected:
    /**
    * Wektor przechowuj�cy s�owa wraz z liczb� ich wyst�pie�
    */
    std::vector<pair<string, int>> dictionary;
public:
    Dictionary() = default;/**< Konstruktor bezargumentowy*/
    /**
    * Konstruktor 
    * @param myDict wektor s��w do przechowywania w obiekcie
    */
    Dictionary(vector<pair<string, int>> myDict) :dictionary(myDict) {};

    /**
    * Metoda dodaj�ca wektor ze zliczonymi s�owami do obiektu
    * @param toAdd wektor s��w do dodania do wektora obecnego w obiekcie
    */
    void addToDict(vector<pair<string, int>>& toAdd);

    /**
    * Metoda sprawdzaj�ca czy dane s�owo jest zapisane w obiekcie
    * @param s�owo kt�rego wyst�powanie jest sprawdzane
    * @return para warto�� logiczna - zmienna ca�kowita;
    * warto�� logiczna przyjmuje warto�� true je�eli szukany obiekt 
    * zosta� znaleziony, false w przeciwnym wypadku;
    * zmienna ca�kowita okre�la liczb� wyst�pien danego s�owa w wektorze
    * obiektu - 0 w przypadku braku
    */
    std::pair<bool, int> inDict(string another);

    /**
    * Metoda wypisuj�ca zawarto�� wektora s��w na wyj�cie konsolowe
    */
    void printDictionary();
};
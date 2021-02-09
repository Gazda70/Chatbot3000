#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
using namespace sf;
using namespace std;

/**
* Klasa do przechowywania i rejestrowania iloœci s³ów
*/
class Dictionary
{
protected:
    /**
    * Wektor przechowuj¹cy s³owa wraz z liczb¹ ich wyst¹pieñ
    */
    std::vector<pair<string, int>> dictionary;
public:
    Dictionary() = default;/**< Konstruktor bezargumentowy*/
    /**
    * Konstruktor 
    * @param myDict wektor s³ów do przechowywania w obiekcie
    */
    Dictionary(vector<pair<string, int>> myDict) :dictionary(myDict) {};

    /**
    * Metoda dodaj¹ca wektor ze zliczonymi s³owami do obiektu
    * @param toAdd wektor s³ów do dodania do wektora obecnego w obiekcie
    */
    void addToDict(vector<pair<string, int>>& toAdd);

    /**
    * Metoda sprawdzaj¹ca czy dane s³owo jest zapisane w obiekcie
    * @param s³owo którego wystêpowanie jest sprawdzane
    * @return para wartoœæ logiczna - zmienna ca³kowita;
    * wartoœæ logiczna przyjmuje wartoœæ true je¿eli szukany obiekt 
    * zosta³ znaleziony, false w przeciwnym wypadku;
    * zmienna ca³kowita okreœla liczbê wyst¹pien danego s³owa w wektorze
    * obiektu - 0 w przypadku braku
    */
    std::pair<bool, int> inDict(string another);

    /**
    * Metoda wypisuj¹ca zawartoœæ wektora s³ów na wyjœcie konsolowe
    */
    void printDictionary();
};
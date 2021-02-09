#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

/**
* Enum reprezentuj¹cy stan obiektu w zale¿noœci od u¿ycia na nim myszki
*/
enum class State
{
	Active, Inactive
};

/*
* Klasa udostêpniaj¹ca interfejs do obs³ugi danych wejœciowych z myszki
*/
class InteractableMouse 
{
protected:

	/*
	* Pole opisuj¹ce stan obiektu
	*/
	State actual;
public:

	/*
	* Metoda czysto wirtualna do obs³ugi myszki
	* @param wspó³rzêdne kursora myszki
	*/
	virtual void manageInput(sf::Vector2f mousepos) = 0;

	/*
	* Metoda zwracaj¹ca informacjê o stanie obiektu
	* @return stan obiektu
	*/
	State getState() { return actual; };
};

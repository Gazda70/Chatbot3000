#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

/**
* Enum reprezentuj�cy stan obiektu w zale�no�ci od u�ycia na nim myszki
*/
enum class State
{
	Active, Inactive
};

/*
* Klasa udost�pniaj�ca interfejs do obs�ugi danych wej�ciowych z myszki
*/
class InteractableMouse 
{
protected:

	/*
	* Pole opisuj�ce stan obiektu
	*/
	State actual;
public:

	/*
	* Metoda czysto wirtualna do obs�ugi myszki
	* @param wsp�rz�dne kursora myszki
	*/
	virtual void manageInput(sf::Vector2f mousepos) = 0;

	/*
	* Metoda zwracaj�ca informacj� o stanie obiektu
	* @return stan obiektu
	*/
	State getState() { return actual; };
};

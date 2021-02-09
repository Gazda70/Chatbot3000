#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ContainText.h"
#include "InteractableMouse.h"
using namespace sf;
/**
* Klasa reprezentuj�ca przycisk oraz pola tekstowe
*/
class Button : public ContainText, InteractableMouse
{
private:
	/**
	* obiekt reprezentuj�cy kszta�t do wyrysowania
	*/
	sf::RectangleShape body;
public:
	/**
	* metoda sprawdzaj�ca czy dany punkt znajduje si� wewn�trz kszta�tu 
	*/
	bool contains(sf::Vector2f mousepos);
	/**
	* Konstruktor
	* @param x_axis wsp�rz�dna pozioma po�o�enia kszta�tu
	* @param y_axis wsp�rz�dna pionowa po�o�enia kszta�tu
	* @param width szeroko�� kszta�tu
	* @param height wysoko�� kszta�tu
	* @param color kolor kszta�tu
	* @param text tekst do wy�wietlenia w obr�bie kszta�u
	* @param nameFontFile nazwa pliku z czcionk� do stworzenia tekstu
	* @param textSize rozmiar liter w tek�cie
	* @param textColor kolor tekstu
	* @param textpos wektor z warto�ciami przez kt�re nale�y przemno�y� wymiary kszta�tu by
	* otrzyma� po�o�enie tekstu wzgl�dem kszta�tu
	* @param textBold okre�la czy tekst powinien by� napisany pogrubion� czcionk�
	* @param textUnderline okre�la czy tekst powinien by� podkre�lony
	* @param outlineThick okre�la grubo�� obw�dki kszta�tu
	* @param outlineColor okre�la kolor obw�dki kszta�tu
	*/
	Button(float x_axis = 0.0, float y_axis = 0.0, float width = 100.0, float height = 50.0, sf::Color color = sf::Color::Blue,
		std::string text = "Button", std::string nameFontFile = "times.ttf", unsigned int textSize = 15, sf::Color textColor = sf::Color::Black,
		sf::Vector2f textpos = { (1.5 / 4.0),(1.0 / 4.0) },Text::Style textBold = Text::Style::Regular,
		sf::Text::Style textUnderline = sf::Text::Style::Regular, float outlineThick = 3.0, sf::Color outlineColor = sf::Color::Black);

	/**
	* metoda do obs�ugi informacji z myszki - wci�ni�cie klawisza
	*/
	void manageInput(Vector2f mousepos);

	/**
	* metoda aktywacji obiektu
	*/
	void activate();

	/**
	* Metoda s�u�ac� do wyrysowania obiektu
	* @param target obiekt na kt�rym ma by� narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void sf::Drawable::draw(RenderTarget& window, RenderStates state)const;
};
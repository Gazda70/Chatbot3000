#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ContainText.h"
#include "InteractableMouse.h"
using namespace sf;
/**
* Klasa reprezentuj¹ca przycisk oraz pola tekstowe
*/
class Button : public ContainText, InteractableMouse
{
private:
	/**
	* obiekt reprezentuj¹cy kszta³t do wyrysowania
	*/
	sf::RectangleShape body;
public:
	/**
	* metoda sprawdzaj¹ca czy dany punkt znajduje siê wewn¹trz kszta³tu 
	*/
	bool contains(sf::Vector2f mousepos);
	/**
	* Konstruktor
	* @param x_axis wspó³rzêdna pozioma po³o¿enia kszta³tu
	* @param y_axis wspó³rzêdna pionowa po³o¿enia kszta³tu
	* @param width szerokoœæ kszta³tu
	* @param height wysokoœæ kszta³tu
	* @param color kolor kszta³tu
	* @param text tekst do wyœwietlenia w obrêbie kszta³u
	* @param nameFontFile nazwa pliku z czcionk¹ do stworzenia tekstu
	* @param textSize rozmiar liter w tekœcie
	* @param textColor kolor tekstu
	* @param textpos wektor z wartoœciami przez które nale¿y przemno¿yæ wymiary kszta³tu by
	* otrzymaæ po³o¿enie tekstu wzglêdem kszta³tu
	* @param textBold okreœla czy tekst powinien byæ napisany pogrubion¹ czcionk¹
	* @param textUnderline okreœla czy tekst powinien byæ podkreœlony
	* @param outlineThick okreœla gruboœæ obwódki kszta³tu
	* @param outlineColor okreœla kolor obwódki kszta³tu
	*/
	Button(float x_axis = 0.0, float y_axis = 0.0, float width = 100.0, float height = 50.0, sf::Color color = sf::Color::Blue,
		std::string text = "Button", std::string nameFontFile = "times.ttf", unsigned int textSize = 15, sf::Color textColor = sf::Color::Black,
		sf::Vector2f textpos = { (1.5 / 4.0),(1.0 / 4.0) },Text::Style textBold = Text::Style::Regular,
		sf::Text::Style textUnderline = sf::Text::Style::Regular, float outlineThick = 3.0, sf::Color outlineColor = sf::Color::Black);

	/**
	* metoda do obs³ugi informacji z myszki - wciœniêcie klawisza
	*/
	void manageInput(Vector2f mousepos);

	/**
	* metoda aktywacji obiektu
	*/
	void activate();

	/**
	* Metoda s³u¿ac¹ do wyrysowania obiektu
	* @param target obiekt na którym ma byæ narysowany obiekt
	* @param state stan obiektu do narysowania
	*/
	void sf::Drawable::draw(RenderTarget& window, RenderStates state)const;
};
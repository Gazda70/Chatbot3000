#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

/**
* Klasa s�u��ca do obs�ugi tekstu
*/
class ContainText : public sf::Drawable
{
protected:
	/**
	* Zmienna okre�laj�ca czy wy�wietlany
	* jest domy�lny tekst
	*/
	bool isinfoString;

	/**
	* Zmienna okre�laj�ca czy pole tekstowe
	* jest aktywne
	*/
	bool textfieldActive;

	/**
	* Wektor par ilo�� znak�w w tek�cie-rozmiar tekstu
	* s�u�y do powrotu do wcze�niejszego rozmiaru czcionki
	* przy usuwaniu znak�w
	*/
	std::vector<std::pair<int, int>> adjustments;

	/**
	* Domy�lny napis
	*/
	std::string infoString;

	/**
	* Aktualna odleg�o�� jaka pozosta�a do ko�ca obszaru
	* w kt�rym mo�e pojawia� sie tekst
	*/
	float actualWidth;

	/**
	* Aktualna wysoko�� tekstu
	*/
	float textHeight;

	/**
	* Przechowywany tekst
	*/
	sf::Text myText;

	/**
	* U�ywana czcionka
	*/
	sf::Font myFont;

	/**
	* Wymiary kszta�tu w kt�rym ma znale��
	* si� pole tekstowe
	*/
	sf::FloatRect parent;

	/**
	* Pozycja tekstu w obr�bie kszta�tu
	*/
	sf::Vector2f textLocalOffset;

	/**
	* Aktualny rozmiar liter w tek�cie
	*/
	unsigned int selectedSize;

	/**
	* Minimalny rozmiar liter w tek�cie
	* pozwalaj�cy na dobr� widoczno��
	*/
	unsigned int minimalSize;

	/**
	* Konstruktor
	* @param parentDim wymiary ksztaltu w kt�ry ma zosta� wpisany tekst
	* @param relative wektor z warto�ciami przez kt�re nale�y przemno�y� wymiary kszta�tu by
	* otrzyma� po�o�enie tekstu wzgl�dem kszta�tu
	* @param text tekst do wy�wietlenia w obr�bie kszta�u
	* @param nameFontFile nazwa pliku z czcionk� do stworzenia tekstu
	* @param textSize rozmiar liter w tek�cie
	* @param textColor kolor tekstu
	* @param textBold okre�la czy tekst powinien by� napisany pogrubion� czcionk�
	* @param textUnderline okre�la czy tekst powinien by� podkre�lony
	*/
	virtual void setText(sf::FloatRect parentDim, sf::Vector2f relative, std::string text = "Text", std::string nameFontFile = "times.ttf",
		unsigned int textSize = 15, sf::Color textColor = sf::Color::Black, sf::Text::Style textBold = sf::Text::Style::Regular,
		sf::Text::Style textUnderline = sf::Text::Style::Regular);

	/**
	* Metoda pozwalaj�ca zmniejszy� rozmiar liter w tek�cie
	* celem zmieszczenia tekstu w obr�bie przewidzianej przestrzeni
	* @param textbounds obszar w ktr�ym mo�e pojawi� si� tekst
	* @param glyphbounds aktualne wymiary znaku
	* @param spacing odleg�o�� mi�dzy liniami tekstu
	* @return true gdy uda�o si� zmniejszy� tekst by zmie��i� go w granicach obszaru jednocze�nie nie
	* przekraczaj�c minimalnego rozmiaru, false w przypadku przeciwnym
	*/
	bool adjustText(sf::FloatRect textbounds, sf::FloatRect glyphbounds, float spacing);

	/**
	* Metoda pozwalaj�ca zwi�kszy� rozmiar liter w tek�cie
	* gdy zmniejszana jest jego dugo��
	*/
	void readjustText();

	/**
	* Metoda pozwalaj�ca doda� kolejn� liter� do tekstu
	* @param analyzed kod litery
	*/
	void addTextInRange(sf::Uint32 analyzed);

	/**
	* Metoda ustawiaj�ca domy�lny tekst
	*/
	void setInfoString();

	/**
	* Metoda usuwaj�ca domy�lny tekst
	*/
	void unsetInfoString();

	/**
	* Metoda usuwaj�ca domy�lny tekst
	*/
	void setLocalOffset(sf::Vector2f relative);
public:

	/**
	* Metoda modyfikuj�ca tekst w zale�no�ci od przekazanego znaku
	* @param letter kod przekazanego znaku
	*/
	void modifyText(sf::Uint32 letter);

	/**
	* Metoda resetuj�ca pole tekstowe
	*/
	void reset();

	/**
	* Metoda zwracaj�ca warto�� aktualnie przechowywanego tekstu
	* @return warto�� aktualnie przechowywanego tekstu
	*/
	std::string getMyString() { return myText.getString().toAnsiString(); };

	/**
	* Metoda sprawdzaj�ca czy do pola tekstowego wpisano warto��
	* @return true je�eli wpisano, false je�eli nie wpisano
	*/
	bool checkIfEntered();
};
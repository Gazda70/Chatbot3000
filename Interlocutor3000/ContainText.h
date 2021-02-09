#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

/**
* Klasa s³u¿¹ca do obs³ugi tekstu
*/
class ContainText : public sf::Drawable
{
protected:
	/**
	* Zmienna okreœlaj¹ca czy wyœwietlany
	* jest domyœlny tekst
	*/
	bool isinfoString;

	/**
	* Zmienna okreœlaj¹ca czy pole tekstowe
	* jest aktywne
	*/
	bool textfieldActive;

	/**
	* Wektor par iloœæ znaków w tekœcie-rozmiar tekstu
	* s³u¿y do powrotu do wczeœniejszego rozmiaru czcionki
	* przy usuwaniu znaków
	*/
	std::vector<std::pair<int, int>> adjustments;

	/**
	* Domyœlny napis
	*/
	std::string infoString;

	/**
	* Aktualna odleg³oœæ jaka pozosta³a do koñca obszaru
	* w którym mo¿e pojawiaæ sie tekst
	*/
	float actualWidth;

	/**
	* Aktualna wysokoœæ tekstu
	*/
	float textHeight;

	/**
	* Przechowywany tekst
	*/
	sf::Text myText;

	/**
	* U¿ywana czcionka
	*/
	sf::Font myFont;

	/**
	* Wymiary kszta³tu w którym ma znaleŸæ
	* siê pole tekstowe
	*/
	sf::FloatRect parent;

	/**
	* Pozycja tekstu w obrêbie kszta³tu
	*/
	sf::Vector2f textLocalOffset;

	/**
	* Aktualny rozmiar liter w tekœcie
	*/
	unsigned int selectedSize;

	/**
	* Minimalny rozmiar liter w tekœcie
	* pozwalaj¹cy na dobr¹ widocznoœæ
	*/
	unsigned int minimalSize;

	/**
	* Konstruktor
	* @param parentDim wymiary ksztaltu w który ma zostaæ wpisany tekst
	* @param relative wektor z wartoœciami przez które nale¿y przemno¿yæ wymiary kszta³tu by
	* otrzymaæ po³o¿enie tekstu wzglêdem kszta³tu
	* @param text tekst do wyœwietlenia w obrêbie kszta³u
	* @param nameFontFile nazwa pliku z czcionk¹ do stworzenia tekstu
	* @param textSize rozmiar liter w tekœcie
	* @param textColor kolor tekstu
	* @param textBold okreœla czy tekst powinien byæ napisany pogrubion¹ czcionk¹
	* @param textUnderline okreœla czy tekst powinien byæ podkreœlony
	*/
	virtual void setText(sf::FloatRect parentDim, sf::Vector2f relative, std::string text = "Text", std::string nameFontFile = "times.ttf",
		unsigned int textSize = 15, sf::Color textColor = sf::Color::Black, sf::Text::Style textBold = sf::Text::Style::Regular,
		sf::Text::Style textUnderline = sf::Text::Style::Regular);

	/**
	* Metoda pozwalaj¹ca zmniejszyæ rozmiar liter w tekœcie
	* celem zmieszczenia tekstu w obrêbie przewidzianej przestrzeni
	* @param textbounds obszar w ktróym mo¿e pojawiæ siê tekst
	* @param glyphbounds aktualne wymiary znaku
	* @param spacing odleg³oœæ miêdzy liniami tekstu
	* @return true gdy uda³o siê zmniejszyæ tekst by zmieœæiæ go w granicach obszaru jednoczeœnie nie
	* przekraczaj¹c minimalnego rozmiaru, false w przypadku przeciwnym
	*/
	bool adjustText(sf::FloatRect textbounds, sf::FloatRect glyphbounds, float spacing);

	/**
	* Metoda pozwalaj¹ca zwiêkszyæ rozmiar liter w tekœcie
	* gdy zmniejszana jest jego dugoœæ
	*/
	void readjustText();

	/**
	* Metoda pozwalaj¹ca dodaæ kolejn¹ literê do tekstu
	* @param analyzed kod litery
	*/
	void addTextInRange(sf::Uint32 analyzed);

	/**
	* Metoda ustawiaj¹ca domyœlny tekst
	*/
	void setInfoString();

	/**
	* Metoda usuwaj¹ca domyœlny tekst
	*/
	void unsetInfoString();

	/**
	* Metoda usuwaj¹ca domyœlny tekst
	*/
	void setLocalOffset(sf::Vector2f relative);
public:

	/**
	* Metoda modyfikuj¹ca tekst w zale¿noœci od przekazanego znaku
	* @param letter kod przekazanego znaku
	*/
	void modifyText(sf::Uint32 letter);

	/**
	* Metoda resetuj¹ca pole tekstowe
	*/
	void reset();

	/**
	* Metoda zwracaj¹ca wartoœæ aktualnie przechowywanego tekstu
	* @return wartoœæ aktualnie przechowywanego tekstu
	*/
	std::string getMyString() { return myText.getString().toAnsiString(); };

	/**
	* Metoda sprawdzaj¹ca czy do pola tekstowego wpisano wartoœæ
	* @return true je¿eli wpisano, false je¿eli nie wpisano
	*/
	bool checkIfEntered();
};
#pragma once
#include <string>
#include <regex>
#include <random>
#include <chrono>
#include <functional>
#include <fstream>
#include <iostream>
#include <queue>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

/**
* Struktura do przechowywania danych inicjalizuj¹cych obiekt klasy Button,
* podane wartoœci liczbowe to mno¿niki dla wartoœci okreœlaj¹cych
* rozmiar sceny na której taki obiekt ma zostaæ narysowany
*/
struct ButtonInitializer
{
	std::string name;/**< nazwa*/
	float x;/**< po³o¿enie w poziomie*/
	float y;/**< po³o¿enie w pionie*/
	float w;/**< szerokoœæ*/
	float h;/**< wysokoœæ*/
	sf::Color color;/**< kolor*/
	std::string font;/**< nazwa pliku z czcionk¹*/
	float textsize;/**< rozmiar liter*/
	sf::Color textcolor;/**< kolor tekstu*/
	float textx;/**< po³o¿enie tekstu w poziomie*/
	float texty;/**< po³o¿enie tekstu w pionie*/
};

/**
* Struktura do przechowywania danych inicjalizuj¹cych obiekt klasy Field,
* podane wartoœci liczbowe to mno¿niki dla wartoœci okreœlaj¹cych
* rozmiar sceny na której taki obiekt ma zostaæ narysowany
* oraz widoku na teksturê udostêpnionego u¿ytkownikowi
*/
struct FieldInitializer
{
	float x_axis;/**< po³o¿enie w poziomie*/
	float y_axis;/**< po³o¿enie w pionie*/
	float width;/**< szerokoœæ*/
	float height;/**< wysokoœæ*/
	sf::Color color;/**< kolor*/
	float vx;/**< po³o¿enie w poziomie widoku*/
	float vy;/**< po³o¿enie w pionie widoku*/
	float vw;/**< szerokoœæ widoku*/
	float vh;/**< wysokoœæ widoku*/
};

/**
* Struktura do przechowywania danych inicjalizuj¹cych obiekt klasy Avatar,
* podane wartoœci liczbowe to mno¿niki dla wartoœci okreœlaj¹cych
* rozmiar sceny na której taki obiekt ma zostaæ narysowany
* oraz wymiary i po³o¿enie skojarzonego z nim dymku czatu
*/
struct AvatarInitializer
{
	float userx;/**< po³o¿enie w poziomie awatara u¿ytkownika*/
	float usery;/**< po³o¿enie w pionie awatara u¿ytkownika*/
	float botx;/**< po³o¿enie w poziomie awatara bota*/
	float boty;/**< po³o¿enie w pionie awatara bota*/
	float balluserx;/**< po³o¿enie w poziomie dymku czatu skojarzonego z awatarem u¿ytkownika*/
	float ballusery;/**< po³o¿enie w pionie dymku czatu skojarzonego z awatarem u¿ytkownika*/
	float ballbotx;/**< po³o¿enie w poziomie dymku czatu skojarzonego z awatarem bota*/
	float ballboty;/**< po³o¿enie w pionie dymku czatu skojarzonego z awatarem bota*/
	int charsize;/**< rozmiar znaku w tekœcie w dymku czatu*/
	float posx;/**< po³o¿enie w poziomie tekstu w dymku czatu*/
	float posy;/**< po³o¿enie w pionie tekstu w dymku czatu*/
};

/**
* Struktura do przechowywania danych inicjalizuj¹cych obiekt klasy SpeechBalloon,
* podane wartoœci liczbowe to mno¿niki dla wartoœci okreœlaj¹cych
* rozmiar sceny na której taki obiekt ma zostaæ narysowany
*/
struct SpeechBalloonInitializer
{
	float parentx;/**< po³o¿enie w poziomie kszta³tu skojarzonego z dymkiem*/
	float parenty;/**< po³o¿enie w pionie kszta³tu skojarzonego z dymkiem*/
	float charsize;/**< rozmiar znaku w tekœcie w dymku czatu*/
	float posx;/**< po³o¿enie w poziomie tekstu w dymku czatu*/
	float posy;/**< po³o¿enie w pionie tekstu w dymku czatu*/
};

/**
* Klasa - singleton przechowuj¹ca informacje o elementach interfejsu graficznego
* i udostêpniaj¹ca metody do uzyskiwania tych informacji
*/
class SettingsContainer
{
private:
	/**
	* Kolejka z instancjami struktury inicjalizuj¹cej obiekty
	* klasy Button
	*/
	std::deque<ButtonInitializer> buttonInitializers;

	/**
	* Kolejka z instancjami struktury inicjalizuj¹cej obiekty
	* klasy Field
	*/
	std::deque<FieldInitializer> fieldInitializers;

	/**
	* Kolejka z instancjami struktury inicjalizuj¹cej obiekty
	* klasy Avatar
	*/
	std::deque<AvatarInitializer> avatarInitializers;

	/**
	* Kolejka z instancjami struktury inicjalizuj¹cej obiekty
	* klasy Speechballoon
	*/
	std::deque<SpeechBalloonInitializer> spInitializers;
	std::string sessionFile;/**< plik w którym nale¿y zapisaæ aktualn¹ sesjê konwersacji*/
	std::string username;/**< nazwa u¿ytkownika*/
	std::string botname;/**< nazwa bota*/
	sf::Font generalFont;/**< Krój pisma uzywany przez napisy w projekcie*/
public:

	/**
	* Metoda daj¹ca dostêp do jedynej instancji klasy
	*/
	static SettingsContainer& getInstance();

	/**
	* Metoda sczytuj¹ca plik z informacjami do inicjalizacji
	* obiektów klasy Button
	* @param filename nazwa pliku
	*/
	void readButtonInitializationFile(const char* filename);

	/**
	* Metoda sczytuj¹ca plik z informacjami do inicjalizacji
	* obiektów klasy Field
	* @param filename nazwa pliku
	*/
	void readFieldInitializationFile(const char* filename);

	/**
	* Metoda sczytuj¹ca plik z informacjami do inicjalizacji
	* obiektów klasy Avatar
	* @param filename nazwa pliku
	*/
	void readAvatarInitializationFile(const char* filename);

	/**
	* Metoda sczytuj¹ca plik z informacjami do inicjalizacji
	* obiektów klasy SpeechBalloon
	* @param filename nazwa pliku
	*/
	void readSpeechBalloonInitializationFile(const char* filename);

	/**
	* Metoda pobieraj¹ca z kolejki pierwszy element
	* bêd¹cy instancj¹ struktury do inicjalizacji
	* obiektów klasy Button
	* @return instancja struktury
	*/
	ButtonInitializer initsButtonFront();

	/**
	* Metoda pobieraj¹ca z kolejki pierwszy element
	* bêd¹cy instancj¹ struktury do inicjalizacji
	* obiektów klasy Field
	* @return instancja struktury
	*/
	FieldInitializer initsFieldFront();

	/**
	* Metoda pobieraj¹ca z kolejki pierwszy element
	* bêd¹cy instancj¹ struktury do inicjalizacji
	* obiektów klasy Avatar
	* @return instancja struktury
	*/
	AvatarInitializer initsAvatarFront();

	/**
	* Metoda pobieraj¹ca z kolejki pierwszy element
	* bêd¹cy instancj¹ struktury do inicjalizacji
	* obiektów klasy SpeechBallon
	* @return instancja struktury
	*/
	SpeechBalloonInitializer initsSPFront();

	/**
	* Metoda zwracaj¹ca obiekt klasy Color
	* na podstawie przekazanego s³owa
	* @param indicator przekazane s³owo - nazwa koloru
	* @return obiekt klasy Color
	*/
	sf::Color colorFromString(std::string indicator);

	/**
	* Metoda ustawiaj¹ca nazwê pliku w którym
	* powinna zostaæ zapisana zawartoœæ 
	* aktualnej konwersacji
	* @param filename nazwa pliku do zapisu 
	*/
	void setSessionFile(const char* filename) { sessionFile = filename; };

	/**
	* Metoda zwracaj¹ca nazwê pliku w którym
	* powinna zostaæ zapisana zawartoœæ
	* aktualnej konwersacji
	* @return nazwa pliku 
	*/
	std::string getSessionFile() { return sessionFile; };

	/**
	* Metoda ustawiaj¹ca nazwê u¿ytkownika
	* @param usrnm nazwa u¿ytkownika
	*/
	void setUsername(std::string usrnm) { username = usrnm; };

	/**
	* Metoda zwracaj¹ca nazwê u¿ytkownika
	* @return usrnm nazwa u¿ytkownika
	*/
	std::string getUsername() { return username; };

	/**
	* Metoda ustawiaj¹ca nazwê bota
	* @param btnm nazwa bota
	*/
	void setBotname(std::string btnm) { botname = btnm; };

	/**
	* Metoda zwracaj¹ca nazwê bota
	* @return  nazwa u¿ytkownika
	*/
	std::string getBotname() { return botname; };

	/**
	* Metoda ustawiaj¹ca wartoœæ pliku z 
	* krojem pisma
	* @param filename nazwa pliku
	*/
	void setFont(const char* filename);

	/**
	* Metoda zwracaj¹c¹ referencjê do obiektu
	* klasy Font
	* @return obiekt klasy Font
	*/
	sf::Font& getFont();

	/**
	* Metoda zwracaj¹c¹ pseudolosow¹ liczbê ca³kowit¹
	* z zakresu od zera do maksimum
	* @param max wartoœæ maksimum
	* @return pseudolosowa wartoœæ ca³kowita
	*/
	int getRndIntInRange(int max);
};


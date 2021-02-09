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
* Struktura do przechowywania danych inicjalizuj�cych obiekt klasy Button,
* podane warto�ci liczbowe to mno�niki dla warto�ci okre�laj�cych
* rozmiar sceny na kt�rej taki obiekt ma zosta� narysowany
*/
struct ButtonInitializer
{
	std::string name;/**< nazwa*/
	float x;/**< po�o�enie w poziomie*/
	float y;/**< po�o�enie w pionie*/
	float w;/**< szeroko��*/
	float h;/**< wysoko��*/
	sf::Color color;/**< kolor*/
	std::string font;/**< nazwa pliku z czcionk�*/
	float textsize;/**< rozmiar liter*/
	sf::Color textcolor;/**< kolor tekstu*/
	float textx;/**< po�o�enie tekstu w poziomie*/
	float texty;/**< po�o�enie tekstu w pionie*/
};

/**
* Struktura do przechowywania danych inicjalizuj�cych obiekt klasy Field,
* podane warto�ci liczbowe to mno�niki dla warto�ci okre�laj�cych
* rozmiar sceny na kt�rej taki obiekt ma zosta� narysowany
* oraz widoku na tekstur� udost�pnionego u�ytkownikowi
*/
struct FieldInitializer
{
	float x_axis;/**< po�o�enie w poziomie*/
	float y_axis;/**< po�o�enie w pionie*/
	float width;/**< szeroko��*/
	float height;/**< wysoko��*/
	sf::Color color;/**< kolor*/
	float vx;/**< po�o�enie w poziomie widoku*/
	float vy;/**< po�o�enie w pionie widoku*/
	float vw;/**< szeroko�� widoku*/
	float vh;/**< wysoko�� widoku*/
};

/**
* Struktura do przechowywania danych inicjalizuj�cych obiekt klasy Avatar,
* podane warto�ci liczbowe to mno�niki dla warto�ci okre�laj�cych
* rozmiar sceny na kt�rej taki obiekt ma zosta� narysowany
* oraz wymiary i po�o�enie skojarzonego z nim dymku czatu
*/
struct AvatarInitializer
{
	float userx;/**< po�o�enie w poziomie awatara u�ytkownika*/
	float usery;/**< po�o�enie w pionie awatara u�ytkownika*/
	float botx;/**< po�o�enie w poziomie awatara bota*/
	float boty;/**< po�o�enie w pionie awatara bota*/
	float balluserx;/**< po�o�enie w poziomie dymku czatu skojarzonego z awatarem u�ytkownika*/
	float ballusery;/**< po�o�enie w pionie dymku czatu skojarzonego z awatarem u�ytkownika*/
	float ballbotx;/**< po�o�enie w poziomie dymku czatu skojarzonego z awatarem bota*/
	float ballboty;/**< po�o�enie w pionie dymku czatu skojarzonego z awatarem bota*/
	int charsize;/**< rozmiar znaku w tek�cie w dymku czatu*/
	float posx;/**< po�o�enie w poziomie tekstu w dymku czatu*/
	float posy;/**< po�o�enie w pionie tekstu w dymku czatu*/
};

/**
* Struktura do przechowywania danych inicjalizuj�cych obiekt klasy SpeechBalloon,
* podane warto�ci liczbowe to mno�niki dla warto�ci okre�laj�cych
* rozmiar sceny na kt�rej taki obiekt ma zosta� narysowany
*/
struct SpeechBalloonInitializer
{
	float parentx;/**< po�o�enie w poziomie kszta�tu skojarzonego z dymkiem*/
	float parenty;/**< po�o�enie w pionie kszta�tu skojarzonego z dymkiem*/
	float charsize;/**< rozmiar znaku w tek�cie w dymku czatu*/
	float posx;/**< po�o�enie w poziomie tekstu w dymku czatu*/
	float posy;/**< po�o�enie w pionie tekstu w dymku czatu*/
};

/**
* Klasa - singleton przechowuj�ca informacje o elementach interfejsu graficznego
* i udost�pniaj�ca metody do uzyskiwania tych informacji
*/
class SettingsContainer
{
private:
	/**
	* Kolejka z instancjami struktury inicjalizuj�cej obiekty
	* klasy Button
	*/
	std::deque<ButtonInitializer> buttonInitializers;

	/**
	* Kolejka z instancjami struktury inicjalizuj�cej obiekty
	* klasy Field
	*/
	std::deque<FieldInitializer> fieldInitializers;

	/**
	* Kolejka z instancjami struktury inicjalizuj�cej obiekty
	* klasy Avatar
	*/
	std::deque<AvatarInitializer> avatarInitializers;

	/**
	* Kolejka z instancjami struktury inicjalizuj�cej obiekty
	* klasy Speechballoon
	*/
	std::deque<SpeechBalloonInitializer> spInitializers;
	std::string sessionFile;/**< plik w kt�rym nale�y zapisa� aktualn� sesj� konwersacji*/
	std::string username;/**< nazwa u�ytkownika*/
	std::string botname;/**< nazwa bota*/
	sf::Font generalFont;/**< Kr�j pisma uzywany przez napisy w projekcie*/
public:

	/**
	* Metoda daj�ca dost�p do jedynej instancji klasy
	*/
	static SettingsContainer& getInstance();

	/**
	* Metoda sczytuj�ca plik z informacjami do inicjalizacji
	* obiekt�w klasy Button
	* @param filename nazwa pliku
	*/
	void readButtonInitializationFile(const char* filename);

	/**
	* Metoda sczytuj�ca plik z informacjami do inicjalizacji
	* obiekt�w klasy Field
	* @param filename nazwa pliku
	*/
	void readFieldInitializationFile(const char* filename);

	/**
	* Metoda sczytuj�ca plik z informacjami do inicjalizacji
	* obiekt�w klasy Avatar
	* @param filename nazwa pliku
	*/
	void readAvatarInitializationFile(const char* filename);

	/**
	* Metoda sczytuj�ca plik z informacjami do inicjalizacji
	* obiekt�w klasy SpeechBalloon
	* @param filename nazwa pliku
	*/
	void readSpeechBalloonInitializationFile(const char* filename);

	/**
	* Metoda pobieraj�ca z kolejki pierwszy element
	* b�d�cy instancj� struktury do inicjalizacji
	* obiekt�w klasy Button
	* @return instancja struktury
	*/
	ButtonInitializer initsButtonFront();

	/**
	* Metoda pobieraj�ca z kolejki pierwszy element
	* b�d�cy instancj� struktury do inicjalizacji
	* obiekt�w klasy Field
	* @return instancja struktury
	*/
	FieldInitializer initsFieldFront();

	/**
	* Metoda pobieraj�ca z kolejki pierwszy element
	* b�d�cy instancj� struktury do inicjalizacji
	* obiekt�w klasy Avatar
	* @return instancja struktury
	*/
	AvatarInitializer initsAvatarFront();

	/**
	* Metoda pobieraj�ca z kolejki pierwszy element
	* b�d�cy instancj� struktury do inicjalizacji
	* obiekt�w klasy SpeechBallon
	* @return instancja struktury
	*/
	SpeechBalloonInitializer initsSPFront();

	/**
	* Metoda zwracaj�ca obiekt klasy Color
	* na podstawie przekazanego s�owa
	* @param indicator przekazane s�owo - nazwa koloru
	* @return obiekt klasy Color
	*/
	sf::Color colorFromString(std::string indicator);

	/**
	* Metoda ustawiaj�ca nazw� pliku w kt�rym
	* powinna zosta� zapisana zawarto�� 
	* aktualnej konwersacji
	* @param filename nazwa pliku do zapisu 
	*/
	void setSessionFile(const char* filename) { sessionFile = filename; };

	/**
	* Metoda zwracaj�ca nazw� pliku w kt�rym
	* powinna zosta� zapisana zawarto��
	* aktualnej konwersacji
	* @return nazwa pliku 
	*/
	std::string getSessionFile() { return sessionFile; };

	/**
	* Metoda ustawiaj�ca nazw� u�ytkownika
	* @param usrnm nazwa u�ytkownika
	*/
	void setUsername(std::string usrnm) { username = usrnm; };

	/**
	* Metoda zwracaj�ca nazw� u�ytkownika
	* @return usrnm nazwa u�ytkownika
	*/
	std::string getUsername() { return username; };

	/**
	* Metoda ustawiaj�ca nazw� bota
	* @param btnm nazwa bota
	*/
	void setBotname(std::string btnm) { botname = btnm; };

	/**
	* Metoda zwracaj�ca nazw� bota
	* @return  nazwa u�ytkownika
	*/
	std::string getBotname() { return botname; };

	/**
	* Metoda ustawiaj�ca warto�� pliku z 
	* krojem pisma
	* @param filename nazwa pliku
	*/
	void setFont(const char* filename);

	/**
	* Metoda zwracaj�c� referencj� do obiektu
	* klasy Font
	* @return obiekt klasy Font
	*/
	sf::Font& getFont();

	/**
	* Metoda zwracaj�c� pseudolosow� liczb� ca�kowit�
	* z zakresu od zera do maksimum
	* @param max warto�� maksimum
	* @return pseudolosowa warto�� ca�kowita
	*/
	int getRndIntInRange(int max);
};


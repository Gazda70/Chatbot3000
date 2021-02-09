#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ContainText.h"
#include "SpeechBalloon.h"
#include "Avatar.h"
#include "SettingsContainer.h"
using namespace sf;
/**
* Klasa enum odpowiadaj�ca za rozr�nianie pomi�dzy u�ytkownikiem a botem
*/
enum class Interlocutors
{
	Uzytkownik, Bot
};

/**
* Klasa odpowiedzialna za obs�ug� pola konwersacji
*/
class ConversationField
{
private:

	/**
	* Struktura zawieraj�ca informacje do inicjalizacji awatara
	*/
	AvatarInitializer init;

	/**
	* Wektor instancji awatara u�ytkownika, ka�da odpowiada jednej wiadomo�ci
	*/
	std::vector<Avatar*> userInstances;

	/**
	* Wektor instancji awatara bota, ka�da odpowiada jednej wiadomo�ci
	*/
	std::vector<Avatar*> botInstances;

	/**
	* Tekstura na kt�rej narysowane zostaj� awatary i dymki czatu
	*/
	sf::RenderTexture* field;

	/**
	* Szeroko�� tekstury
	*/
	float fieldX;

	/**
	* Wysoko�� tekstury
	*/
	float fieldY;

	/**
	* Nazwa u�ytkownika
	*/
	std::string username;

	/**
	* Nazwa bota
	*/
	std::string botname;

	/**
	* Przesuni�cie spowodowane scrollowaniem
	*/
	float scrollOffset;

	/**
	* Metoda s�u��ca do narysowania awatar�w na teksturze
	*/
	void drawAvatars() const;
public:
	/**
	* Konstruktor
	* @param x_axis wsp�rz�dna pozioma po�o�enia kszta�tu
	* @param y_axis wsp�rz�dna pionowa po�o�enia kszta�tu
	* @param width szeroko�� kszta�tu
	* @param height wysoko�� kszta�tu
	* @param color kolor kszta�tu
	*/
	ConversationField(float x_axis = 0.0, float y_axis = 0.0, float width = 500.0, float height = 500.0, Color color = Color::Blue);

	/**
	* Metoda ustawiaj�ca awatar u�ytkownika
	* @param usersaid wiadomo�� do wy�wietlenia w dymku czatu
	* @param avatarTexture tekstura do okre�lenia awatara
	*/
	void setUserAvatar(std::string usersaid, const char* avatarTexture);

	/**
	* Metoda ustawiaj�ca awatar bota
	* @param botsaid wiadomo�� do wy�wietlenia w dymku czatu
	* @param avatarTexture tekstura do okre�lenia awatara
	*/
	void setBotAvatar(std::string botsaid, const char* avatarTexture);

	/**
	* Metoda zwracaj�ca bazowe wsp�rz�dne po�o�enia
	* awatara bota lub u�ytkownika
	* @param need okre�la czy zwr�ci� warto�ci dla u�ytkownika czy bota
	* @return bazowe wsp�rz�dne dla odpowiedniego awatara
	*/
	Vector2f getAvatarCoords(Interlocutors need);

	/**
	* Metoda przesuwa widok w zale�no�ci od u�ycia scrolla
	* @param delta przesuni�cie widoku
	* @param myView obiekt reprezentuj�cy widok
	*/
	void scrollView(float delta, sf::View& myView);

	/**
	* Metoda resetuje zawarto�� pola konwersacji
	*/
	void reset();

	/**
	* Metoda rysuje elementy na teksturze a nast�pnie tworzy obiekt
	* klasy Sprite przy u�yciu tej tekstury
	* @return sprite utworzony z tekstury
	*/
	sf::Sprite drawField();

	/**
	* Destruktor, zwalnia zaalokowan� dynamicznie pami��
	*/
	~ConversationField();
};
#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "ContainText.h"
#include "SpeechBalloon.h"
#include "Avatar.h"
#include "SettingsContainer.h"
using namespace sf;
/**
* Klasa enum odpowiadaj¹ca za rozró¿nianie pomiêdzy u¿ytkownikiem a botem
*/
enum class Interlocutors
{
	Uzytkownik, Bot
};

/**
* Klasa odpowiedzialna za obs³ugê pola konwersacji
*/
class ConversationField
{
private:

	/**
	* Struktura zawieraj¹ca informacje do inicjalizacji awatara
	*/
	AvatarInitializer init;

	/**
	* Wektor instancji awatara u¿ytkownika, ka¿da odpowiada jednej wiadomoœci
	*/
	std::vector<Avatar*> userInstances;

	/**
	* Wektor instancji awatara bota, ka¿da odpowiada jednej wiadomoœci
	*/
	std::vector<Avatar*> botInstances;

	/**
	* Tekstura na której narysowane zostaj¹ awatary i dymki czatu
	*/
	sf::RenderTexture* field;

	/**
	* Szerokoœæ tekstury
	*/
	float fieldX;

	/**
	* Wysokoœæ tekstury
	*/
	float fieldY;

	/**
	* Nazwa u¿ytkownika
	*/
	std::string username;

	/**
	* Nazwa bota
	*/
	std::string botname;

	/**
	* Przesuniêcie spowodowane scrollowaniem
	*/
	float scrollOffset;

	/**
	* Metoda s³u¿¹ca do narysowania awatarów na teksturze
	*/
	void drawAvatars() const;
public:
	/**
	* Konstruktor
	* @param x_axis wspó³rzêdna pozioma po³o¿enia kszta³tu
	* @param y_axis wspó³rzêdna pionowa po³o¿enia kszta³tu
	* @param width szerokoœæ kszta³tu
	* @param height wysokoœæ kszta³tu
	* @param color kolor kszta³tu
	*/
	ConversationField(float x_axis = 0.0, float y_axis = 0.0, float width = 500.0, float height = 500.0, Color color = Color::Blue);

	/**
	* Metoda ustawiaj¹ca awatar u¿ytkownika
	* @param usersaid wiadomoœæ do wyœwietlenia w dymku czatu
	* @param avatarTexture tekstura do okreœlenia awatara
	*/
	void setUserAvatar(std::string usersaid, const char* avatarTexture);

	/**
	* Metoda ustawiaj¹ca awatar bota
	* @param botsaid wiadomoœæ do wyœwietlenia w dymku czatu
	* @param avatarTexture tekstura do okreœlenia awatara
	*/
	void setBotAvatar(std::string botsaid, const char* avatarTexture);

	/**
	* Metoda zwracaj¹ca bazowe wspó³rzêdne po³o¿enia
	* awatara bota lub u¿ytkownika
	* @param need okreœla czy zwróciæ wartoœci dla u¿ytkownika czy bota
	* @return bazowe wspó³rzêdne dla odpowiedniego awatara
	*/
	Vector2f getAvatarCoords(Interlocutors need);

	/**
	* Metoda przesuwa widok w zale¿noœci od u¿ycia scrolla
	* @param delta przesuniêcie widoku
	* @param myView obiekt reprezentuj¹cy widok
	*/
	void scrollView(float delta, sf::View& myView);

	/**
	* Metoda resetuje zawartoœæ pola konwersacji
	*/
	void reset();

	/**
	* Metoda rysuje elementy na teksturze a nastêpnie tworzy obiekt
	* klasy Sprite przy u¿yciu tej tekstury
	* @return sprite utworzony z tekstury
	*/
	sf::Sprite drawField();

	/**
	* Destruktor, zwalnia zaalokowan¹ dynamicznie pamiêæ
	*/
	~ConversationField();
};
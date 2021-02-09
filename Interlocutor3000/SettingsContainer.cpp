#include "SettingsContainer.h"

using namespace sf;

SettingsContainer& SettingsContainer::getInstance()
{
	static SettingsContainer single = SettingsContainer();
	return single;
}

void SettingsContainer::readButtonInitializationFile(const char* filename)
{
	ButtonInitializer toInitialize;
	std::regex format("name:([a-zA-Z0-9 ]+) x:([0-9]+\.[0-9]+) y:([0-9]+\.[0-9]+) w:([0-9]+\.[0-9]+) h:([0-9]+\.[0-9]+) color:([a-zA-Z0-9]+) font:(.+)"
		"textsize:([0-9]+\.[0-9]+) textcolor:([a-zA-Z0-9]+) textx:([0-9]+\.[0-9]+) texty:([0-9]+\.[0-9]+)");
	std::smatch match;
	std::ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string input;
			std::getline(file, input);
			if (std::regex_match(input, match, format))
			{
				toInitialize.name = match[1].str();
				toInitialize.x = std::stof(match[2].str());
				toInitialize.y = std::stof(match[3].str());
				toInitialize.w = std::stof(match[4].str());
				toInitialize.h = std::stof(match[5].str());
				toInitialize.color = colorFromString(match[6].str());
				toInitialize.font = match[7].str();
				toInitialize.textsize = std::stof(match[8].str());
				toInitialize.textcolor = colorFromString(match[9].str());
				toInitialize.textx = std::stof(match[10].str());
				toInitialize.texty = std::stof(match[11].str());
				buttonInitializers.push_back(toInitialize);
			}
		}
		file.close();
	}
}

void SettingsContainer::readFieldInitializationFile(const char* filename)
{
	FieldInitializer toInitialize;
	std::regex format("x:([0-9]+\.[0-9]+) y:([0-9]+\.[0-9]+) w:([0-9]+\.[0-9]+) h:([0-9]+\.[0-9]+) color:([a-zA-Z]+) vx:([0-9]+\.[0-9]+) vy:([0-9]+\.[0-9]+) vw:([0-9]+\.[0-9]+) vh:([0-9]+\.[0-9]+)");
	std::smatch match;
	std::ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string input;
			std::getline(file, input);
			if (std::regex_match(input, match, format))
			{
				toInitialize.x_axis = std::stof(match[1].str());
				toInitialize.y_axis = std::stof(match[2].str());
				toInitialize.width = std::stof(match[3].str());
				toInitialize.height = std::stof(match[4].str());
				toInitialize.color = colorFromString(match[5].str());
				toInitialize.vx = std::stof(match[6].str());
				toInitialize.vy = std::stof(match[7].str());
				toInitialize.vw = std::stof(match[8].str());
				toInitialize.vh = std::stof(match[9].str());
			}
			fieldInitializers.push_back(toInitialize);
		}
		file.close();
	}
}

void SettingsContainer::readAvatarInitializationFile(const char* filename)
{
	AvatarInitializer toInitialize;
	std::regex format("userx:([0-9]+\.[0-9]+) usery:([0-9]+\.[0-9]+) botx:([0-9]+\.[0-9]+) boty:([0-9]+\.[0-9]+)" 
		" balluserx:([0-9]+\.[0-9]+) ballusery:([0-9]+\.[0-9]+) ballbotx:([0-9]+\.[0-9]+) ballboty:([0-9]+\.[0-9]+) charsize:([0-9]+\.[0-9]+) posx:([0-9]+\.[0-9]+) posy:([0-9]+\.[0-9]+)");
	std::smatch match;
	std::ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string input;
			std::getline(file, input);
			if (std::regex_match(input, match, format))
			{
				toInitialize.userx = std::stof(match[1].str());
				toInitialize.usery  = std::stof(match[2].str());
				toInitialize.botx = std::stof(match[3].str());
				toInitialize.boty = std::stof(match[4].str());
				toInitialize.balluserx = std::stof(match[5].str());
				toInitialize.ballusery = std::stof(match[6].str());
				toInitialize.ballbotx = std::stof(match[7].str());
				toInitialize.ballboty = std::stof(match[8].str());
				toInitialize.charsize = std::stof(match[9].str());
				toInitialize.posx = std::stof(match[10].str());
				toInitialize.posy = std::stof(match[11].str());
			}
			avatarInitializers.push_back(toInitialize);
		}
		file.close();
	}
}

void SettingsContainer::readSpeechBalloonInitializationFile(const char* filename)
{
	SpeechBalloonInitializer toInitialize;
	std::regex format("parentx:([0-9]+\.[0-9]+) parenty:([0-9]+\.[0-9]+) charsize:([0-9]+\.[0-9]+) posx:([0-9]+\.[0-9]+) posy:([0-9]+\.[0-9]+)");
	std::smatch match;
	std::ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string input;
			std::getline(file, input);
			if (std::regex_search(input, match, format))
			{
				toInitialize.parentx = std::stof(match[1].str());
				toInitialize.parenty = std::stof(match[2].str());
				toInitialize.charsize = std::stof(match[3].str());
				toInitialize.posx = std::stof(match[4].str());
				toInitialize.posy = std::stof(match[5].str());
			}
			spInitializers.push_back(toInitialize);
		}
		file.close();
	}
}

ButtonInitializer SettingsContainer::initsButtonFront()
{
		ButtonInitializer front;
		if (!buttonInitializers.empty())
		{
			front = buttonInitializers.front();
			buttonInitializers.pop_front();
		}
		return front;
}

FieldInitializer SettingsContainer::initsFieldFront()
{
	FieldInitializer front;
	if (!fieldInitializers.empty())
	{
		front = fieldInitializers.front();
		fieldInitializers.pop_front();
	}
	return front;
}

AvatarInitializer SettingsContainer::initsAvatarFront()
{
	AvatarInitializer front;
	if (!avatarInitializers.empty())
	{
		front = avatarInitializers.front();
		avatarInitializers.pop_front();
	}
	return front;
}

SpeechBalloonInitializer SettingsContainer::initsSPFront()
{
	SpeechBalloonInitializer front;
	if (!spInitializers.empty())
	{
		front = spInitializers.front();
		spInitializers.pop_front();
	}
	return front;
}


sf::Color SettingsContainer::colorFromString(std::string indicator)
{
	sf::Color toReturn;
	if (indicator == "Black")
	{
		toReturn = Color::Black;
	}
	else if (indicator == "Blue")
	{
		toReturn = Color::Blue;
	}
	else if (indicator == "Cyan")
	{
		toReturn = Color::Cyan;
	}
	else if (indicator == "Green")
	{
		toReturn = Color::Green;
	}
	else if (indicator == "Magenta")
	{
		toReturn = Color::Magenta;
	}
	else if (indicator == "Red")
	{
		toReturn = Color::Red;
	}
	else if (indicator =="White" )
	{
		toReturn = Color::White;
	}
	else if (indicator == "Yellow")
	{
		toReturn = Color::Yellow;
	}
	return toReturn;
}


void SettingsContainer::setFont(const char* filename)
{
	generalFont.loadFromFile(filename);
}

int SettingsContainer::getRndIntInRange(int max)
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	return generator()%max;
}

Font& SettingsContainer::getFont()
{
	return generalFont;
}

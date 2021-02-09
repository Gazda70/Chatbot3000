#include "ConvoManager.h"

void ConvoManager::setSessionContent(vector<pair<string, string>>& toSet)
{
	currentSession = toSet;
}

void ConvoManager::startSession()
{
	interlocutor.startSession();
}

void ConvoManager::endSession()
{
	interlocutor.endSession();
}

void ConvoManager::reloadConv()
{
	ifstream saved;
	saved.open(SettingsContainer::getInstance().getSessionFile());
	if (saved.is_open())
	{
		string message;
		string response;
		if (!saved.eof())
		{
			getline(saved, message);
			getline(saved, response);
			SettingsContainer::getInstance().setUsername(message);
			SettingsContainer::getInstance().setBotname(response);
		}
		while (!saved.eof())
		{
			getline(saved, message);
			getline(saved, response);
			if (message != "" && response != "")
			{
			std:pair<string, string> gotten;
				gotten.first = message;
				gotten.second = response;
				currentSession.push_back(gotten);
			}
		}
		saved.close();
	}
}

void ConvoManager::saveConv()
{
	drawPrevious = true;
	ofstream save;
	save.open(SettingsContainer::getInstance().getSessionFile());
	if (save.is_open())
	{
		save.clear();
		operator<<(save);
		save.close();
	}
	currentSession.clear();
}

void ConvoManager::trainBot(const char* filename)
{
	creator = CategoryCreator();
	interlocutor = Bot();
	creator.readFile(filename, interlocutor);
}

string ConvoManager::sendMessage(string message)
{
	Question asked = Question(message);
	std::string response =  interlocutor.respond(asked);
	std::pair<string, string> temp;
	temp.first = message;
	temp.second = response;
	currentSession.push_back(temp);
	return response;
}

std::ostream& ConvoManager::operator<<(std::ostream& os)
{
	os << SettingsContainer::getInstance().getUsername() << endl;
	os << SettingsContainer::getInstance().getBotname() << endl;
	for (vector<pair<string, string>>::iterator iter = currentSession.begin(); iter != currentSession.end(); iter++)
	{
		os << iter->first << endl;
		os << iter->second << endl;
	}
	return os;
}

ConvoManager& ConvoManager::operator=(const ConvoManager& toCopy)
{
	if(this != &toCopy)
	currentSession = toCopy.currentSession;
	return *this;
}


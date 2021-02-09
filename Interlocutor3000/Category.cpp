#include "Category.h"


Category::Category(string myName, vector<string>& myRes, vector<pair<string, int>>& myWords) :
	name(myName), actualResponse(myRes), sessionResp(myRes), score(0.0),Dictionary(myWords)
{
}

Category::Category(const Category& toCopy)
{
	this->name = toCopy.name;
	this->score = toCopy.score;
	this->actualResponse = toCopy.actualResponse;
	this->sessionResp = toCopy.sessionResp;
	this->dictionary = toCopy.dictionary;
}
int Category::getOccurences(std::string given)
{
	std::pair<bool, int> temp = inDict(given);
	if (temp.first)
		return temp.second;
	return 0;
}
void Category::startSession()
{ 
	sessionResp = actualResponse;
}
void Category::addResponses(std::vector<std::string>& newResps)
{
	for (vector<string>::iterator iter = newResps.begin(); iter != newResps.end(); ++iter)
	{
		actualResponse.push_back(*iter);
		sessionResp.push_back(*iter);
	}
}
void Category::endSession()
{
	sessionResp = actualResponse;
}
void Category::zeroScore()
{
	score = 0.0;
}
void Category::printResponses()
{
	int count = 1;
	for (vector<string>::iterator iter = actualResponse.begin(); iter != actualResponse.end(); ++iter)
	{
		cout << "Odpowiedz " << count << ": " << *iter << endl;
		count++;
	}
	cout << endl;
}
void Category::printWords()
{
	for (vector<pair<string,int>>::iterator baseIter = dictionary.begin(); baseIter != dictionary.end(); ++baseIter)
	{
		cout << baseIter->first << " : " << baseIter->second << endl;
	}
	cout << endl;
}

string Category::sayResponse()
{
	startSession();
	int ses = sessionResp.size();
	int act = actualResponse.size();
	int randIdx = SettingsContainer::getInstance().getRndIntInRange(sessionResp.size());
	return sessionResp[randIdx];
}
string Category::sayName()
{
	return name;
}

Category& Category::operator=(Category&& toMove)noexcept
{
	if (this != &toMove)
	{
		this->name = move(toMove.name);
		this->score = move(toMove.score);
		this->actualResponse = move(toMove.actualResponse);
		this->sessionResp = move(toMove.sessionResp);
		this->dictionary = move(toMove.dictionary);
		delete& toMove;
	}
	return *this;
}
Category& Category::operator=(const Category& toCopy) noexcept
{
	if (this != &toCopy)
	{
		this->name = toCopy.name;
		this->score = toCopy.score;
		this->actualResponse = toCopy.actualResponse;
		this->dictionary = toCopy.dictionary;
	}
	return *this;
}


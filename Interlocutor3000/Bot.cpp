#include "Bot.h"

string Bot::getResponse()
{
	Category champion = *base.begin();
	for (vector<Category>::iterator iterDict = base.begin(); iterDict != base.end(); iterDict++)
	{
		if (champion.getScore() < iterDict->getScore())
			champion = *iterDict;
	}
	return champion.sayResponse();
}

void Bot::addToBase(string& name, vector<string>& actualResponse, vector<pair<string, int>>& associatedWords)
{
	vector<Category>::iterator iterBase = base.begin();
	iterBase = findClassInBase(name, iterBase);
	if (iterBase == base.end())
	{
		base.push_back(Category(name, actualResponse, associatedWords));
	}
	else
	{
		iterBase->addToDict(associatedWords);
		iterBase->addResponses(actualResponse);
	}
}
vector<Category>::iterator& Bot::findClassInBase(string name, vector<Category>::iterator& iterBase)
{
	while( iterBase != base.end())
	{
		if (iterBase->sayName() == name)
		{
			return iterBase;
		}
		iterBase++;
	}
	return iterBase;
}
void Bot::printBase()
{
	for (vector<Category>::iterator iterBase = base.begin(); iterBase != base.end(); ++iterBase)
	{
		cout <<"Klasa: "<<iterBase->sayName()<<endl;
		iterBase->printWords();
		iterBase->printResponses();
	}
}
void Bot::zeroScore()
{
	for (auto iter : base)
	{
		iter.zeroScore();
	}
}
string Bot::respond(Question& toAnswer)
{
	for (vector<std::string>::iterator strIter = toAnswer.words.begin(); strIter != toAnswer.words.end(); strIter++)
	{
		bool found = false;
		vector<Category>::iterator champ = base.begin();
		int mostcases = 0;
		int occurences = 0;
		for (vector<Category>::iterator baseIter = base.begin(); baseIter != base.end(); ++baseIter)
		{
			occurences = baseIter->getOccurences(*strIter);
			if (occurences > mostcases)
			{
				champ = baseIter;
				mostcases = occurences;
				found = true;
			}
		}
		if(found)
			champ->incScore();
	}
	std:: string response = getResponse();
	zeroScore();
	return response;
}

void Bot::startSession()
{
	for (vector<Category>::iterator baseIter = base.begin(); baseIter != base.end(); baseIter++)
	{
		baseIter->startSession();
	}
}

void Bot::endSession()
{
	for (vector<Category>::iterator baseIter = base.begin(); baseIter != base.end(); ++baseIter)
	{
		baseIter->endSession();
	}
}




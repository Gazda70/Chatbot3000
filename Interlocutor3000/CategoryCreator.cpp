#include "CategoryCreator.h"
#include <algorithm>
#include <string>

//funkcja ma za zadanie zliczyæ liczbê wyst¹pieñ danego s³owa w wektorze podanym
// jako argument i zwróciæ wektor par s³owo-liczba wyst¹pieñ
vector<pair<string, int>> CategoryCreator::countWords(vector<string>& myWords)
{
	vector<pair<string, int>> counted;
	for (vector<string> ::iterator outer = myWords.begin(); outer != myWords.end(); ++outer)
	{
		if (!inVectorString(myWords, *outer,outer))
		{
			int occur = 1;
			for (vector<string> ::iterator inner = outer; inner != myWords.end(); ++inner)
			{
				if (*inner == *outer && inner != outer)
					occur++;
			}
			counted.push_back(make_pair(*outer, occur));
		}
	}
	return counted;
}

bool CategoryCreator::inVectorString(vector<string>& vctr, string str, vector<string>::iterator border)
{
	for (vector<string> ::iterator iter = vctr.begin(); iter != border; ++iter)
	{
		if (*iter == str)
			return true;
	}
	return false;
}


void CategoryCreator::readFile(const char* filename, Bot& toFeed)
{
	trainingFile.open(filename);
	if (trainingFile.is_open())
	{
		while (!trainingFile.eof())
		{
			try
			{
				this->operator>>(trainingFile);
			}
			catch (const ReadException& exc)
			{
				continue;
			}
			vector<pair<string, int>> words;
			words = countWords(tokens);
			toFeed.addToBase(actualClass, responses, words);
			toFeed.addToDict(words);
			actualClass = "";
			tokens.clear();
			responses.clear();
		}
		trainingFile.close();
	}
}
istream& CategoryCreator::operator>>(istream& input)
{
	string formatedWords;
	string formatedResponses;
	string response = "";
	try {
		getline(input, formatedWords, ';');
		getline(input, actualClass, ';');
		getline(input, formatedResponses);
		if (!(testString(formatedWords) && testString(actualClass) && testString(formatedResponses)))
		{
			throw (ReadException());
		}
	}
	catch (const ReadException& exc)
	{
		throw;
		return input;
	}
	tokens = tokenize(formatedWords);
	for(auto i : formatedResponses)
	{
		if (i != ';')
		{
			response += i;
		}
		else
		{
			responses.push_back(response);
			response = "";
		}
	}
	if(response != "")
		responses.push_back(response);
	return input;
}
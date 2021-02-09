#include "Dictionary.h"
#include <iostream>
using namespace std;


void Dictionary::addToDict(vector<pair<string, int>>& toAdd)
{
	for (vector<pair<string, int>>::iterator outer = toAdd.begin(); outer != toAdd.end(); outer++)
	{
		vector<pair<string, int>>::iterator inner = dictionary.begin();
		while (inner != dictionary.end() && inner->first != outer->first)
		{
			inner++;
		}
		if (inner == dictionary.end())
		{
			dictionary.push_back(*outer);
		}
		else
		{
			inner->second += outer->second;
		}
	}
}

std::pair<bool, int> Dictionary::inDict(string another)
{
	std::pair<bool, int> toReturn = std::make_pair<bool, int>(false, 0);
	for (vector<pair<string, int>>::iterator iter = dictionary.begin(); iter != dictionary.end(); ++iter)
	{
		if (iter->first == another)
		{
			toReturn.first = true;
			toReturn.second = iter->second;
		}
	}
	return toReturn;
}
void Dictionary::printDictionary()
{
	for (vector<pair<string, int>>::iterator iterDict = dictionary.begin(); iterDict != dictionary.end(); iterDict++)
	{
		cout << iterDict->first << ": " << iterDict->second << endl;
	}
}
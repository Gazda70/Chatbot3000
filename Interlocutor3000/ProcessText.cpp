#include "ProcessText.h"

vector<string> ProcessText::tokenize(string toTokenize)
{
	vector<string> tokens;
	string actual = "";
	for (int i = 0; i < toTokenize.size(); i++)
	{
		if (toTokenize[i] != ' ' && toTokenize[i] != ';' )
		{
			if ((static_cast<int>(toTokenize[i]) > 64 && static_cast<int>(toTokenize[i]) < 91)
				|| (static_cast<int>(toTokenize[i]) > 96 && static_cast<int>(toTokenize[i]) < 123) || (static_cast<int>(toTokenize[i]) > 47 &&
					static_cast<int>(toTokenize[i]) < 58))
				actual += static_cast<char>(tolower(toTokenize[i]));
		}
		else
		{
			tokens.push_back(actual);
			actual = "";
		}
	}
	tokens.push_back(actual);
	stem(tokens);
	return tokens;
}
void ProcessText::stem(vector<string>& toStem)
{
	PorterStemmer stemmer = PorterStemmer();
	for (int i = 0; i < toStem.size(); i++)
	{
		stemmer.stem(toStem[i]);
		std::cout << toStem[i] << std::endl;
	}
}

bool ProcessText::testString(string toTest)
{
	for (auto t : toTest)
	{
		if (static_cast<int>(t) > 64 && static_cast<int>(t)
			|| static_cast<int>(t) > 96 && static_cast<int>(t) < 123)
		{
			return true;
		}
	}
	return false;
}

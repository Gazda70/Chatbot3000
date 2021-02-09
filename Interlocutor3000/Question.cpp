#include "Question.h"
#include "Bot.h"
using namespace std;


Question::Question(string toTokenize)
{
	words = tokenize(toTokenize);
}
void Question::printTokens()
{
	cout << "Wypisanie tokenow" << endl;
	for (vector<string>::iterator i = words.begin(); i != words.end(); ++i)
	{
		cout << *i << endl;
	}
}

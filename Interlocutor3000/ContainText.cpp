#include "ContainText.h"


void ContainText::setText(FloatRect parentDim, Vector2f relative, std::string text, std::string nameFontFile, unsigned int textSize, Color textColor,
							Text::Style textBold, Text::Style textUnderline)
{
	parent = parentDim;
	minimalSize = textSize / 3.0;
	actualWidth = 0.0;
	textfieldActive = true;
	selectedSize = textSize;
	infoString = text;
	myFont.loadFromFile(nameFontFile);
	myText.setFont(myFont);
	setInfoString();
	myText.setFillColor(textColor);
	myText.setStyle(textBold | textUnderline);
	FloatRect textBounds = myText.getLocalBounds();
	setLocalOffset(relative);
	myText.setPosition(parent.left + textLocalOffset.x, parent.top + textLocalOffset.y);
}
void ContainText::setLocalOffset(Vector2f relative)
{
	if (relative != Vector2f{ 0.0,0.0 })
	{
		textLocalOffset = { relative.x * parent.width, relative.y * parent.height };
	}
	else
	{
		myText.setOrigin(myText.getLocalBounds().width / 2.0, myText.getLocalBounds().height / 2.0);
		textLocalOffset = { parent.width / float(2.0), parent.height / float(2.0) };
	}
}

void ContainText::modifyText(sf::Uint32 letter)
{
	sf::String myown = myText.getString();
	if (isinfoString)
	{
		unsetInfoString();
	}
	switch (letter)
	{
	case 8:
		if (!myown.isEmpty())
		{
			if (myText.getString()[myown.getSize() - 1] == '\n')
				readjustText();
			myown.erase(myown.getSize() - 1, 1);
			myText.setString(myown);
			textfieldActive = true;
		}
		break;
	default:
		addTextInRange(letter);
		break;
	}
}

void ContainText::reset()
{
	setInfoString();
}

void ContainText::addTextInRange(sf::Uint32 analyzed)
{
	if (textfieldActive)
	{
		sf::String myString = myText.getString();
		FloatRect textbounds = myText.getGlobalBounds();
		FloatRect glyphBounds = myFont.getGlyph(analyzed, myText.getCharacterSize(), myText.getStyle()).bounds;
		float lineSpacing = myFont.getLineSpacing(myText.getCharacterSize());
		float widthLeft = parent.width - 2 * textLocalOffset.x;
		float heightLeft = parent.height - textLocalOffset.y;
		actualWidth += glyphBounds.width;
		std::cout << actualWidth + glyphBounds.width << std::endl;
		if (actualWidth + glyphBounds.width >= widthLeft)
		{
			actualWidth = glyphBounds.width;
			sf::String toAddNewline = myText.getString();
			if (textbounds.height + glyphBounds.height + lineSpacing < heightLeft)
			{
				myText.setString(myString + '\n');
			}
			else
			{
				if (!adjustText(textbounds, glyphBounds, lineSpacing))
				{
					textfieldActive = false;
					actualWidth = 0.0;
					return;
				}
			}
		}
			myText.setString(myText.getString() + analyzed);
	}
}

bool ContainText::adjustText(FloatRect textbounds, FloatRect glyphbounds, float spacing)
{
	unsigned int mysize = myText.getCharacterSize();
	unsigned int prevsize = mysize;
	unsigned int toreduce = 0;
	while (textbounds.top + textbounds.height + spacing + glyphbounds.height - toreduce >= parent.top + parent.height && mysize >= minimalSize)
	{
		mysize--;
		toreduce++;
		myText.setCharacterSize(mysize);
	}
	if (textbounds.top + textbounds.height + spacing + glyphbounds.height - toreduce >= parent.top + parent.height)
	{
		myText.setCharacterSize(prevsize);
		return false;
	}
	std::pair<int, int> temp;
	temp.first = prevsize;
	myText.setString(myText.getString() + '\n');
	temp.second = myText.getString().getSize();
	adjustments.push_back(temp);
	return true;
}

void ContainText::readjustText()
{
	std::vector<std::pair<int, int>>::iterator iter = adjustments.begin();
	size_t actual = myText.getString().getSize();
	if (!adjustments.empty())
	{
		while (iter != adjustments.end() && iter->second != actual)
		{
			iter++;
		}
		if (iter != adjustments.end())
		{
			if (iter->second == myText.getString().getSize())
			{
				myText.setCharacterSize(iter->first);
			}
		}
	}
}

void ContainText::setInfoString()
{
	actualWidth = 0.0;
	textfieldActive = true;
	isinfoString = true;
	myText.setCharacterSize(selectedSize);
	myText.setString(infoString);
}

bool ContainText::checkIfEntered()
{
	return !isinfoString;
}

void ContainText::unsetInfoString()
{
	isinfoString = false;
	myText.setString("");
}



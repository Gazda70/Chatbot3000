#include "Button.h"

Button::Button(float x_axis, float y_axis, float width, float height, Color color,
	std::string text, std::string nameFontFile, unsigned int textSize, Color textColor,
	Vector2f textpos,Text::Style textBold, Text::Style textUnderline,
	float outlineThick, Color outlineColor)
{
	this->body.setSize({ width,height });
	this->body.setPosition({ x_axis,y_axis });
	this->body.setFillColor(color);
	this->body.setOutlineThickness(outlineThick);
	this->body.setOutlineColor(outlineColor);
	FloatRect dimens = FloatRect({ x_axis, y_axis }, { width, height });
	this->setText(dimens, textpos, text, nameFontFile, textSize, textColor, textBold, textUnderline);
}
void Button::manageInput(Vector2f mousepos)
{
	if (contains(mousepos))
	{
		this->actual = State::Active;
	}
}
void Button::draw(RenderTarget& window, RenderStates state) const
{
	window.draw(this->body, state);
	window.draw(this->myText, state);
}

void Button::activate()
{
	actual = State::Active;
}

bool Button::contains(Vector2f mousepos)
{
	if(body.getGlobalBounds()
		.contains(static_cast<float>(mousepos.x), static_cast<float>(mousepos.y)))
	{
		return true;
	}
	return false;
}

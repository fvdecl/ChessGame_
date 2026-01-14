#include "TextView.h"

void View::TextView::DrawText(sf::RenderWindow& window)
{
	for (int i = 0; i < textObject.size(); i++)
		window.draw(textObject.at(i));
}

void View::TextView::AddTextObject(sf::Text text)
{
	textObject.push_back(text);
}
#pragma once

#include <SFML/Graphics.hpp>

namespace View
{
	class TextView
	{
	private:

		std::vector<sf::Text> textObject;

	public:

		void DrawText(sf::RenderWindow& window);
		void AddTextObject(sf::Text text);
	};
}


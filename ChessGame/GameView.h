#pragma once

#include <SFML/Graphics.hpp>

namespace View
{
	class GameView
	{
	private:
		sf::Texture pawnTexture[6];

	public:
		GameView(sf::Texture pawnTextureArr[6]);

	};
}


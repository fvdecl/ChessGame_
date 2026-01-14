#pragma once

#include <SFML/Graphics.hpp>

namespace View
{
	class PawnView
	{
	private:
		sf::Texture pawnTexture;

		float x, y, z;
		float position[3] = { x, y, z };

	public:
		PawnView(sf::Texture _pawnTexture, float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : pawnTexture(_pawnTexture), x(_x), y(_y), z(_z) {}

		float GetWorldPosition();
	};
};
#include "GameView.h"


View::GameView::GameView(sf::Texture pawnTextureArr[6])
{
	for (int i = 0; i < (sizeof(pawnTexture) / sizeof(sf::Texture)); i++)
	{
		this->pawnTexture[i] = pawnTextureArr[i];
	}
}

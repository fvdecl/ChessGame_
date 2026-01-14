#include "Game.hpp"


Model::Game::Game(ChessValue::Type initPlayer)
{
	this->ChessMoveQueue = initPlayer;
}

void Model::Game::SwitchChessPlayer()
{
	switch (this->ChessMoveQueue)
	{
	case ChessValue::Type::White:
		this->ChessMoveQueue = ChessValue::Type::Black;
		break;
	case ChessValue::Type::Black:
		this->ChessMoveQueue = ChessValue::Type::White;
		break;
	}
}

ChessValue::Type Model::Game::getCurrentChessPlayer()
{
	return ChessMoveQueue;
}
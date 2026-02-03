#include "GameSession.hpp"


Model::GameSession::GameSession(ChessValue::Type initPlayer)
{
	this->ChessMoveQueue = initPlayer;
}

void Model::GameSession::SwitchChessPlayer()
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

ChessValue::Type Model::GameSession::getCurrentChessPlayer()
{
	return ChessMoveQueue;
}
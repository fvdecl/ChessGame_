#include "Pawn.hpp"

using namespace Model;


//Pawn::Pawn(int _id = -1, ChessValue::Type _teamId = ChessValue::Type::Black, ChessValue::Shape _shape = ChessValue::Shape::Pawn, bool _isDeath = false)
//{
//	this->id = _id;
//	this->teamId = _teamId;
//	this->shape = _shape;
//	this->isDeath = _isDeath;
//}

int Pawn::GetId()
{
	return this->id;
}

ChessValue::Type Pawn::GetTeamID()
{
	return teamId;
}


bool Pawn::IsDeath()
{
	return isDeath;
}

ChessValue::Shape Pawn::GetType()
{
	return this->shape;
}

void Pawn::SetShape(ChessValue::Shape _shape)
{
	this->shape = _shape;
}
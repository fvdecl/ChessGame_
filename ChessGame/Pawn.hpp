#pragma once

#include <cstddef>
#include <iostream>

#include "Game.hpp"


namespace Model
{
	enum Direction;
	class Pawn
	{
	private:
		int id;
		ChessValue::Type teamId = ChessValue::Type::None;
		ChessValue::Shape shape = ChessValue::Shape::Pawn;

		bool isDeath;

	public:

		Pawn(int _id = -1, ChessValue::Type _teamId = ChessValue::Type::None, ChessValue::Shape _shape = ChessValue::Shape::Pawn, bool _isDeath = false) : id(_id), teamId(_teamId), shape(_shape), isDeath(_isDeath) {}

		int GetId();
		ChessValue::Shape GetType();
		ChessValue::Type GetTeamID();
		void SetShape(ChessValue::Shape _shape);
		bool IsDeath();

	};
}
#pragma once

namespace ChessValue
{
	enum class Type : int { White = 1, Black = 0, None = 2 };
	enum class Direction : int { left = 0, right = 1, down = 2, up = 3 };
	enum class Shape : int { Pawn = 0, Rook = 1, Horse = 2, Bishop = 3, Queen = 4, King = 5};
}

namespace Model
{
	class Game
	{
	private:

		ChessValue::Type ChessMoveQueue;

	public:
		Game(ChessValue::Type initPlayer);

		void SwitchChessPlayer();
		ChessValue::Type getCurrentChessPlayer();
	};
}
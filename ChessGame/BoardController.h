#pragma once

#include <vector>
#include <boost/assign.hpp>

#include "Pawn.hpp"
#include "Cell.hpp"
#include "BoardView.hpp"
#include "Board.hpp"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Horse.h"

namespace Controller 
{
	class BoardController
	{
	private:
		View::BoardView* boardView;
		Model::Board* board;

		Rook rook;
		Bishop bishop;
		King king;
		Horse horse;


		// Need separate it to interface.
		const int stepCoiffLateralDirection[4][2] = {
					{ -1, 1 },  // right up
					{ -1, -1 }, // left up
					{ 1, 1 },   // right down
					{ 1, -1 }   // left down
		};

		const int stepCoiffDirection[4][2] = {
					{ 0, 1 },  // right
					{ 1, 0 },  // down
					{ 0, -1 }, // left
					{ -1, 0 }  // up
		};

		const int stepCoiffHorseDirection[4][4][2] = {
			// up
			{
				{ -1, 1 },  // in up and right
				{ -1, -1 }, // in up and left
			},
			
			// down
			{
				{ 1, 1 },	// in down and right
				{ 1, -1 },	// in down and left
			},

			// right
			{
				{ 1, 1 },	// in right and down
				{ 1, -1 },	// in right and up
			},

			// left
			{
				{ -1, -1 },	// in left and up
				{ -1, 1 }	// in left and down
			}
		};

		bool isInsideBoard(int y, int x);
		bool isFilledCell(int y, int x);
		bool canBishopMoveFromToCellInRange(int fromY, int fromX, int toY, int toX);
		int getStepByDirectionWithStepCountArr(int directionY, int directionX, int stepCount);
		int getStepCountWithDirection(int directionY, int directionX, int stepCount);
		int getMaxPositionToMoveByCurrentYX(int currentY, int currentX);
	public:

		BoardController(Model::Board &boardModel, View::BoardView &boardView);
		void SetPawn(int cellPositionY, int cellPositionX, Model::Pawn pawn);
		void SetPawnByCellName(std::string nameCell, Model::Pawn pawn);
		void ClearCellByCellName(std::string nameCell);
		Model::Cell SelectCell(int cellPositionY, int cellPositionX);
		Model::Cell* SelectCellPtr(int cellPositionY, int cellPositionX);
		View::BoardView* GetBoardViewPtr();
		Model::Board* GetBoardPtr();
		Model::Board GetBoard();
		// Return position cellPositionY cellPositionX
		std::vector<Model::Cell> ShowStepsForCellWithPawn(int cellPositionY, int cellPositionX, Model::Cell* cell);
		void ClearAllMarks();
		int CountPawn(ChessValue::Type type);
	};
}


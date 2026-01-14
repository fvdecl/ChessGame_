#pragma once

#include <iostream>
#include <string>

#include "Cell.hpp"

namespace Model
{
	class Board
	{
	private:
		Cell board[8][8];
		// For call to pawn we're using boardPtr that's here :)
		Cell* boardPtr[8][8];

		std::string CreateBoardCellNameByAlphabet(char alphabetSym, int boardCellHorizontalPosition);
		char defAlphabet[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

		Cell* GetAvailableNeighbors(int y, int x);
	public:
		Board(char alphabet[], float positionAddMargin2D, float cellSize[2]);
		Board(char alphabet[], float positionAddMargin2D = 60.0f, float cellSizeX = 60.0f, float cellSizeY = 60.0f);
		Board(float positionAddMargin2D = 60.0f, float cellSizeX = 60.0f, float cellSizeY = 60.0f);

		Cell GetCell(int positionY, int positionX);
		Cell* GetCellPtr(int positionY, int positionX);
		Cell* FindCellByNamePtr(std::string cellName);
		void SetupPawn();
	};
}

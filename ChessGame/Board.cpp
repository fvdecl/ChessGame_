#include "Cell.hpp"

#include "Board.hpp"

using namespace Model;

std::string Board::CreateBoardCellNameByAlphabet(char alphabetSym, int boardCellHorizontalPosition)
{
	return alphabetSym + std::to_string(boardCellHorizontalPosition);
}

Cell* Board::GetAvailableNeighbors(int y, int x)
{
	// right, left, down, up
	Cell* availableNeighborsCount[4] = {&board[y][x+1], &board[y][x-1], 
		&board[y+1][x], &board[y-1][x]};

	int coordArr[2] = { y, x };
	for (int i = 0; i < (sizeof(coordArr) / sizeof(int)); i++)
	{
		for (int j = 0; j < (sizeof(coordArr) / sizeof(int)); j += 2)
		{
			switch (j)
			{
			case 0:
				if ((coordArr[i] - 1) < 0) availableNeighborsCount[0+j] = nullptr;
			case 1:
				if ((sizeof(board) / sizeof(board[0])) < (static_cast<unsigned long long>(coordArr[i]) + 1)) availableNeighborsCount[1+j] = nullptr;
			}
		}
	}

	return *availableNeighborsCount;
}	

Model::Board::Board(char alphabet[], float positionAddMargin2D, float cellSize[2])
{
	float iterationMarginX, iterationMarginY;

	for (int y = 0; y < (sizeof(board) / sizeof(board[0])); y++)
	{
		iterationMarginY = y * positionAddMargin2D;
		for (int x = 0; x < (sizeof(board[0]) / sizeof(Cell)); x++)
		{
			board[y][x].SetName(CreateBoardCellNameByAlphabet(alphabet[y], x));
			
			board[y][x].SetNeighbors(GetAvailableNeighbors(y, x));


			iterationMarginX = x * positionAddMargin2D;
			board[y][x].AddPosition(iterationMarginX, iterationMarginY, NULL);
		}
	}
}

Model::Board::Board(char alphabet[], float positionAddMargin2D, float cellSizeX, float cellSizeY)
{
	float iterationMarginX, iterationMarginY;

	for (int y = 0; y < (sizeof(board) / sizeof(board[0])); y++)
	{
		iterationMarginY = y * positionAddMargin2D;
		for (int x = 0; x < (sizeof(board[0]) / sizeof(Cell)); x++)
		{
			board[y][x].SetName(CreateBoardCellNameByAlphabet(alphabet[y], x));

			board[y][x].SetNeighbors(GetAvailableNeighbors(y, x));


			iterationMarginX = x * positionAddMargin2D;
			board[y][x].AddPosition(iterationMarginX, iterationMarginY, NULL);
		}
	}
}

Model::Board::Board(float positionAddMargin2D, float cellSizeX, float cellSizeY)
{
	float iterationMarginX, iterationMarginY;

	for (int y = 0; y < (sizeof(board) / sizeof(board[0])); y++)
	{
		iterationMarginY = y * positionAddMargin2D;
		for (int x = 0; x < (sizeof(board[0]) / sizeof(Cell)); x++)
		{
			board[y][x].SetName(CreateBoardCellNameByAlphabet(defAlphabet[y], x));

			board[y][x].SetNeighbors(GetAvailableNeighbors(y, x));


			iterationMarginX = x * positionAddMargin2D;
			board[y][x].AddPosition(iterationMarginX, iterationMarginY, NULL);
		}
	}
}

Model::Cell Model::Board::GetCell(int positionY, int positionX)
{
	return board[positionY][positionX];
}

Model::Cell* Model::Board::GetCellPtr(int positionY, int positionX)
{
	return &board[positionY][positionX];
}

Model::Cell* Model::Board::FindCellByNamePtr(std::string cellName)
{
	for (int i = 0; i < sizeof(board[0]) / sizeof(board[0][0]); i++)
		for (int j = 0; j < sizeof(board[0]) / sizeof(board[0][0]); j++)
			if (cellName == board[i][j].GetName())
				return &board[i][j];
}

void Model::Board::SetupPawn()
{
	int id = 0;
	int hSum = 0;
	int* idPtr = &id;
	int* hSumPtr = &hSum;

	// White and black
	for (int i = 0; i < 2; i++)
	{
		// Pawn shapes
		for (int j = 0; j < 8; j++)
		{
			Model::Pawn pawn(*idPtr, (ChessValue::Type)i, ChessValue::Shape::Pawn, false);
			GetCellPtr((6 * i) + (1 - i), j)->SetPawn(pawn);
			std::cout << "Model::Pawn pawn(*idPtr, (ChessValue::Type)i, ChessValue::Shape::Pawn, false): " << (int)pawn.GetType() << std::endl;
			*idPtr += 1;

			/*if (j == 0 && i == 1)
			{
				std::cout << "GG" << std::endl;
				
			}
			else
			{
				Model::Pawn pawn(*idPtr, (ChessValue::Type)i, ChessValue::Shape::Pawn, false);
				GetCellPtr((6 * i) + (1 - i), j)->SetPawn(pawn);
				std::cout << "Model::Pawn pawn(*idPtr, (ChessValue::Type)i, ChessValue::Shape::Pawn, false): " << (int)pawn.GetType() << std::endl;
				*idPtr += 1;
			}*/
		}


		*hSumPtr = 0;
		// From left to right
		for (int h = 0; h < 8; h++)
		{
			int nonPawnOffset = (5 < (h+1)) ? 4-((h+1)%5) : h+1;
			Model::Pawn pawnOth(*idPtr, (ChessValue::Type)i, (ChessValue::Shape)nonPawnOffset, false);
			std::cout << "Model::Pawn pawnOth(*idPtr, (ChessValue::Type)i, (ChessValue::Shape)nonPawnOffset, false) " << (int)pawnOth.GetType() << std::endl;
			
			std::cout << "GetCellPtr(((-1 * -i) + (i * 5)), h).SetPawn(pawnOth): " << sizeof(*GetCellPtr(((-1 * -i) + (i * 5)), h)->GetCellPawnPtr())/sizeof(Pawn) << std::endl;
			std::cout << "nonPawnOffset: " << nonPawnOffset << std::endl;

			std::cout << "***PAWN*** " << std::endl;
			std::cout << "*idPtr: " << *idPtr << std::endl;
			std::cout << "Team: " << i << std::endl;
			std::cout << "Figure (shape): " << nonPawnOffset << std::endl;
			std::cout << "GetCellY: " << ((-1 * -i) + (i * 5)) << std::endl;
			std::cout << "GetCellX: " << h << std::endl << std::endl;


			GetCellPtr(i * 7, h)->SetPawn(Model::Pawn(*idPtr, (ChessValue::Type)i, (ChessValue::Shape)nonPawnOffset, false));

			//this->board[(i * 7)][h].SetNeighbors((h - 1 < 0) ? Cell() : board[i * 7][*hSumPtr - 1], (7 < h + 1) ? Cell() : board[i * 7][h + 1], (7 < ((i * 7) + 1)) ? Cell() : board[(i * 7) + 1][h], (((i * 7) - 1) < 0) ? Cell() : board[i * 7 - 1][h]);
			// this->board[(i * 7)][h].SetNeighborsPtr((h - 1 < 0) ? nullptr : &board[i * 7][*hSumPtr - 1], (7 < h + 1) ? nullptr : &board[i * 7][h + 1], (7 < ((i * 7) + 1)) ? nullptr : &board[(i * 7) + 1][h], (((i * 7) - 1) < 0) ? nullptr : boardPtr[i * 7 - 1][h]);
			/*for (int i = 0; i < 4; i++)
				this->board[(i * 7)][h].GetCellNeighborPtr((ChessValue::Direction)i) == nullptr ? boardPtr[(i * 7)][h]->GetCellNeighborPtr((ChessValue::Direction)i)->IsFill() = nullptr : ;*/
			
			*idPtr += 1;
			*hSumPtr += 1;
		}
	}
}
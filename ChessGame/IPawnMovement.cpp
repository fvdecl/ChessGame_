#include "IPawnMovement.h"

void IPawnMovement::Move(std::vector<Model::Cell> &v, Model::Board* boardPtr, View::BoardView* boardViewPtr, int cellPositionY, int cellPositionX)
{
	std::cout << "Something IDK... " << std::endl;
}

bool IPawnMovement::isInsideBoard(int y, int x)
{
	return y < 8 && -1 < y && x < 8 && -1 < x;
}

bool IPawnMovement::isFilledCell(int y, int x, Model::Board* board)
{
	if (board->GetCellPtr(y, x)->IsFill())
		return true;

	return false;
}
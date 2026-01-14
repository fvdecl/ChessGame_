#pragma once

#include <vector>
#include "Board.hpp"
#include "BoardView.hpp"

struct IPawnMovement
{
public:
	bool isInsideBoard(int y, int x);
	bool isFilledCell(int y, int x, Model::Board* board);

	virtual void Move(std::vector<Model::Cell> &v, Model::Board* boardPtr, View::BoardView* boardViewPtr, int cellPositionY, int cellPositionX);

	virtual ~IPawnMovement() = default;
};
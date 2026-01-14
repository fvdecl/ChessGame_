#pragma once

#include "BoardView.hpp"
#include "Board.hpp"

class Log
{
public:

	void PrintCellClickData(Model::Cell* cellPtr);
	void PrintViewCellPositions(Model::Board boardModel);
	void PrintModelCellFill(Model::Board boardModel);
};


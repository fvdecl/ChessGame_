#pragma once
#include "IPawnMovement.h"

class Bishop : public IPawnMovement
{
public:
	void Move(std::vector<Model::Cell> &v, Model::Board* boardPtr, View::BoardView* boardViewPtr, int cellPositionY, int cellPositionX) override;
};


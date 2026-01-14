#include "King.h"

void King::Move(std::vector<Model::Cell>& v, Model::Board* boardPtr, View::BoardView* boardViewPtr, int cellPositionY, int cellPositionX)
{
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

	int count = 0;
	int* countPtr = &count;
	int maxStepBishop[4] = { 0, 0, 0, 0 };
	int maxStepRook[4] = { 0, 0, 0, 0 };
	bool isTrue = true, * isTruePtr = &isTrue;


	// Gettting max position by direction.
	for (int i = 0; i < 4; i++)
	{
		*countPtr = 0;
		while (*isTruePtr)
		{
			if (isInsideBoard(cellPositionY + (*countPtr * stepCoiffLateralDirection[i][0]), cellPositionX + (*countPtr * stepCoiffLateralDirection[i][1])) && *countPtr < 2)
				*countPtr += 1;
			else
				break;
		}

		maxStepBishop[i] = *countPtr;
	}

	for (int i = 0; i < 4; i++)
	{
		if (isInsideBoard(cellPositionY + stepCoiffDirection[i][0], cellPositionX + stepCoiffDirection[i][1]))
		{
			switch (isFilledCell(cellPositionY + stepCoiffDirection[i][0], cellPositionX + stepCoiffDirection[i][1], boardPtr))
			{
			case true:
				boardViewPtr->SetCellColor(cellPositionY + stepCoiffDirection[i][0], cellPositionX + stepCoiffDirection[i][1], sf::Color(10, 122, 0));
				break;
			case false:
				boardViewPtr->SetCellColor(cellPositionY + stepCoiffDirection[i][0], cellPositionX + stepCoiffDirection[i][1], sf::Color(255, 0, 0));
				break;
			}

			v.push_back(boardPtr->GetCell(cellPositionY + stepCoiffDirection[i][0], cellPositionX + stepCoiffDirection[i][1]));
		}
	}


	for (int i = 0; i < 4; i++)
	{
		if (maxStepBishop[i] != 0)
			for (int j = 1; j < maxStepBishop[i]; j++)
			{
				if (isFilledCell(cellPositionY + (j * stepCoiffLateralDirection[i][0]), cellPositionX + (j * stepCoiffLateralDirection[i][1]), boardPtr) || j < 1)
				{
					boardViewPtr->SetCellColor(cellPositionY + (j * stepCoiffLateralDirection[i][0]), cellPositionX + (j * stepCoiffLateralDirection[i][1]), sf::Color(10, 122, 0));

					v.push_back(boardPtr->GetCell(cellPositionY + (j * stepCoiffLateralDirection[i][0]), cellPositionX + (j * stepCoiffLateralDirection[i][1])));
					break;
				}
				else
				{
					boardViewPtr->SetCellColor(cellPositionY + (j * stepCoiffLateralDirection[i][0]), cellPositionX + (j * stepCoiffLateralDirection[i][1]), sf::Color(255, 0, 0));

					v.push_back(boardPtr->GetCell(cellPositionY + (j * stepCoiffLateralDirection[i][0]), cellPositionX + (j * stepCoiffLateralDirection[i][1])));
				}
			}
	}
}
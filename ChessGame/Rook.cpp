#include "Rook.h"

void Rook::Move(std::vector<Model::Cell> &v, Model::Board* boardPtr, View::BoardView* boardViewPtr, int cellPositionY, int cellPositionX)
{
	for (int i = 0; i < cellPositionY; i++)
	{
		if (boardPtr->GetCellPtr(cellPositionY - (i + 1), cellPositionX)->IsFill() == true)
		{
			boardViewPtr->SetCellColor(cellPositionY - (i + 1), cellPositionX, sf::Color(10, 122, 0));
			v.push_back(boardPtr->GetCell(cellPositionY - (i + 1), cellPositionX));
			break;
		}

		if (boardPtr->GetCellPtr(cellPositionY - (i + 1), cellPositionX)->IsFill() == false)
		{
			boardViewPtr->SetCellColor(cellPositionY - (i + 1), cellPositionX, sf::Color(255, 0, 0));
			v.push_back(boardPtr->GetCell(cellPositionY - (i + 1), cellPositionX));
		}
	}

	for (int i = 0; i < 7 - cellPositionX; i++)
	{
		if (boardPtr->GetCellPtr(cellPositionY, cellPositionX + (i + 1))->IsFill() == true)
		{
			boardViewPtr->SetCellColor(cellPositionY, cellPositionX + (i + 1), sf::Color(10, 122, 0));
			v.push_back(boardPtr->GetCell(cellPositionY, cellPositionX + (i + 1)));
			break;
		}

		if (boardPtr->GetCellPtr(cellPositionY, cellPositionX + (i + 1))->IsFill() == false)
		{
			boardViewPtr->SetCellColor(cellPositionY, cellPositionX + (i + 1), sf::Color(255, 0, 0));
			v.push_back(boardPtr->GetCell(cellPositionY, cellPositionX + (i + 1)));
		}
	}

	for (int i = cellPositionX; 0 < i; i--)
	{
		if (boardPtr->GetCellPtr(cellPositionY, cellPositionX - 1)->IsFill() == true)
		{
			boardViewPtr->SetCellColor(cellPositionY, cellPositionX - 1, sf::Color(10, 122, 0));
			v.push_back(boardPtr->GetCell(cellPositionY, cellPositionX - 1));
			break;
		}


		if (boardPtr->GetCellPtr(cellPositionY, cellPositionX - i)->IsFill() == false)
		{
			boardViewPtr->SetCellColor(cellPositionY, cellPositionX - i, sf::Color(255, 0, 0));
			v.push_back(boardPtr->GetCell(cellPositionY, cellPositionX - i));
		}
	}

	for (int i = 1; i < (-1 * (-8 + cellPositionY)); i++)
	{
		if (boardPtr->GetCellPtr(cellPositionY + i, cellPositionX)->IsFill() == true)
		{
			boardViewPtr->SetCellColor(cellPositionY + i, cellPositionX, sf::Color(10, 122, 0));
			v.push_back(boardPtr->GetCell(cellPositionY + i, cellPositionX));
			break;
		}


		if (boardPtr->GetCellPtr(cellPositionY + i, cellPositionX)->IsFill() == false)
		{
			boardViewPtr->SetCellColor(cellPositionY + i, cellPositionX, sf::Color(255, 0, 0));
			v.push_back(boardPtr->GetCell(cellPositionY + i, cellPositionX));
		}
	}
}
#include "Horse.h"


void Horse::Move(std::vector<Model::Cell>& v, Model::Board* boardPtr, View::BoardView* boardViewPtr, int cellPositionY, int cellPositionX)
{
	int startPositionX = cellPositionX, startPositionY = cellPositionY;

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY - i, cellPositionX + 1))
		{
			if (boardPtr->GetCellPtr(cellPositionY - i, cellPositionX + 1)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY - i, cellPositionX + 1, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY - i, cellPositionX + 1, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY - i, cellPositionX + 1));
		}

		if (!isInsideBoard(cellPositionY - i, cellPositionX))
			break;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY - i, cellPositionX - 1))
		{
			if (boardPtr->GetCellPtr(cellPositionY - i, cellPositionX + 1)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY - i, cellPositionX - 1, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY - i, cellPositionX - 1, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY - i, cellPositionX - 1));
		}

		if (!isInsideBoard(cellPositionY - i, cellPositionX))
			break;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY - 1, cellPositionX + i))
		{
			if (boardPtr->GetCellPtr(cellPositionY - 1, cellPositionX + i)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY - 1, cellPositionX + i, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY - 1, cellPositionX + i, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY - 1, cellPositionX + i));
		}

		if (!isInsideBoard(cellPositionY, cellPositionX + i))
			break;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY + 1, cellPositionX + i))
		{
			if (boardPtr->GetCellPtr(cellPositionY + 1, cellPositionX + i)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY + 1, cellPositionX + i, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY + 1, cellPositionX + i, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY + 1, cellPositionX + i));
		}

		if (!isInsideBoard(cellPositionY, cellPositionX + i))
			break;
	}

	/*for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY - i, cellPositionX + 1))
		{
			boardViewPtr->SetCellColor(cellPositionY - i, cellPositionX + 1, sf::Color(255, 0, 0));

			v.push_back(boardPtr->GetCell(cellPositionY - i, cellPositionX + 1));
		}

		if (!isInsideBoard(cellPositionY - i, cellPositionX))
			break;
	}*/

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY + i, cellPositionX + 1))
		{
			if (boardPtr->GetCellPtr(cellPositionY + i, cellPositionX + 1)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY + i, cellPositionX + 1, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY + i, cellPositionX + 1, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY + i, cellPositionX + 1));
		}

		if (!isInsideBoard(cellPositionY + i, cellPositionX))
			break;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY + i, cellPositionX - 1))
		{
			if (boardPtr->GetCellPtr(cellPositionY + i, cellPositionX - 1)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY + i, cellPositionX - 1, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY + i, cellPositionX - 1, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY + i, cellPositionX - 1));
		}

		if (!isInsideBoard(cellPositionY + i, cellPositionX))
			break;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY + 1, cellPositionX - i))
		{
			if (boardPtr->GetCellPtr(cellPositionY + 1, cellPositionX - i)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY + 1, cellPositionX - i, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY + 1, cellPositionX - i, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY + 1, cellPositionX - i));
		}

		if (!isInsideBoard(cellPositionY, cellPositionX - i))
			break;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 2 && isInsideBoard(cellPositionY - 1, cellPositionX - i))
		{
			if (boardPtr->GetCellPtr(cellPositionY - 1, cellPositionX - i)->GetCellPawnPtr()->GetTeamID() ==
				boardPtr->GetCellPtr(startPositionY, startPositionX)->GetCellPawnPtr()->GetTeamID())
				boardViewPtr->SetCellColor(cellPositionY - 1, cellPositionX - i, sf::Color(10, 122, 0));
			else
				boardViewPtr->SetCellColor(cellPositionY - 1, cellPositionX - i, sf::Color(255, 0, 0));
				v.push_back(boardPtr->GetCell(cellPositionY - 1, cellPositionX - i));
		}

		if (!isInsideBoard(cellPositionY, cellPositionX - i))
			break;
	}
}
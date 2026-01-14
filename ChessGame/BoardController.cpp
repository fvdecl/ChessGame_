#include "BoardController.h"

Controller::BoardController::BoardController(Model::Board &boardModel, View::BoardView &boardView)
{
	this->board = &boardModel;
	this->boardView = &boardView;

	this->bishop = Bishop();
	this->rook = Rook();
	this->king = King();
	this->horse = Horse();
}

void Controller::BoardController::SetPawn(int cellPositionY, int cellPositionX, Model::Pawn pawn)
{
	board->GetCell(cellPositionY, cellPositionX).SetPawn(pawn);
}

void Controller::BoardController::SetPawnByCellName(std::string nameCell, Model::Pawn pawn)
{
	GetBoardPtr()->FindCellByNamePtr(nameCell)->SetPawn(pawn);
}

void Controller::BoardController::ClearCellByCellName(std::string nameCell)
{
	GetBoardPtr()->FindCellByNamePtr(nameCell)->ResetCellFromPawn();
}

View::BoardView* Controller::BoardController::GetBoardViewPtr()
{
	return boardView;
}

Model::Board* Controller::BoardController::GetBoardPtr()
{
	return board;
}

Model::Cell Controller::BoardController::SelectCell(int cellPositionY, int cellPositionX)
{
	// Mark setting in 2 lines
	GetBoardViewPtr()->ReInitBoardCells();

	// Pawn is not set
	if (!GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->IsFill())
	{
		GetBoardViewPtr()->SetCellColor(cellPositionY, cellPositionX, sf::Color(255, 0, 0));
		std::cout << "Cell shape fill color: " << (int)GetBoardViewPtr()->GetCell(cellPositionY, cellPositionX).GetCellShape().getFillColor().r << ' ' << (int)GetBoardViewPtr()->GetCell(cellPositionY, cellPositionX).GetCellShape().getFillColor().g << ' ' << (int)GetBoardViewPtr()->GetCell(cellPositionY, cellPositionX).GetCellShape().getFillColor().b << ' ' << std::endl;
		
		//return nullptr;
	}

	GetBoardViewPtr()->SetCellColor(cellPositionY, cellPositionX, sf::Color(sf::Uint8(122.5f), sf::Uint8(122.5f), 0));


	return this->board->GetCell(cellPositionY, cellPositionX);
}

Model::Cell* Controller::BoardController::SelectCellPtr(int cellPositionY, int cellPositionX)
{
	// Mark setting in 2 lines
	GetBoardViewPtr()->ReInitBoardCells();

	// Pawn is not set
	if (!GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->IsFill())
	{
		GetBoardViewPtr()->SetCellColor(cellPositionY, cellPositionX, sf::Color(255, 0, 0));
		std::cout << "Cell shape fill color: " << (int)GetBoardViewPtr()->GetCell(cellPositionY, cellPositionX).GetCellShape().getFillColor().r << ' ' << (int)GetBoardViewPtr()->GetCell(cellPositionY, cellPositionX).GetCellShape().getFillColor().g << ' ' << (int)GetBoardViewPtr()->GetCell(cellPositionY, cellPositionX).GetCellShape().getFillColor().b << ' ' << std::endl;

		//return nullptr;
	}

	GetBoardViewPtr()->SetCellColor(cellPositionY, cellPositionX, sf::Color(sf::Uint8(122.5f), sf::Uint8(122.5f), 0));


	return this->board->GetCellPtr(cellPositionY, cellPositionX);
}

std::vector<Model::Cell> Controller::BoardController::ShowStepsForCellWithPawn(int cellPositionY, int cellPositionX, Model::Cell* cell)
{
	std::vector<Model::Cell> v = { };

	if (!cell->IsFill())
		return v;


	int teamId = (int)cell->GetPawn().GetTeamID();

	int maxStepHorse[4] = { 0, 0, 0, 0 };
	bool isTrue = true, * isTruePtr = &isTrue;

	switch (cell->GetPawn().GetType())
	{
	default:
		return v;
		break;
	case ChessValue::Shape::Pawn:

		if ((cellPositionY == 6 || cellPositionY == 1) & 
			!GetBoardPtr()->GetCellPtr(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX)->IsFill() &
			!GetBoardPtr()->GetCellPtr(cellPositionY + (2 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -4)), cellPositionX)->IsFill())
		{
			if (isInsideBoard(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)))
				&& GetBoardPtr()->GetCellPtr(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)))->IsFill())
			{
				v.push_back(GetBoardPtr()->GetCell(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))));

				GetBoardViewPtr()->SetCellColor(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), sf::Color(10, 120, 0));
			}

			if (isInsideBoard(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))) &&
				GetBoardPtr()->GetCellPtr(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)))->IsFill())
			{
				v.push_back(GetBoardPtr()->GetCell(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))));

				GetBoardViewPtr()->SetCellColor(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), sf::Color(10, 120, 0));
			}

			GetBoardViewPtr()->SetCellColor(cellPositionY + (1 + (-2 * (int)cell->GetPawn().GetTeamID())), cellPositionX, sf::Color(255, 0, 0));
			GetBoardViewPtr()->SetCellColor(cellPositionY + (2 + (-4 * (int)cell->GetPawn().GetTeamID())), cellPositionX, sf::Color(255, 0, 0));
			v.push_back(GetBoardPtr()->GetCell(cellPositionY + (1 + (-2 * teamId)), cellPositionX));
			v.push_back(GetBoardPtr()->GetCell(cellPositionY + (2 + (-4 * teamId)), cellPositionX));

			for (int i = 0; i < v.size(); i++)
				std::cout << v.at(i).GetName() << std::endl;


			return v;
		}

		if (!GetBoardPtr()->GetCellPtr(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX)->IsFill())
		{
			GetBoardViewPtr()->SetCellColor(cellPositionY + (1 + (-2 * (int)cell->GetPawn().GetTeamID())), cellPositionX, sf::Color(255, 0, 0));
			v = { GetBoardPtr()->GetCell(cellPositionY + (1 + (-2 * teamId)), cellPositionX) };
		
			if (isInsideBoard(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))) && GetBoardPtr()->GetCellPtr(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)))->IsFill())
			{
				v.push_back(GetBoardPtr()->GetCell(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))));

				GetBoardViewPtr()->SetCellColor(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), sf::Color(10, 120, 0));
			}

			if (isInsideBoard(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))) &&
				GetBoardPtr()->GetCellPtr(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)))->IsFill())
			{
				v.push_back(GetBoardPtr()->GetCell(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2))));

				GetBoardViewPtr()->SetCellColor(cellPositionY + (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), cellPositionX - (1 + ((int)GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX)->GetPawn().GetTeamID() * -2)), sf::Color(10, 120, 0));
			}


			std::cout << std::endl << "CellPositionY (b,w): " << cellPositionY + (1 + (-1 * teamId)) << std::endl;
			return v;
		}

		return v;
		break;

		case ChessValue::Shape::Rook:

			
			/*for (int i = 0; i < 8; i++)
			{
				if (GetBoardPtr()->GetCellPtr(cellPositionY, cellPositionX + i)->IsFill() == true)
					GetBoardViewPtr()->SetCellColor(cellPositionY, cellPositionX + i, sf::Color(255, 0, 0));
			}*/

			rook.Move(v, GetBoardPtr(), GetBoardViewPtr(), cellPositionY, cellPositionX);

		return v;
		break;

		case ChessValue::Shape::Bishop:


			bishop.Move(v, GetBoardPtr(), GetBoardViewPtr(), cellPositionY, cellPositionX);

			return v;
			break;

		//case ChessValue::Shape::Horse:
		//	
		//	int count = 0;
		//	int* countPtr = &count;

		//	 Gettting max position by direction.
		//	for (int i = 0; i < 4; i++)
		//	{
		//		*countPtr = 0;
		//		for (int j = 0; j < 3; j++)
		//		{
		//			if (j == 2)
		//				isInsideBoard(cellPositionY + (j * stepCoiffDirection[i][0]), cellPositionX + (j * stepCoiffDirection[i][1]));

		//		/*	if (isInsideBoard(cellPositionY + (j * stepCoiffDirection[i][0]), cellPositionX + (j * stepCoiffDirection[i][1])))
		//				*countPtr += 1;*/
		//			else
		//				break;
		//		}

		//		maxStepHorse[i] = *countPtr;
		//	}


		//	for (int i = 0; i < 4; i++)
		//	{
		//		if (maxStepHorse[i] != 0)
		//		{
		//			for (int j = 1; j < maxStepHorse[i]; j++)
		//			{
		//				GetBoardViewPtr()->SetCellColor(cellPositionY + (j * stepCoiffDirection[i][0]), cellPositionX + (j * stepCoiffDirection[i][1]), sf::Color(255, 0, 0));
		//				v.push_back(GetBoardPtr()->GetCell(cellPositionY + (j * stepCoiffDirection[i][0]), cellPositionX + (j * stepCoiffDirection[i][1])));
		//			}
		//		}
		//	}

		//	return v;
		//	break;
		case ChessValue::Shape::Queen:

			bishop.Move(v, GetBoardPtr(), GetBoardViewPtr(), cellPositionY, cellPositionX);
			rook.Move(v, GetBoardPtr(), GetBoardViewPtr(), cellPositionY, cellPositionX);

			return v;

		case ChessValue::Shape::King:

			king.Move(v, GetBoardPtr(), GetBoardViewPtr(), cellPositionY, cellPositionX);

			return v;

		case ChessValue::Shape::Horse:


			horse.Move(v, GetBoardPtr(), GetBoardViewPtr(), cellPositionY, cellPositionX);

			return v;
	};
}

void Controller::BoardController::ClearAllMarks()
{
	GetBoardViewPtr()->ReInitBoardCells();
}

bool Controller::BoardController::isInsideBoard(int y, int x)
{
	return y < 8 && -1 < y && x < 8 && -1 < x;
}

bool Controller::BoardController::canBishopMoveFromToCellInRange(int fromY, int fromX, int toY, int toX)
{
	return isInsideBoard(fromY + toY, fromX + toX);
}

int Controller::BoardController::getStepByDirectionWithStepCountArr(int directionY, int directionX, int stepCount)
{
	return (stepCount + 1) * stepCoiffLateralDirection[directionY][directionX];
}

int Controller::BoardController::getStepCountWithDirection(int directionY, int directionX, int stepCount)
{
	return stepCount * stepCoiffLateralDirection[directionY][directionX];
}

// Where "int direction, int step" is cellPositionY, cellPositionX.
//void Controller::BoardController::BishopMove(int direction, int step, Model::Cell* cell)
//{
//	bool isTrue = true, *isTruePtr = &isTrue;
//	int count = 0;
//	int* countPtr = &count;
//	int maxStep[4] = { 0, 0, 0, 0 };
//
//	// Gettting max position by direction.
//	for (int i = 0; i < 4; i++)
//	{
//		*countPtr = 0;
//		while (*isTruePtr)
//		{
//			if (isInsideBoard(direction + (*countPtr * stepCoiffLateralDirection[i][0]), step + (*countPtr * stepCoiffLateralDirection[i][1])))
//				*countPtr += 1;
//			else
//				break;
//		}
//
//		maxStep[i] = *countPtr;
//	}
//
//
//	for (int i = 0; i < 4; i++)
//	{
//		if (maxStep[i] != 0)
//			for (int j = 1; j < maxStep[i]; j++)
//				GetBoardViewPtr()->SetCellColor(direction + (j * stepCoiffLateralDirection[i][0]), step + (j * stepCoiffLateralDirection[i][1]), sf::Color(255, 0, 0));
//	}
//}

//int Controller::BoardController::getMaxPositionToMoveByCurrentYX(int currentY, int currentX)
//{
//	bool isTrue = true, * isTruePtr = &isTrue;
//	int count = 0;
//	int* countPtr = &count;
//	int maxStep = 0, *maxStepPtr = &maxStep;
//
//	// Define direction for getting max position.
//	for (int i = 0; i < 4; i++)
//	{
//		if (currentY == i)
//		{
//			*countPtr = 0;
//			while (*isTruePtr)
//			{
//				if (isInsideBoard(currentY + (*countPtr * stepCoiffLateralDirection[i][0]), currentX + (*countPtr * stepCoiffLateralDirection[i][1])))
//					*countPtr += 1;
//				else
//					break;
//			}
//
//			*maxStepPtr = *countPtr;
//		}
//	}
//
//	return maxStep;
//}

bool Controller::BoardController::isFilledCell(int y, int x)
{
	if (GetBoardPtr()->GetCellPtr(y, x)->IsFill())
		return true;

	return false;
}

int Controller::BoardController::CountPawn(ChessValue::Type type)
{
	int count = 0;
	int *countPtr = &count;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (GetBoardPtr()->GetCellPtr(i, j)->IsFill() & (GetBoardPtr()->GetCellPtr(i, j)->GetCellPawnPtr()->GetTeamID() == type))
				*countPtr += 1;
		}
	}

	return *countPtr;
}
#include "Cell.hpp"

using namespace Model;


//Cell::Cell(std::string _nameCell, Cell neighborCellRight, Cell neighborCellLeft, Cell neighborCellDown, Cell neighborCellUp,
//	float _x, float _y, float _z, bool _isFill, bool _isCellOfWin)
//{
//	this->nameCell = _nameCell;
//	this->neighborRight = &neighborCellRight;
//	this->neighborLeft = &neighborCellLeft;
//	this->neighborDown = &neighborCellDown;
//	this->neighborUp = &neighborCellUp;
//	this->x = _x;
//	this->y = _y;
//	this->z = _z;
//	this->isFill = _isFill;
//	this->isCellOfWin = _isCellOfWin;
//
//}

void Cell::SetNeighborsArray(Cell neighbors[4])
{
	for (int i = 0; i < this->neighbors->size(); i++)
	{
		this->neighbors->at(i) = neighbors[i];
	}
}

//void Cell::SyncNeighborFieldsToArray(Cell& neighborLeft, Cell neighborRight, Cell neighborDown, Cell neighborUp)
//{
//	
//}


void Cell::SetPosition(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Cell::AddPosition(float x, float y, float z)
{
	this->x += x;
	this->y += y;
	this->z += z;
}

void Cell::SetNeighbor(Cell neighbor, ChessValue::Direction direction)
{
	switch (direction)
	{
	case ChessValue::Direction::left:
		this->neighborLeft = &neighbor;
		break;
	case ChessValue::Direction::right:
		this->neighborRight = &neighbor;
		break;
	case ChessValue::Direction::down:
		this->neighborDown = &neighbor;
		break;
	case ChessValue::Direction::up:
		this->neighborUp = &neighbor;
		break;
	}
}

void Cell::SetNeighbors(Cell neighborCellLeft, Cell neighborCellRight, Cell neighborCellDown, Cell neighborCellUp)
{
	this->neighborLeft = &neighborCellRight;
	this->neighborRight = &neighborCellLeft;
	this->neighborDown = &neighborCellDown;
	this->neighborUp = &neighborCellUp;
}

void Cell::SetNeighbors(Cell neighbors[4])
{
	SetNeighborsArray(neighbors);
}

void Cell::SetName(std::string newName)
{
	this->nameCell = newName;
}

void Cell::SetPawn(Pawn pawn)
{
	this->currentPawn = pawn;
	this->isFill = true;
}

//void Cell::SetSize(float x, float y)
//{
//	this->size[0] = x;
//	this->size[1] = y;
//}

void Cell::MovePawnByFillCheck(ChessValue::Direction direction)
{
	if (GetCellNeighborPtr(direction)->IsFill())
	{
		std::cout << "This cell is fill. Set pawn is impossible!" << std::endl;
	}
	else
	{
		// After change to NULL or Pawn() null
		SetPawn(Pawn());
		GetCellNeighborPtr(direction)->SetPawn(currentPawn);
	}
}

void Cell::MovePawnByType(ChessValue::Direction direction, int step)
{
	switch (currentPawn.GetType())
	{
	case ChessValue::Shape::Pawn:
		GetCellNeighborPtr((ChessValue::Direction)((int)ChessValue::Direction::down + (int)currentPawn.GetTeamID()));
		break;
	}
}

void Cell::MoveToNeighborCell(ChessValue::Direction direction)
{
	MovePawnByFillCheck(direction);
}

//std::vector<float> Cell::GetPosition3D()
//{
//	return this->position;
//}

float Cell::GetPositionX()
{
	return this->x;
}

float Cell::GetPositionY()
{
	return this->y;
}

std::string Cell::GetName()
{
	return this->nameCell;
}


Pawn Cell::GetPawn()
{
	return currentPawn;
}

Pawn* Cell::GetCellPawnPtr()
{
	return &currentPawn;
}

Cell* Cell::GetCellNeighborPtr(ChessValue::Direction direction)
{
	switch (direction)
	{
	case (ChessValue::Direction::left):
		return this->neighborRight;
	case (ChessValue::Direction::right):
		return this->neighborLeft;
	case (ChessValue::Direction::down):
		return this->neighborDown;
	case (ChessValue::Direction::up):
		return this->neighborUp;
	}
}

Cell Cell::GetCellNeighbor(ChessValue::Direction direction)
{
	switch (direction)
	{
	case (ChessValue::Direction::left):
		return *this->neighborRight;
	case (ChessValue::Direction::right):
		return *this->neighborLeft;
	case (ChessValue::Direction::down):
		return *this->neighborDown;
	case (ChessValue::Direction::up):
		return *this->neighborUp;
	}
}

bool Cell::IsFill()
{
	return isFill;
}

bool Cell::IsCellOfWin()
{
	return isCellOfWin;
}

void Cell::ResetCellFromPawn()
{
	this->isFill = false;
	this->currentPawn = Model::Pawn();
}

void Cell::SetNeighborsPtr(Cell* neighborCellLeft, Cell* neighborCellRight, Cell* neighborCellDown, Cell* neighborCellUp)
{
	this->neighborLeft = neighborCellLeft;
	this->neighborRight = neighborCellRight;
	this->neighborDown = neighborCellDown;
	this->neighborUp = neighborCellUp;
}
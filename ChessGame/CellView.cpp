#include "CellView.hpp"

void View::CellView::SetCellShape(sf::RectangleShape shape)
{
	this->cellShape = shape;
	this->cellShapePtr = &cellShape;
}

//void View::CellView::SetCellShapePtr(sf::RectangleShape* shape)
//{
//	this->cellShape = *shape;
//}

void View::CellView::SetCellShapeColor(sf::Color shapeColor)
{
	this->cellShapePtr->setFillColor(shapeColor);
}

sf::RectangleShape View::CellView::GetCellShape()
{
	return cellShape;
}

sf::RectangleShape& View::CellView::GetCellShapeReference()
{
	return cellShape;
}

sf::RectangleShape* View::CellView::GetCellShapePtr()
{
	return this->cellShapePtr;
}

std::string View::CellView::GetName()
{
	return this->nameCell;
}

void View::CellView::SetName(std::string cellName)
{
	this->nameCell = cellName;
}
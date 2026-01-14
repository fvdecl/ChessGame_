#pragma once

#include <SFML/Graphics.hpp>

namespace View 
{
	class CellView
	{
	private:
		std::string nameCell;

		sf::RectangleShape* cellShapePtr;
		sf::RectangleShape cellShape;

	public:
		//CellView(float cellSizeX = 60.0f, float cellSizeY = 60.0f, float cellPositionX = 0.0f, float cellPositionY = 0.0f, sf::Color cellColor = sf::Color(0,0,0));

		void SetCellShape(sf::RectangleShape shape);
		//void SetCellShapePtr(sf::RectangleShape* shape);
		void SetCellShapeColor(sf::Color shapeColor);
		void SetName(std::string name);

		sf::RectangleShape GetCellShape();
		sf::RectangleShape& GetCellShapeReference();
		sf::RectangleShape* GetCellShapePtr();
		std::string GetName();
	};
}



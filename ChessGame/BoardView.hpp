#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>

#include "Game.hpp"
#include "Pawn.hpp"
#include "PawnView.h"
#include "CellView.hpp"

namespace View
{
	class BoardView
	{
	private:
		View::CellView boardView[8][8];
		sf::Texture textureArr[2][6];

		std::string CreateBoardCellNameByAlphabet(char alphabetSym, int boardCellHorizontalPosition);
		char defAlphabet[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

	public:
		BoardView(float cellSizeX = 60.0f, float cellSizeY = 60.0f, float positionMargin = 60.0f);

		View::CellView GetFirstBoardCell();
		void DrawBoard(sf::RenderWindow& window);
		void ReInitBoardCells(float cellSizeX = 60.0f, float cellSizeY = 60.0f, float positionMargin = 60.0f);
		//void ChangeBoardCellColor(int cellPositionX, int cellPositionY, sf::Color color);
		void SetCellColor(int cellPositionY, int cellPositionX, sf::Color color);
		CellView GetCell(int cellPositionY, int cellPositionX);
		CellView* GetCellPtr(int cellPositionY, int cellPositionX);
		void ShowStepsForCell(int cellPositionY, int cellPositionX);
		sf::RenderWindow* GetTargetWindowReference();
		void SetupPawn(std::vector<std::vector<sf::Texture>>&textureArr);
		void SetupCell(float cellSizeX, float cellSizeY, float positionMargin);
		CellView* FindCellByNamePtr(std::string cellName);
	};
}

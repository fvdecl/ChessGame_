#pragma once

#include <string>
#include <vector>

#include "Game.hpp"
#include "Pawn.hpp"

namespace Model
{
	class Cell
	{

	private:

		std::string nameCell;

		float x, y, z;
		float position[3] = { x, y, z };

		Cell* neighborLeft, * neighborRight, * neighborDown, * neighborUp;
		// Reference to previous line.
		std::vector<Cell> neighbors[4];

		// Pawn* currentPawnPtr = nullptr; // Pawn cell slot
		Pawn currentPawn = Model::Pawn();
		bool isFill, isCellOfWin;


		void SetNeighborsArray(Cell neighbors[4]);

		void SyncNeighborFieldsToArray();
		void SyncNeighborArrayToFields();

	public:
		
		Cell(std::string _nameCell = "undefined", Cell* neighborCellLeft =	nullptr, Cell* neighborCellRight = nullptr, Cell* neighborCellDown = nullptr, Cell* neighborCellUp = NULL,
			float _x = 0.0f, float _y = 0.0f, float _z = 0.0f, bool _isFill = false, bool _isCellOfWin = false, Pawn _currentPawn = Pawn()) : nameCell(_nameCell), neighborLeft(neighborCellLeft), neighborRight(neighborCellRight), neighborDown(neighborCellDown), neighborUp(neighborCellUp), x(_x), y(_y), z(_z), isFill(_isFill), isCellOfWin(_isCellOfWin), currentPawn(_currentPawn) {}

		/* Setters */

		void SetName(std::string newName);
		void SetPawn(Pawn pawn);

		void SetNeighbor(Cell neighbor, ChessValue::Direction direction);
		void SetNeighbors(Cell neighborCellLeft, Cell neighborCellRight, Cell neighborCellDown, Cell neighborCellUp);
		void SetNeighborsPtr(Cell* neighborCellLeft, Cell* neighborCellRight, Cell* neighborCellDown, Cell* neighborCellUp);
		/* neighbors: right, left, down, up */
		void SetNeighbors(Cell neighbors[4]);



		/* Getters */

		std::string GetName();
		Pawn GetPawn();
		Pawn* GetCellPawnPtr();
		Cell GetCellNeighbor(ChessValue::Direction direction);
		Cell* GetCellNeighborPtr(ChessValue::Direction direction);
		std::vector<float> GetPosition3D();
		float GetPositionX(), GetPositionY();


		void AddPosition(float x, float y, float z);
		void SetPosition(float x, float y, float z);
		//void SetSize(float x, float y);

		bool IsFill(), IsCellOfWin();


		void MovePawnByFillCheck(ChessValue::Direction direction);
		void MovePawnByType(ChessValue::Direction direction, int step);
		void MoveToNeighborCell(ChessValue::Direction direction);

		void ResetCellFromPawn();
	};
}
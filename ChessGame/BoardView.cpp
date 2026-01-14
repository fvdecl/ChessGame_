#include "BoardView.hpp"


View::BoardView::BoardView(float cellSizeX, float cellSizeY, float positionMargin)
{
    SetupCell(cellSizeX, cellSizeY, positionMargin);
}

View::CellView View::BoardView::GetFirstBoardCell()
{
    return boardView[0][0];
}

void View::BoardView::DrawBoard(sf::RenderWindow& window)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            window.draw(boardView[i][j].GetCellShapeReference());
}

void View::BoardView::SetCellColor(int cellPositionY, int cellPositionX, sf::Color color)
{
    boardView[cellPositionY][cellPositionX].SetCellShapeColor(color);
}

void View::BoardView::ReInitBoardCells(float cellSizeX, float cellSizeY, float positionMargin)
{
    // Creating new cell shapes
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            boardView[i][j].GetCellShapePtr()->setPosition(j * positionMargin, i * positionMargin);
            boardView[i][j].GetCellShapePtr()->setFillColor(sf::Color(255, 255, 255, 255));
            if ((j + i) % 2 == 0) boardView[i][j].GetCellShapePtr()->setFillColor(sf::Color(65, 65, 65, 255));
            // std::cout << rect.getPosition().x << ' ' << rect.getPosition().y << std::endl;
        }
    }

    // Add cell shapes into array.

}

View::CellView View::BoardView::GetCell(int cellPositionY, int cellPositionX)
{
    return this->boardView[cellPositionY][cellPositionX];
}

View::CellView* View::BoardView::GetCellPtr(int cellPositionY, int cellPositionX)
{
    return &this->boardView[cellPositionY][cellPositionX];
}

void View::BoardView::SetupPawn(std::vector<std::vector<sf::Texture>> &textureArr)
{
        for (int j = 0; j < 2; j++)
            for (int h = 0; h < 8; h++)
                boardView[1 + (j * 5)][h].GetCellShapePtr()->setTexture(&textureArr.at(j).at(0));

        for (int j = 0; j < 2; j++)
        {
            for (int h = 1; h < 6; h++)
                boardView[j * 7][h - 1].GetCellShapePtr()->setTexture(&textureArr.at(j).at(h));
            for (int h = 1; h < 4; h++)
                boardView[j * 7][4 + h].GetCellShapePtr()->setTexture(&textureArr.at(j).at(4 - h));
        }
}

std::string View::BoardView::CreateBoardCellNameByAlphabet(char alphabetSym, int boardCellHorizontalPosition)
{
    return alphabetSym + std::to_string(boardCellHorizontalPosition);
}

void View::BoardView::SetupCell(float cellSizeX, float cellSizeY, float positionMargin)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            sf::RectangleShape rect(sf::Vector2f(cellSizeX, cellSizeY));
            rect.setPosition(j * positionMargin, i * positionMargin);
            rect.setFillColor(sf::Color(255, 255, 255, 255));
            if ((j + i) % 2 == 0) rect.setFillColor(sf::Color(65, 65, 65, 255));
            // std::cout << rect.getPosition().x << ' ' << rect.getPosition().y << std::endl;


            this->boardView[i][j].SetCellShape(rect);
            this->boardView[i][j].SetName(CreateBoardCellNameByAlphabet(defAlphabet[i], j));
        }
    }
}

View::CellView* View::BoardView::FindCellByNamePtr(std::string cellName)
{
    for (int i = 0; i < sizeof(boardView[0]) / sizeof(boardView[0][0]); i++)
        for (int j = 0; j < sizeof(boardView[0]) / sizeof(boardView[0][0]); j++)
            if (cellName == boardView[i][j].GetName())
                return &boardView[i][j];
}
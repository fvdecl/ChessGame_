#include "Log.h"

void Log::PrintViewCellPositions(Model::Board boardModel)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << boardModel.GetCell(i, j).GetPositionX() << ' ' << boardModel.GetCell(i, j).GetPositionY() << std::endl << std::endl;
        }
        std::cout << std::endl;
    }
}

void Log::PrintModelCellFill(Model::Board boardModel)
{
    for (int y = 0; y < 8; y++)
    {
        std::cout << std::endl;
        for (int x = 0; x < 8; x++)
        {
            std::cout << (int)boardModel.GetCell(y, x).GetPawn().GetType() + (int)boardModel.GetCell(y, x).IsFill() << ' ';
        }
        std::cout << std::endl;
    }
}

void Log::PrintCellClickData(Model::Cell* cellPtr)
{
    std::cout << std::endl << "***CLICKED CELL DATA***" << std::endl;
    std::cout << "Coord: " << cellPtr->GetName() << std::endl;
    std::cout << "IsFill:" << cellPtr->IsFill() << std::endl;
    std::cout << "Shape:" << (int)cellPtr->GetPawn().GetType() << std::endl;
    std::cout << "IsDeath:" << cellPtr->GetPawn().IsDeath() << std::endl;
    std::cout << "TeamId:" << (int)cellPtr->GetPawn().GetTeamID() << std::endl;
    std::cout << "***END DATA***" << std::endl << std::endl;
}
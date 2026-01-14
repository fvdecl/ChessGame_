////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <SFML/Graphics.hpp>


#include "Log.h"

#include "Game.hpp"
#include "Board.hpp"
#include "BoardView.hpp"
#include "Pawn.hpp"
#include "BoardController.h"
#include "GameView.h"


std::vector<std::vector<sf::Texture>> getTextureV()
{
    std::string texturePath[2][6] = {
        {
            "Assets/Texture/chess_figure/piece_b_0.png", "Assets/Texture/chess_figure/piece_b_1.png", "Assets/Texture/chess_figure/piece_b_2.png", "Assets/Texture/chess_figure/piece_b_3.png", "Assets/Texture/chess_figure/piece_b_4.png", "Assets/Texture/chess_figure/piece_b_5.png"
        },
        {
            "Assets/Texture/chess_figure/piece_w_0.png", "Assets/Texture/chess_figure/piece_w_1.png", "Assets/Texture/chess_figure/piece_w_2.png", "Assets/Texture/chess_figure/piece_w_3.png", "Assets/Texture/chess_figure/piece_w_4.png", "Assets/Texture/chess_figure/piece_w_5.png"
        }
    };

    sf::Texture textureArr[2][6];
    std::vector<std::vector<sf::Texture>> textureV;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            if (!textureArr[i][j].loadFromFile(texturePath[i][j]))
                std::cout << "Texture is undefined" << std::endl;

    for (int i = 0; i < 2; i++)
    {
        textureV.push_back(std::vector<sf::Texture>());
        for (int j = 0; j < 8; j++)
        {
            textureV.at(i).push_back(textureArr[i][j]);
        }
    }


    return textureV;
}


int main()
{
    Log log;

    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    char alphabet[8] = { 'a', 'b', 'c', 'd', 'f', 'e', 'g', 'h' };
    

    std::string texturePath[2][6] = {
        {
            "Assets/Texture/chess_figure/piece_b_0.png", "Assets/Texture/chess_figure/piece_b_1.png", "Assets/Texture/chess_figure/piece_b_2.png", "Assets/Texture/chess_figure/piece_b_3.png", "Assets/Texture/chess_figure/piece_b_4.png", "Assets/Texture/chess_figure/piece_b_5.png"
        },
        {
            "Assets/Texture/chess_figure/piece_w_0.png", "Assets/Texture/chess_figure/piece_w_1.png", "Assets/Texture/chess_figure/piece_w_2.png", "Assets/Texture/chess_figure/piece_w_3.png", "Assets/Texture/chess_figure/piece_w_4.png", "Assets/Texture/chess_figure/piece_w_5.png"
        }
    };
    
    sf::Texture textureArr[2][6];
    std::vector<std::vector<sf::Texture>> textureV;

    /*for (int i = 0; i < 2; i++)
        textureV.push_back(std::vector<sf::Texture>());*/

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 6; j++)
            if (!textureArr[i][j].loadFromFile(texturePath[i][j]))
                std::cout << "Texture is undefined" << std::endl;

    for (int i = 0; i < 2; i++)
    {
        textureV.push_back(std::vector<sf::Texture>());
        for (int j = 0; j < 8; j++)
        {
            textureV.at(i).push_back(textureArr[i][j]);
        }
    }

    // LOAD ONLY FROM MAIN()
    //for (int i = 0; i < 2; i++)
        /*for (int j = 0; j < 6; j++)
            if (!textureArr->at(j).loadFromFile(texturePath[0][j]))
                std::cout << "Texture is undefined" << std::endl;*/


    // Model #MVC
    Model::Board chessBoard(60.0f, 60.0f, 60.0f);
    View::BoardView boardView(60.0f, 60.0f, 60.0f);
    Controller::BoardController boardController(chessBoard, boardView);
    View::GameView gameView();

    chessBoard.SetupPawn();
    boardView.SetupPawn(textureV);
    
    // PRINT CELL POSITIONS
    std::cout << std::endl << std::endl << "***CELL GRAPHIC COORDS***" << std::endl;
    log.PrintViewCellPositions(chessBoard);
    std::cout << "***END***" << std::endl << std::endl << std::endl;


    // PRINT IS FILL CELL
    std::cout << std::endl << "***CELL MODEL FILL***";
    log.PrintModelCellFill(chessBoard);
    std::cout << "***END***" << std::endl << std::endl << std::endl;


    sf::RenderWindow window(sf::VideoMode(640, 480), "ChessGame", sf::Style::Titlebar | sf::Style::Close, contextSettings);
    

    Model::Game chessGame(ChessValue::Type::White);

    sf::Font font;
    font.loadFromFile("Fonts/arial.ttf");
    if (!font.loadFromFile("Fonts/arial.ttf"))
        std::cout << "Error" << std::endl;

    sf::Text currentPlayerText("Current player: " + std::to_string((int)chessGame.getCurrentChessPlayer()), font, 18);
    sf::Text whiteChessText("White pawn: " + std::to_string(boardController.CountPawn(ChessValue::Type::White)), font, 18);
    sf::Text blackChessText("Black pawn: " + std::to_string(boardController.CountPawn(ChessValue::Type::Black)), font, 18);

    currentPlayerText.setPosition(480, 100);
    whiteChessText.setPosition(480, 130);
    blackChessText.setPosition(480, 160);


    Model::Cell lastSelectedCell;
    Model::Cell *lastSelectedCellPtr = &lastSelectedCell;
    bool isHavingSelectedCell = false;
    bool* isHavingSelectedCellPtr = &isHavingSelectedCell;

    std::vector<Model::Cell> stepsForSelectedCell;
    std::vector<Model::Cell>* stepsForSelectedCellPtr = &stepsForSelectedCell;

    sf::RectangleShape textureRes;
    sf::RectangleShape* textureResPtr = &textureRes;

    int lastSelectedCellX, lastSelectedCellY, *lastSelectedCellXPtr = &lastSelectedCellX, *lastSelectedCellYPtr = &lastSelectedCellY;

    // Start the game loop
    while (window.isOpen())
    {
        window.clear();

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {

            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.x < 480))
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << std::endl << "***LEFT CLICK COORDS***" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    std::cout << "***END***" << std::endl << std::endl;

                    log.PrintCellClickData(boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60));

                    switch (*isHavingSelectedCellPtr)
                    {
                    case true:
                        for (int i = 0; i < stepsForSelectedCellPtr->size(); i++)
                        {
                            if (boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetName() == stepsForSelectedCellPtr->at(i).GetName() &&
                                boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetCellPawnPtr()->GetTeamID() != lastSelectedCellPtr->GetCellPawnPtr()->GetTeamID())
                            {
                                // Model
                                boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->SetPawn(lastSelectedCellPtr->GetPawn());
                                boardController.GetBoardPtr()->FindCellByNamePtr(lastSelectedCellPtr->GetName())->ResetCellFromPawn();

                                // View
                                boardController.GetBoardViewPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetCellShapePtr()->setTexture(textureResPtr->getTexture());
                                boardController.GetBoardViewPtr()->FindCellByNamePtr(lastSelectedCellPtr->GetName())->GetCellShapePtr()->setTexture(NULL, true);
                                
                                //lastSelectedCellPtr->ResetCellFromPawn();
                                // Remove pawn.
                                boardController.ClearCellByCellName(lastSelectedCellPtr->GetName());

                                // if newCellName != lastCellName
                                if (boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetName() != lastSelectedCellPtr->GetName())
                                    chessGame.SwitchChessPlayer();
                            }
                        }

                        //std::cout << "New pawn team: " << (int)boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetPawn().GetTeamID() << std::endl;

                        *isHavingSelectedCellPtr = false;
                        stepsForSelectedCellPtr->clear();

                        boardController.ClearAllMarks();

                        break;
                    case false:
                        lastSelectedCellPtr = boardController.SelectCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60);
                        //std::cout << "Hueta: " << boardController.GetBoardViewPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetCellShape().getFillColor().a << std::endl;

                        if (lastSelectedCellPtr->GetCellPawnPtr()->GetTeamID() == chessGame.getCurrentChessPlayer())
                        {
                            std::cout << "To front from pawn: " << boardController.GetBoardPtr()->GetCellPtr((((event.mouseButton.y + (60 + ((int)lastSelectedCellPtr->GetPawn().GetTeamID() * -120))) / 60)), event.mouseButton.x / 60)->IsFill() << std::endl;
                            //std::cout << "last selected: " << ((lastSelectedCellPtr->GetCellPawnPtr()->GetTeamID() == chessGame.getCurrentChessPlayer()) ? 0 : 1) << std::endl;
                            if (lastSelectedCellPtr->IsFill());
                            {
                                // Error is here
                                *stepsForSelectedCellPtr = boardController.ShowStepsForCellWithPawn(event.mouseButton.y / 60, event.mouseButton.x / 60, boardController.GetBoardPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60));
                                //std::cout << stepsForSelectedCellPtr->at(0).GetName();
                                //*textureResPtr = boardController.GetBoardViewPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetCellShapePtr()->getTexture();
                                
                                *textureResPtr = boardController.GetBoardViewPtr()->GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetCellShapeReference();
                            }

                            /*if (1 < stepsForSelectedCellPtr->size())
                                std::cout << ' ' << stepsForSelectedCellPtr->at(1).GetName() << std::endl;*/

                            for (int i = 0; i < stepsForSelectedCellPtr->size(); i++)
                                std::cout << stepsForSelectedCellPtr->at(i).GetName() << ' ' << std::endl;

                            std::cout << std::endl;

                            *isHavingSelectedCellPtr = true;
                        }

                        break;
                    }

                    std::cout << "Color (source): " << (int)boardView.GetCellPtr(event.mouseButton.y / 60, event.mouseButton.x / 60)->GetCellShape().getFillColor().r << std::endl;
                }

                std::cout << std::endl << "***CELL MODEL FILL***";
                log.PrintModelCellFill(chessBoard);
                std::cout << "***END***" << std::endl << std::endl << std::endl;
            }

            // Resize event: adjust the viewport
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }

        boardView.DrawBoard(window);
        // Player
        currentPlayerText.setString("Current player: " + std::to_string((int)chessGame.getCurrentChessPlayer()));
        window.draw(currentPlayerText);
        // White
        whiteChessText.setString("White pawn: " + std::to_string(boardController.CountPawn(ChessValue::Type::White)));
        window.draw(whiteChessText);
        // Black
        blackChessText.setString("Black pawn: " + std::to_string(boardController.CountPawn(ChessValue::Type::Black)));
        window.draw(blackChessText);

        // Finally, display the rendered frame on screen
        window.display();
    }

    return EXIT_SUCCESS;
}

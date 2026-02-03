#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "BoardController.h"
#include "GameSession.hpp"


namespace Controller
{
    class Game
    {
    public:
        Game(sf::RenderWindow& window);
        void Run();
        void UpdateTexts();

    private:
        void ProcessEvents();
        void HandleMouseClick(const sf::Event& event);
        void SelectCell(int row, int col);
        void TryMove(int row, int col);
        void Update();
        void Render();

    private:
        sf::RenderWindow& window;

        Model::Board board;
        View::BoardView boardView;
        Controller::BoardController boardController;
        Model::GameSession chessGame;


        bool hasSelectedCell = false;
        Model::Cell* selectedCell = nullptr;
        std::vector<Model::Cell> availableSteps;

        sf::RectangleShape selectedTexture;
        
        sf::Font font;

        sf::Text currentPlayerText;
        sf::Text whiteChessText;
        sf::Text blackChessText;
    };
}
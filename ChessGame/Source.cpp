#include <iostream>

#include "Game.hpp"
#include "GameSession.hpp"


int main()
{
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    sf::RenderWindow window(sf::VideoMode(640, 480), "ChessGame", sf::Style::Titlebar | sf::Style::Close, contextSettings);
    Model::GameSession chessGame(ChessValue::Type::White);

    Controller::Game game(window);
    game.Run();

    return EXIT_SUCCESS;
}

#include "Game.hpp"

Controller::Game::Game(sf::RenderWindow& win)
    : window(win),
    board(60.0f, 60.0f, 60.0f),
    boardView(60.0f, 60.0f, 60.0f),
    boardController(board, boardView),
    chessGame(ChessValue::Type::White)
{
    if (!font.loadFromFile("Fonts/arial.ttf"))
        std::cout << "Error loading font" << std::endl;

    currentPlayerText.setFont(font);
    currentPlayerText.setCharacterSize(18);
    currentPlayerText.setPosition(480, 100);

    whiteChessText.setFont(font);
    whiteChessText.setCharacterSize(18);
    whiteChessText.setPosition(480, 130);

    blackChessText.setFont(font);
    blackChessText.setCharacterSize(18);
    blackChessText.setPosition(480, 160);


    board.SetupPawn();
    boardView.SetupPawn();

    UpdateTexts();
}

void Controller::Game::Run()
{
    while (window.isOpen())
    {
        ProcessEvents();
        // Update();
        Render();
    }
}

void Controller::Game::UpdateTexts()
{
    currentPlayerText.setString(
        "Current player: " +
        std::to_string((int)chessGame.getCurrentChessPlayer()));

    whiteChessText.setString(
        "White pawn: " +
        std::to_string(boardController.CountPawn(ChessValue::Type::White)));

    blackChessText.setString(
        "Black pawn: " +
        std::to_string(boardController.CountPawn(ChessValue::Type::Black)));
}

void Controller::Game::TryMove(int row, int col)
{
    Model::Cell* targetCell =
        boardController.GetBoardPtr()->GetCellPtr(row, col);

    for (auto& step : availableSteps)
    {
        if (step.GetName() == targetCell->GetName())
        {
            targetCell->SetPawn(selectedCell->GetPawn());
            boardController
                .GetBoardPtr()
                ->FindCellByNamePtr(selectedCell->GetName())
                ->ResetCellFromPawn();

            boardController
                .GetBoardViewPtr()
                ->GetCellPtr(row, col)
                ->GetCellShapePtr()
                ->setTexture(selectedTexture.getTexture());

            boardController
                .GetBoardViewPtr()
                ->FindCellByNamePtr(selectedCell->GetName())
                ->GetCellShapePtr()
                ->setTexture(nullptr, true);

            if (targetCell->GetName() != selectedCell->GetName())
            {
                chessGame.SwitchChessPlayer();
                UpdateTexts();
            }

            break;
        }
    }

    boardController.ClearAllMarks();
    availableSteps.clear();
    hasSelectedCell = false;
}

void Controller::Game::Render()
{
    window.clear();

    boardView.DrawBoard(window);

    window.draw(currentPlayerText);
    window.draw(whiteChessText);
    window.draw(blackChessText);

    window.display();
}

void Controller::Game::ProcessEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed &&
            event.key.code == sf::Keyboard::Escape)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left &&
            event.mouseButton.x < 480)
        {
            HandleMouseClick(event);
        }
    }
}

void Controller::Game::HandleMouseClick(const sf::Event& event)
{
    int row = event.mouseButton.y / 60;
    int col = event.mouseButton.x / 60;

    if (!hasSelectedCell)
    {
        SelectCell(row, col);
    }
    else
    {
        TryMove(row, col);
    }
}

void Controller::Game::SelectCell(int row, int col)
{
    selectedCell = boardController.SelectCellPtr(row, col);

    if (selectedCell &&
        selectedCell->GetCellPawnPtr()->GetTeamID() ==
        chessGame.getCurrentChessPlayer())
    {
        availableSteps =
            boardController.ShowStepsForCellWithPawn(row, col, selectedCell);

        selectedTexture =
            boardController.GetBoardViewPtr()
            ->GetCellPtr(row, col)
            ->GetCellShapeReference();

        hasSelectedCell = true;
    }
}
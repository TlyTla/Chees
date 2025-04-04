#include "StartGame.hpp"

void StartGame::Start()
{
	do 
	{
		PrintBoardAndDesignations(GameBoard.MainGameBoard);
		NextPlayer();
	} while (!GameOver());
	GameBoard.PrintBoard();
}

void StartGame::NextPlayer()
{
	if (player == 'W')
	{
		player = 'B';
	}
	else
	{
		player = 'W';
	}
}

bool StartGame::GameOver()
{
	bool possibleMove(false);

	possibleMove = GameBoard.MovePlayer(player);

	if (!possibleMove) 
	{
		if (GameBoard.DangerToTheKing(player)) 
		{
			NextPlayer();
			std::cout << "Шах и мат, " << player << " Урааааа победа!!!!!" << std::endl;
		}
		else 
		{
			std::cout << "Больше нет ходов!" << std::endl;
		}
	}
	return !possibleMove;
}

void StartGame::PrintBoardAndDesignations(ChessPiece* GameBoard[8][8])
{
    bool bValidMove = false;
    do 
    {
        system("clear");
        std::cout << std::endl << std::endl << "          Welcome to Chess Game Developed by Cppsecrets " << std::endl << std::endl << std::endl;
        std::cout << "                      Keys to sysmbols used " << std::endl << std::endl << std::endl;
        std::cout << " * = white space" << std::endl;
        std::cout << " Blank space = black space" << std::endl;
        std::cout << " WP = White pawn &  BP = Black pawn" << std::endl;
        std::cout << " WN = White Knight & BN = Black Knight" << std::endl;
        std::cout << " WB = White Bishop & BB = Black Bishop" << std::endl;
        std::cout << " WR = White Rook & BR = Black Rook" << std::endl;
        std::cout << " WQ = White Queen & BQ = Black Queen" << std::endl;
        std::cout << " WK = White King & BK =Black King" << std::endl;
        std::cout << "Rule for move is :" << std::endl;
        std::cout << "Move by selecting row & column to another valid location using row & column" << std::endl << std::endl << std::endl;
        this->GameBoard.PrintBoard();

        int startMove, endMove;

        std::cout << player << "'s Move: ";
        std::cin >> startMove;

        int startLine = (startMove / 10) - 1, startCol = (startMove % 10) - 1;

        std::cout << "To: ";
        std::cin >> endMove;

        int endLine = (endMove / 10) - 1, endCol = (endMove % 10) - 1;
       

        if ((startLine >= 0 && startLine <= 7) &&
            (startCol >= 0 && startCol <= 7) &&
            (endLine >= 0 && endLine <= 7) &&
            (endCol >= 0 && endCol <= 7)) {
         

            ChessPiece* qpCurrPiece = GameBoard[startLine][startCol];
          

            if ((qpCurrPiece != 0) && (qpCurrPiece->GetColorChessPiece() == player))
            {
              

                if (qpCurrPiece->CorrentMove(startLine, startCol, endLine, endCol, GameBoard))
                {
                   
                   
                    ChessPiece* pFigureMove = GameBoard[endLine][endCol];
                    GameBoard[endLine][endCol] = GameBoard[startLine][startCol];
                    GameBoard[startLine][startCol] = 0;
                    
                    if (!this->GameBoard.DangerToTheKing(player)) 
                    {
                        delete pFigureMove;
                        bValidMove = true;
                    }
                    else 
                    { 
                        GameBoard[startLine][startCol] = GameBoard[endLine][endCol];
                        GameBoard[endLine][endCol] = pFigureMove;
                    }
                }
            }
        }
        if (!bValidMove) 
        {
            std::cout << "Неправильный ход!" << std::endl;
        }
    } while (!bValidMove);
}

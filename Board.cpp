#include "Board.hpp"

Board::Board()
{
    for (int line = 0; line < 8; ++line) 
    {
        for (int col = 0; col < 8; ++col) 
        {
            MainGameBoard[line][col] = 0;
        }
    }

    for (int col = 0; col < 8; ++col) 
    {
        MainGameBoard[6][col] = new PawnFigure('B');
    }

    MainGameBoard[7][0] = new RookFigure('B');
    MainGameBoard[7][1] = new HorseFigure('B');
    MainGameBoard[7][2] = new ElephantFigure('B');
    MainGameBoard[7][3] = new KingFigure('B');
    MainGameBoard[7][4] = new QueenFigure('B');
    MainGameBoard[7][5] = new ElephantFigure('B');
    MainGameBoard[7][6] = new HorseFigure('B');
    MainGameBoard[7][7] = new RookFigure('B');
 
    for (int col = 0; col < 8; ++col) 
    {
        MainGameBoard[1][col] = new PawnFigure('W');
    }

    MainGameBoard[0][0] = new RookFigure('W');
    MainGameBoard[0][1] = new HorseFigure('W');
    MainGameBoard[0][2] = new ElephantFigure('W');
    MainGameBoard[0][3] = new KingFigure('W');
    MainGameBoard[0][4] = new QueenFigure('W');
    MainGameBoard[0][5] = new ElephantFigure('W');
    MainGameBoard[0][6] = new HorseFigure('W');
    MainGameBoard[0][7] = new RookFigure('W');
}
Board::~Board()
{
    for (int line = 0; line < 8; ++line) 
    {
        for (int col = 0; col < 8; ++col) 
        {
            delete MainGameBoard[line][col];
            MainGameBoard[line][col] = 0;
        }
    }
}

void Board::PrintBoard()
{
    const int widthSquare = 4;
    const int heightSquare = 3;
    for (int line = 0; line < 8 * heightSquare; ++line) 
    {
        
        int squareLine = line / heightSquare;
        if (line % 3 == 1) 
        {
            std::cout << '|' << (char)('1' + 7 - squareLine)<< '|';
        }
        else 
        {
            std::cout << "---";
        }
        
        
        for (int col = 0; col < 8 * widthSquare; ++col) 
        {
            int squareCol = col / widthSquare;
            if (((line % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && MainGameBoard[7 - squareLine][squareCol] != 0) 
            {
                if ((col % 4) == 1)
                {
                    std::cout << MainGameBoard[7 - squareLine][squareCol]->GetColorChessPiece();
                }
                else 
                {
                    std::cout << MainGameBoard[7 - squareLine][squareCol]->GetChessPiece();
                }
            }
            else 
            {
                if ((squareLine + squareCol) % 2 == 1)
                {
                    std::cout << '#';
                }
                else 
                {
                    std::cout << ' ';
                }
            }
        }
        std::cout << std::endl;
    }
  
    for (int line = 0; line < heightSquare; ++line) 
    {
        if (line % 3 == 1) 
        {
            std::cout << "  |";
            for (int col = 0; col < 8 * widthSquare; ++col) 
            {
                int squareCol = col / widthSquare;
                if ((col % 4) == 1) 
                {
                    std::cout << (squareCol + 1);
                }
                else 
                {
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
        }
        else 
        {
            for (int iCol = 1; iCol < 9 * widthSquare; ++iCol) 
            {
                std::cout << '-';
            }
            std::cout << std::endl;
        }
    }
}

bool Board::DangerToTheKing(char colorChessPiece)
{
    int lineKing, colKing;
    for (int line = 0; line < 8; ++line)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (MainGameBoard[line][col] != 0)
            {
                if (MainGameBoard[line][col]->GetColorChessPiece() == colorChessPiece)
                {
                    if (MainGameBoard[line][col]->GetChessPiece() == 'K')
                    {
                        lineKing = line;
                        colKing = col;
                    }
                }
            }
        }
    }

    for (int line = 0; line < 8; ++line)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (MainGameBoard[line][col] != 0)
            {
                if (MainGameBoard[line][col]->GetColorChessPiece() != colorChessPiece)
                {
                    if (MainGameBoard[line][col]->CorrentMove(line, col, lineKing, colKing, MainGameBoard))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Board::MovePlayer(char colorChessPiece)
{
    for (int line = 0; line < 8; ++line)
    {
        for (int col = 0; col < 8; ++col)
        {
            if (MainGameBoard[line][col] != 0)
            {
               
                if (MainGameBoard[line][col]->GetColorChessPiece() == colorChessPiece)
                {
                    for (int lineMove = 0; lineMove < 8; ++lineMove)
                    {
                        for (int colMove = 0; colMove < 8; ++colMove)
                        {
                            if (MainGameBoard[line][col]->CorrentMove(line, col, lineMove, colMove, MainGameBoard))
                            {
                                
                                ChessPiece* pFigureMove = MainGameBoard[lineMove][colMove];
                                MainGameBoard[lineMove][colMove] = MainGameBoard[line][col];
                                MainGameBoard[line][col] = 0;
                                bool possibleMove = !DangerToTheKing(colorChessPiece);
                                
                                MainGameBoard[line][col] = MainGameBoard[lineMove][colMove];
                                MainGameBoard[lineMove][colMove] = pFigureMove;
                                if (possibleMove)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

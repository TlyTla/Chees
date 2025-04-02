#include "Board.hpp"

Board::Board()
{
    for (int line = 0; line < 8; ++line) {
        for (int col = 0; col < 8; ++col) {
            MainGameBoard[line][col] = 0;
        }
    }

    for (int col = 0; col < 8; ++col) {
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
 
    for (int col = 0; col < 8; ++col) {
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
    for (int line = 0; line < 8; ++line) {
        for (int col = 0; col < 8; ++col) {
            delete MainGameBoard[line][col];
            MainGameBoard[line][col] = NULL;
        }
    }
}

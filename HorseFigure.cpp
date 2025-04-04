#include "HorseFigure.hpp"

char HorseFigure::GetChessPiece()
{
    return 'H';
}

bool HorseFigure::CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8])
{
    if ((current—olumn == which—olumn + 1) || (current—olumn == which—olumn - 1))
    {
        if ((currentLine == whichLine + 2) || (currentLine == whichLine - 2))
        {
            return true;
        }
    }
    if ((current—olumn == which—olumn + 2) || (current—olumn == which—olumn - 2))
    {
        if ((currentLine == whichLine + 1) || (currentLine == whichLine - 1))
        {
            return true;
        }
    }
    return false;
}

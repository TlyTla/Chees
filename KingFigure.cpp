#include "KingFigure.hpp"

char KingFigure::GetChessPiece()
{
    return '';
}

bool KingFigure::CorrectChessMove(int currentLine, int current�olumn, int whichLine, int which�olumn, ChessPiece* GameBoard[8][8])
{
    int moveLine = whichLine - currentLine;
    int moveColumn = which�olumn - current�olumn;
    if (((moveLine >= -1) && (moveLine <= 1)) &&
        ((moveColumn >= -1) && (moveColumn <= 1)))
    {
        return true;
    }
    return false;
}

#include "KingFigure.hpp"

char KingFigure::GetChessPiece()
{
    return '';
}

bool KingFigure::CorrectChessMove(int currentLine, int currentÑolumn, int whichLine, int whichÑolumn, ChessPiece* GameBoard[8][8])
{
    int moveLine = whichLine - currentLine;
    int moveColumn = whichÑolumn - currentÑolumn;
    if (((moveLine >= -1) && (moveLine <= 1)) &&
        ((moveColumn >= -1) && (moveColumn <= 1)))
    {
        return true;
    }
    return false;
}

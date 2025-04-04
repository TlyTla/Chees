#include "RookFIgure.hpp"

char RookFigure::GetChessPiece()
{
	return 'R';
}

bool RookFigure::CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8])
{
    if (currentLine == whichLine)
    {
        int setCol;
        if (which—olumn - current—olumn > 0)
        {
            setCol = 1;
        }
        else
        {
            setCol = -1;
        }

        for (int tempCol = current—olumn + setCol; tempCol != which—olumn; tempCol += setCol)
        {
            if (GameBoard[currentLine][tempCol] != 0)
            {
                return false;
            }
        }
        return true;
    }
    else if (which—olumn == current—olumn)
    {
        int setLine;
        if (whichLine - currentLine > 0)
        {
            setLine = 1;
        }
        else
        {
            setLine = -1;
        }

        for (int tempLine = currentLine + setLine; tempLine != whichLine; tempLine += setLine)
        {
            if (GameBoard[tempLine][current—olumn] != 0)
            {
                return false;
            }
        }
        return true;
    }
    return false;
}


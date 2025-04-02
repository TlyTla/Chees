#include "ElephantFigure.hpp"

char ElephantFigure::GetChessPiece()
{
	return '';
}

bool ElephantFigure::CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8])
{
    if ((which—olumn - current—olumn == whichLine - currentLine) || (which—olumn - current—olumn == currentLine - whichLine)) 
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

        int setLine;
        if (whichLine - currentLine > 0)
        {
            setLine = 1;
        }
        else
        {
            setLine = -1;
        }

        for (int tempLine = currentLine + setLine, int tempCol = current—olumn + setCol; 
            tempLine != whichLine; tempLine +=setLine, tempCol += setCol)
        {
            if (GameBoard[tempLine][tempCol] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

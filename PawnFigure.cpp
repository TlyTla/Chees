#include "PawnFigure.hpp"

char PawnFigure::GetChessPiece()
{
	return "";
}

bool PawnFigure::CorrectChessMove(int currentLine, int currentÑolumn, int whichLine, int whichÑolumn, ChessPiece* GameBoard[8][8])
{
	//óêàçàòåëü íà ìåñòî êóäà õî÷åò ôèãóğà
	ChessPiece* pFigureMove = GameBoard[whichLine][whichÑolumn];
	if (pFigureMove == 0)
	{
		if (currentÑolumn == whichÑolumn)
		{
			if (GetColorChessPiece() == 'W')
			{
				if (whichLine == currentLine + 1)
				{
					return true;
				}
			}
			else
			{
				if (whichLine == currentLine - 1)
				{
					return true;
				}
			}
		}
	}
	else 
	{
		if ((currentÑolumn == whichÑolumn + 1) || (currentÑolumn == whichÑolumn - 1))
		{
			if (GetColorChessPiece() == 'W')
			{
				if (whichLine == currentLine + 1)
				{
					return true;
				}
			}
			else 
			{
				if (whichLine == currentLine - 1)
				{
					return true;
				}
			}
		}
	}
	return false;
}

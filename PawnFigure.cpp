#include "PawnFigure.hpp"

char PawnFigure::GetChessPiece()
{
	return "";
}

bool PawnFigure::CorrectChessMove(int currentLine, int current�olumn, int whichLine, int which�olumn, ChessPiece* GameBoard[8][8])
{
	//��������� �� ����� ���� ����� ������
	ChessPiece* pFigureMove = GameBoard[whichLine][which�olumn];
	if (pFigureMove == 0)
	{
		if (current�olumn == which�olumn)
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
		if ((current�olumn == which�olumn + 1) || (current�olumn == which�olumn - 1))
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

#include "ChessPiece.hpp"

bool ChessPiece::CorrentMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8])
{
	ChessPiece* pFigureMove = GameBoard[whichLine][which—olumn];
	if (pFigureMove == 0 || colorChessPiece != pFigureMove->GetColorChessPiece())
	{
		return CorrectChessMove(currentLine, current—olumn, whichLine, which—olumn, GameBoard);
	}
	else
	{
		return false;
	}
}

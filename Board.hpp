#ifndef _BOARD_HPP_
#define _BOARD_HPP_

#include "ChessPiece.hpp"
#include "PawnFigure.hpp"
#include "RookFigure.hpp"
#include "HorseFigure.hpp"
#include "QueenFigure.hpp"
#include "KingFigure.hpp"
#include "ElephantFigure.hpp"

class Board
{
public:
	Board();
	~Board();

	void PrintBoard();
	bool DangerToTheKing(char colorChessPiece);

protected:
	ChessPiece* MainGameBoard[8][8];
};

#endif // ! _BOARD_HPP_
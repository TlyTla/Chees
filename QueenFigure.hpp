#ifndef _QUEEN_FIGURE_HPP_
#define _QUEEN_FIGURE_HPP_
#include "ChessPiece.hpp"

class QueenFigure : public ChessPiece
{
public:
	QueenFigure(char colorChessPiece) : ChessPiece(colorChessPiece) {}
	~QueenFigure() {}
private:
	char GetChessPiece() override;
	bool CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8]) override;
};

#endif // ! _QUEEN_FIGURE_HPP_
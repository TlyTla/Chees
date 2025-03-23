#ifndef _KING_FIGURE_HPP_
#define _KING_FIGURE_HPP_
#include "ChessPiece.hpp"

class KingFigure : public ChessPiece
{
public:
	KingFigure(char colorChessPiece) : ChessPiece(colorChessPiece) {}
	~KingFigure() {}

private:
	char GetChessPiece() override;
	bool CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8]) override;

};

#endif // ! _KING_FIGURE_HPP_
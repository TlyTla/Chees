#ifndef _PAWN_FIGURE_HPP_
#define _PAWN_FIGURE_HPP_
#include "ChessPiece.hpp"
class PawnFigure : public ChessPiece
{
public:
	PawnFigure(char colorChessPiece) : ChessPiece(colorChessPiece) {}
	~PawnFigure() {}
private:
	char GetChessPiece() override;
	bool CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8]) override;

};

#endif // ! _PAWN_FIGURE_HPP_
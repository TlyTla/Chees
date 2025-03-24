#ifndef _HORSE_FIGURE_HPP_
#define _HORSE_FIGURE_HPP_
#include "ChessPiece.hpp"

class HorseFigure : public ChessPiece
{
public:
	HorseFigure(char colorChessPiece) : ChessPiece(colorChessPiece) {}
	~HorseFigure() {}
private:
	char GetChessPiece() override;
	bool CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8]) override;
};

#endif // ! _HORSE_FIGURE_HPP_
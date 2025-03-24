#ifndef _ELEPHANT_FIGURE_HPP_
#define _ELEPHANT_FIGURE_HPP_
#include "ChessPiece.hpp"

class ElephantFigure : public ChessPiece
{
public:
	ElephantFigure(char colorChessPiece) : ChessPiece(colorChessPiece) {}
	~ElephantFigure() {}
private:
	char GetChessPiece() override;
	bool CorrectChessMove(int currentLine, int current—olumn, int whichLine, int which—olumn, ChessPiece* GameBoard[8][8]) override;
};

#endif // ! _ELEPHANT_FIGURE_HPP_
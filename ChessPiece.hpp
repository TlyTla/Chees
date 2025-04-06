#ifndef _CHESS_PIECE_HPP_
#define _CHESS_PIECE_HPP_

#include<iostream>

// клас щахматных фигур от которого наследуются сами фигуры
class ChessPiece
{
public:
	ChessPiece(char colorChessPiece) : colorChessPiece(colorChessPiece) {}
	~ChessPiece() {}

	//гетер - по факту выводит букву фигуры поэтому виртуальный
	virtual char GetChessPiece() = 0;
	char GetColorChessPiece() { return colorChessPiece; }

	//метод проверяет можно ли сходить в данную клетку
	bool CorrentMove(int currentLine, int currentСolumn, int whichLine, int whichСolumn, ChessPiece* GameBoard[8][8]);

private:
	char colorChessPiece;

	//метод проверку на ход конкретной фигуры
	virtual bool CorrectChessMove(int currentLine, int currentСolumn, int whichLine, int whichСolumn, ChessPiece* GameBoard[8][8]) = 0;

};

#endif // ! _CHESS_PIECE_HPP_
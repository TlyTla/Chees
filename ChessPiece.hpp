#ifndef _CHESS_PIECE_HPP_
#define _CHESS_PIECE_HPP_

#include<iostream>

//класс шахмотной фигуры
class ChessPiece
{
public:
	ChessPiece(char colorChessPiece) : colorChessPiece(colorChessPiece) {}
	~ChessPiece() {}

	virtual char GetChessPiece() = 0;
	char GetColorChessPiece() { return colorChessPiece; }

	//функция проверяет можно ли сходить в данную клетку
	bool CorrentMove(int currentLine, int currentСolumn, int whichLine, int whichСolumn, ChessPiece* GameBoard[8][8]);

private:
	char colorChessPiece;

	//функция делает ход конкретной 
	virtual bool CorrectChessMove(int currentLine, int currentСolumn, int whichLine, int whichСolumn, ChessPiece* GameBoard[8][8]) = 0;

};

#endif // ! _CHESS_PIECE_HPP_
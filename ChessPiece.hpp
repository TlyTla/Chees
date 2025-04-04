#ifndef _CHESS_PIECE_HPP_
#define _CHESS_PIECE_HPP_

#include<iostream>

//����� ��������� ������
class ChessPiece
{
public:
	ChessPiece(char colorChessPiece) : colorChessPiece(colorChessPiece) {}
	~ChessPiece() {}

	virtual char GetChessPiece() = 0;
	char GetColorChessPiece() { return colorChessPiece; }

	//������� ��������� ����� �� ������� � ������ ������
	bool CorrentMove(int currentLine, int current�olumn, int whichLine, int which�olumn, ChessPiece* GameBoard[8][8]);

private:
	char colorChessPiece;

	//������� ������ ��� ���������� 
	virtual bool CorrectChessMove(int currentLine, int current�olumn, int whichLine, int which�olumn, ChessPiece* GameBoard[8][8]) = 0;

};

#endif // ! _CHESS_PIECE_HPP_
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
	//в конструкторе добавляем где находятся белые и черные фигуры
	Board();
	~Board();

	//метод рисует доску и ставит фигуры
	void PrintBoard();
	//метод проверяет находится ли в шахе и мате король
	bool DangerToTheKing(char colorChessPiece);
	//проверяет может ли игрок сделать какой нибуть правильный ход
	bool MovePlayer(char colorChessPiece);

protected:
	//доска и все
	ChessPiece* MainGameBoard[8][8];

	friend class StartGame;
};

#endif // ! _BOARD_HPP_
#ifndef _START_GAME_HPP_
#define _START_GAME_HPP_
#include"Board.hpp"
#include<string>

//по факту игровой цикл
class StartGame
{
public:
	StartGame() : player('W') {}
	~StartGame() {}

	void Start();
	//метод свапа игрока
	void NextPlayer();
	//метод который завершает игру если шах и мат
	bool GameOver();
	//метод который выводит правила, доску с метода другого класса и спрашивает ход игрока
	void PrintBoardAndDesignations(ChessPiece* GameBoard[8][8]);

private:
	// ну типа черный игрок или белый
	char player;
	// обьект доски
	Board GameBoard;
};

#endif // ! _START_GAME_HPP_
#ifndef _START_GAME_HPP_
#define _START_GAME_HPP_
#include"Board.hpp"
#include<string>

class StartGame
{
public:
	StartGame() : player('W') {}
	~StartGame() {}

	void Start();
	void NextPlayer();
	bool GameOver();
	void PrintBoardAndDesignations(ChessPiece* GameBoard[8][8]);

private:
	char player;
	Board GameBoard;
};

#endif // ! _START_GAME_HPP_
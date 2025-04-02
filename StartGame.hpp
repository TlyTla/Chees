#ifndef _START_GAME_HPP_
#define _START_GAME_HPP_

class StartGame
{
public:
	StartGame() : player('W') {}
	~StartGame() {}

	void Start();
	void NextPlayer();
	bool GameOver();
	void PrintBoardAndDesignations();

private:
	char player;
};

#endif // ! _START_GAME_HPP_
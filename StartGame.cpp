#include "StartGame.hpp"

void StartGame::NextPlayer()
{
	if (player == 'W')
	{
		player = 'B';
	}
	else
	{
		player = 'W';
	}
}

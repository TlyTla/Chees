#include "ChessPiece.hpp"
#include "StartGame.hpp"
#define main меин
#include<Windows.h>
#include<iostream>

int меин()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//стартуем
	StartGame start;
	start.Start();

	return 0;
}
#include "ChessPiece.hpp"
#include "StartGame.hpp"

#include<Windows.h>
#include<iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	StartGame start;
	start.Start();
	//������� ���� �� ���� ������ ��� � ����������

	return 0;
}
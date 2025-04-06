#include "StartGame.hpp"

void StartGame::Start()
{
	do 
	{
		PrintBoardAndDesignations(GameBoard.MainGameBoard);
		NextPlayer();
	} while (!GameOver());
	GameBoard.PrintBoard();
}

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

bool StartGame::GameOver()
{
	bool possibleMove(false);

	possibleMove = GameBoard.MovePlayer(player);

	if (!possibleMove) 
	{
		if (GameBoard.DangerToTheKing(player)) 
		{
			NextPlayer();
			std::cout << "��� � ���, " << player << " ������� ������!!!!!" << std::endl;
		}
		else 
		{
			std::cout << "������ ��� �����!" << std::endl;
		}
	}
	return !possibleMove;
}

void StartGame::PrintBoardAndDesignations(ChessPiece* GameBoard[8][8])
{
    bool bValidMove = false;

    std::cout << "1 - �������\n2 - ������"<<std::endl;
    std::string number;
    std::getline(std::cin, number);
    do 
    {
        if (number == "1")
        {
            std::cout << "W - ����� �����"<<std::endl;
            std::cout << "B - ������ �����" << std::endl;
            std::cout << "K - ������" << std::endl;
            std::cout << "Q - ��������" << std::endl;
            std::cout << "P - �����" << std::endl;
            std::cout << "R - �����" << std::endl;
            std::cout << "H - ����" << std::endl;
            std::cout << "E - ����" << std::endl;
            std::cout << "��������� ������� ������ ����� ����� ������" << std::endl << std::endl << std::endl;
            number = "2";
            system("pause");
        }
        else 
        {
            system("cls");
            this->GameBoard.PrintBoard();

            int startMove, endMove;

            std::cout << player << " - ���.\n��� �����: ";
            std::cin >> startMove;

            int startLine = (startMove / 10) - 1, startCol = (startMove % 10) - 1;

            std::cout << "���� �����: ";
            std::cin >> endMove;

            int endLine = (endMove / 10) - 1, endCol = (endMove % 10) - 1;


            if ((startLine >= 0 && startLine <= 7) && (startCol >= 0 && startCol <= 7)
                && (endLine >= 0 && endLine <= 7) && (endCol >= 0 && endCol <= 7))
            {


                ChessPiece* qpCurrPiece = GameBoard[startLine][startCol];


                if ((qpCurrPiece != 0) && (qpCurrPiece->GetColorChessPiece() == player))
                {


                    if (qpCurrPiece->CorrentMove(startLine, startCol, endLine, endCol, GameBoard))
                    {


                        ChessPiece* pFigureMove = GameBoard[endLine][endCol];
                        GameBoard[endLine][endCol] = GameBoard[startLine][startCol];
                        GameBoard[startLine][startCol] = 0;

                        if (!this->GameBoard.DangerToTheKing(player))
                        {
                            delete pFigureMove;
                            bValidMove = true;
                        }
                        else
                        {
                            GameBoard[startLine][startCol] = GameBoard[endLine][endCol];
                            GameBoard[endLine][endCol] = pFigureMove;
                        }
                    }
                }
            }
            if (!bValidMove)
            {
                std::cout << "������������ ���!" << std::endl;
            }
        }
     
    } while (!bValidMove);
}

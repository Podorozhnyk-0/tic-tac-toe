#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "Player.h"
#include "Utils.h"

using namespace std;



int main()
{
	srand(time(NULL));

	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Ru");

	Field field = Field();

	bool playVsAi = false;
	PlayerTeam player1Team, player2Team;
	int currentMove;

	char answer;
	do
	{
		answer = AskInput<char>("Do you want to play with a player or with an AI? (y/n)", "Error! Invalid data entered");

		if (answer != 'y' && answer != 'n')
		{
			cout << "Error! Invalid data entered!" << endl;
		}
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y') playVsAi = true;

	do
	{
		player1Team = (PlayerTeam)AskInput<int>("Cross or Zero? (1/2)", "Error! Invalid data entered");

		if (player1Team != PlayerTeam::CROSS_TEAM && player1Team != PlayerTeam::ZERO_TEAM)
		{
			cout << "Error! Invalid data entered!" << endl;
		}
	} while (player1Team != PlayerTeam::CROSS_TEAM && player1Team != PlayerTeam::ZERO_TEAM);

	player2Team = GetOppositeTeam(player1Team);

	Player player1 = Player(false, 0, player1Team, field);
	Player player2 = Player(playVsAi, 1, player2Team, field);

	if (player1.GetPlayerTeam() == PlayerTeam::CROSS_TEAM) currentMove = player1.GetId();
	else currentMove = player2.GetId();

	while (field.CheckWinner() == PlayerTeam::NONE) //игровой цикл
	{
		field.PrintField();
		if (currentMove == player1.GetId())
		{
			cout << "PLAYER 1'S MOVE" << endl;
			player1.Move();
			currentMove = player2.GetId();
		}
		else if (currentMove == player2.GetId())
		{
			cout << "PLAYER 2'S MOVE" << endl;
			player2.Move();
			currentMove = player1.GetId();
		}
		system("cls");
	}
	field.PrintField();
	if (field.CheckWinner() == player1.GetPlayerTeam())
	{
		cout << "PLAYER 1 WON!" << endl;
	}
	else if (field.CheckWinner() == player2.GetPlayerTeam())
	{
		if (player1.IsAI())
		{
			cout << "PLAYER 2 (AI) WON!" << endl;
		}
		else
		{
			cout << "PLAYER 2 (PLAYER) WON!" << endl;
		}
	}
	else
	{
		cout << "TIE!" << endl;
	}
	return 0;
}


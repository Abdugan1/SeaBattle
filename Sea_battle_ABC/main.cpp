#include <iostream>
#include <ctime>
#include "Gamefield.h"
#include "PlayerHuman.h"
#include "PlayerBot.h"

int main() {
	using namespace std;
	srand(time(0));
	Gamefield gf;
	PlayerHuman player1, player2;
	PlayerBot bot;

	char choice = '0';
	do {
		system("cls");
		cout << "1. Player vs Bot\n";
		cout << "2. Player vs Player\n";
		cout << ">";
		cin >> choice;
	} while (choice != '1' && choice != '2');

	switch (choice)
	{
	case '1':
		gf.SetPlayers(player1, bot);
		Gamefield::isPlayerVsBot(true);
		break;
	case '2':
		gf.SetPlayers(player1, player2);
		Gamefield::isPlayerVsBot(false);
		break;
	}

	while (!gf.GameOver())
	{
		gf.Draw();
	}

	system("pause");
	return 0;
}
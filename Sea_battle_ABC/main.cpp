#include <iostream>
#include <ctime>
#include "Gamefield.h"
#include "PlayerHuman.h"

int main() {
	using namespace std;
	srand(time(0));
	PlayerHuman player1, player2;
	Gamefield gf(player1, player2);
	while (true)
	{
		gf.Draw();
	}



	return 0;
}
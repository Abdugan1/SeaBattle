#pragma once
#include "Board.h"
#include "Player.h"
class Gamefield
{
private:
	Board _board1, _board2;
	Ship _ships1[_SHIP_COUNT], _ships2[_SHIP_COUNT];
	Player* _player1;
	Player* _player2;
	int _turn;
	void GenerateShips();
	void Player1View();
	void Player2View();
	void ShowWhoWon();
public:
	Gamefield();
	void Draw();
	Gamefield(Player& player1, Player& player2);
	bool GameOver();
};


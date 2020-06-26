#pragma once
#include "Board.h"
#include "Ship.h"
class Player
{
private:
	Board* _board;
	Ship _ships[_SHIP_COUNT];
	void AssignBoard(Board& board);
	void SetShipsToBoard();
protected:
public:
	Player(Board& board, Ship* ships);
	virtual ~Player() {};
	virtual bool Attack() = 0;
};


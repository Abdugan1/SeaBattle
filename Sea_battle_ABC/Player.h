#pragma once
#include "Board.h"
#include "Ship.h"
class Player
{
private:
	Board* _board;
	Ship _ships[_SHIP_COUNT];
protected:
public:
	void AssignBoard(Board& board);
	void SetShipsToBoard(Ship* ships);
	Player() {};
	virtual ~Player() {};
	virtual bool Attack() = 0;
};


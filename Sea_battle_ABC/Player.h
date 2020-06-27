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
	bool isntCorrectAttack(const Position& hit_pos);
	bool ProjectileHit(const Position& hit_pos);
	void ProcessHit(const Position& hit_pos);
	bool isHaveShips();
	void AssignBoard(Board& board);
	void SetShipsToBoard(Ship* ships);
	Player() {};
	virtual ~Player() {};
	virtual bool Attack(Player& player) = 0;
};


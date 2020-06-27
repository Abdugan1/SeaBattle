#pragma once
#include <iostream>
#include <string>
#include "Constants.h"
#include "Ship.h"
class Board
{
private:
	char _field[HEIGHT][WIDTH];
	bool isFreePlace(Ship& s);
	void FillEmptyPlaces();
public:
	Board();
	void SetShips(Ship* ships);
	bool ProcessAttack(const Position& hit_pos);
	bool isntCorrectAttack(const Position& hit_pos);
	void DrawVisible();
	void DrawInvisible();
	void DrawBorders(const Ship& s);
};


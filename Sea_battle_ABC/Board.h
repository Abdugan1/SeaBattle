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
	void DrawVisible();
	void DrawInvisible();
};


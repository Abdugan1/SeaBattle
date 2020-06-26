#pragma once
#include "Constants.h"
#include "Ship.h"
class Board
{
private:
	char _field[HEIGHT][WIDTH];
	bool isFreePlace(Ship& s);
public:
	void SetShips(Ship* ships);
};


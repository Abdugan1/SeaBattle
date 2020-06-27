#include "Gamefield.h"

void Gamefield::GenerateShips()
{
	int j = 0;
	for (size_t i = 0; i < FOUR_DECK_COUNT; i++) {
		_ships1[j] = Ship(FOUR_DECK_LENGTH);
		_ships2[j] = Ship(FOUR_DECK_LENGTH);
		j++;
	}

	for (size_t i = 0; i < THREE_DECK_COUNT; i++) {
		_ships1[j] = Ship(THREE_DECK_LENGTH);
		_ships2[j] = Ship(THREE_DECK_LENGTH);
		j++;
	}

	for (size_t i = 0; i < TWO_DECK_COUNT; i++) {
		_ships1[j] = Ship(TWO_DECK_LENGTH);
		_ships2[j] = Ship(TWO_DECK_LENGTH);
		j++;
	}

	for (size_t i = 0; i < ONE_DECK_COUNT; i++) {
		_ships1[j] = Ship(ONE_DECK_LENGTH);
		_ships2[j] = Ship(ONE_DECK_LENGTH);
		j++;
	}
}

Gamefield::Gamefield()
{
	GenerateShips();
}

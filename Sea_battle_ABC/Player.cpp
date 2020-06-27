#include "Player.h"

void Player::AssignBoard(Board& board)
{
	_board = &board;
}

void Player::SetShipsToBoard(Ship* ships)
{
	for (size_t i = 0; i < _SHIP_COUNT; i++)
		_ships[i] = ships[i];
	_board->SetShips(_ships);
}

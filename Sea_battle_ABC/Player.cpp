#include "Player.h"

bool Player::isntCorrectAttack(const Position& hit_pos)
{
	return _board->isntCorrectAttack(hit_pos);
}

bool Player::ProjectileHit(const Position& hit_pos)
{
	return _board->ProcessAttack(hit_pos);
}

void Player::ProcessHit(const Position& hit_pos)
{
	for (int i = 0; i < _SHIP_COUNT; i++)
	{
		for (int j = 0; j < _ships[i].GetLength(); j++)
		{
			if (_ships[i].GetPosY(j) == hit_pos.y && _ships[i].GetPosX(j) == hit_pos.x)
			{
				_ships[i].HurtDeck();
				if (_ships[i].GetHealth() <= 0)
				{
					_board->DrawBorders(_ships[i]);
				}
				return;
			}
		}
	}
}

bool Player::isHaveShips()
{
	int intact_ships = 0;
	for (int i = 0; i < _SHIP_COUNT; i++)
	{
		if (_ships[i].GetHealth() != 0)
		{
			intact_ships++;
		}
	}
	return bool(intact_ships);
}

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

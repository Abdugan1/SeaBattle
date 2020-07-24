#include "PlayerBot.h"

void PlayerBot::SwitchAttackDir()
{
	switch (_attack_dir)
	{
	case PlayerBot::UP:
		_attack_dir = PlayerBot::DOWN;
		break;
	case PlayerBot::DOWN:
		_attack_dir = PlayerBot::LEFT;
		break;
	case PlayerBot::LEFT:
		_attack_dir = PlayerBot::RIGHT;
		break;
	case PlayerBot::RIGHT:
		_attack_dir = PlayerBot::UP;
		break;
	}
}

void PlayerBot::ChangeHitPos(Position& hit_pos)
{
	switch (_attack_dir)
	{
	case PlayerBot::UP:
		hit_pos.y--;
		break;
	case PlayerBot::DOWN:
		hit_pos.y++;
		break;
	case PlayerBot::LEFT:
		hit_pos.x--;
		break;
	case PlayerBot::RIGHT:
		hit_pos.x++;
		break;
	}
}

PlayerBot::PlayerBot() :
	Player()
{
	_attack_dir = AttackDir(rand() % 4);
	_hit = false;
}

bool PlayerBot::Attack(Player& enemy_player)
{
    static Position hit_pos;
	clock_t delay = rand() % 1000 + 400;
	clock_t start;
	if (!_hit)
	{
		do {
			start = clock();
			hit_pos.x = rand() % WIDTH;
			hit_pos.y = rand() % HEIGHT;
			while (clock() - start < delay);
		} while (enemy_player.isntCorrectAttack(hit_pos));
	}

	if (enemy_player.ProjectileHit(hit_pos))
	{
		_hit = true;
		enemy_player.ProcessHit(hit_pos);
		ChangeHitPos(hit_pos);
		return true;
	}
	else if (true)
	{

	}
	else
	{
		SwitchAttackDir();
		return false;
	}
}

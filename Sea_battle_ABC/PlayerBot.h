#pragma once
#include <ctime>
#include "Player.h"
class PlayerBot :
    public Player
{
private:
	enum AttackDir {
		UP, DOWN, LEFT, RIGHT
	} _attack_dir;
	bool _hit;
	void SwitchAttackDir();
	void ChangeHitPos(Position& hit_pos);
public:
	PlayerBot();
    virtual bool Attack(Player& enemy_player);
};


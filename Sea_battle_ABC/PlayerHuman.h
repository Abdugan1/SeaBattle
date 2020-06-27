#pragma once
#include "Player.h"
class PlayerHuman :
    public Player
{
public:
    virtual bool Attack(Player& enemy_player);
};


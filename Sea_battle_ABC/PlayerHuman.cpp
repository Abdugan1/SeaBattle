#include "PlayerHuman.h"

bool PlayerHuman::Attack(Player& enemy_player)
{
	if (!enemy_player.isHaveShips())
	{
		return false;
	}
	Position hit_pos;
	do {
		int y; char x;
		std::cout << "Enter coord: ";
		std::cin >> y;
		while (!std::cin)
		{
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Wrong coor!\nEnter coord: ";
			std::cin >> y;
		}
		std::cin >> x;
		hit_pos.x = toupper(x) - 'A';
		hit_pos.y = y - 1;
	} while (enemy_player.isntCorrectAttack(hit_pos));

	if (enemy_player.ProjectileHit(hit_pos))
	{
		enemy_player.ProcessHit(hit_pos);
		return true;
	}
	else
	{
		return false;
	}
}

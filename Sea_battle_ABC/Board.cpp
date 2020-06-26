#include "Board.h"

bool Board::isFreePlace(Ship& s)
{
	for (int i = 0; i < s.GetLength(); i++)
	{
		if (_field[s.GetPosY(i)][s.GetPosX(i)] == 'd' || _field[s.GetPosY(i)][s.GetPosX(i)] == '|')
		{
			s.GetNewPos();
			return false;
		}
	}
	return true;
}

void Board::SetShips(Ship* ships)
{
	for (int i = 0; i < _SHIP_COUNT; )
	{
		while (!isFreePlace(ships[i]))
			continue;
		for (int j = 0; j < ships[i].GetLength(); j++)
		{
			_field[ships[i].GetPosY(j)][ships[i].GetPosX(j)] = 'd';
			//draw_visible();
			//system("cls");
		}
		for (int j = 0; j < ships[i].GetBordersCount(); j++)
		{
			_field[ships[i].GetBorderPosY(j)][ships[i].GetBorderPosX(j)] = '|';
			//draw_visible();
			//system("cls");
		}
		i++;
	}
	//init(); <- нужное
}

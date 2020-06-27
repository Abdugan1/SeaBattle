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

void Board::FillEmptyPlaces()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (_field[i][j] != 'd' && _field[i][j] != 'x')
			{
				_field[i][j] = '.';
			}
		}
	}
}

Board::Board()
{

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
			//DrawVisible();
			//system("cls");
		}
		for (int j = 0; j < ships[i].GetBordersCount(); j++)
		{
			_field[ships[i].GetBorderPosY(j)][ships[i].GetBorderPosX(j)] = '|';
			//DrawVisible();
			//system("cls");
		}
		i++;
	}
	FillEmptyPlaces();
}

bool Board::ProcessAttack(const Position& hit_pos)
{
	if (_field[hit_pos.y][hit_pos.x] == 'd')
	{
		_field[hit_pos.y][hit_pos.x] = 'x';
		return true;
	}
	else 
	{
		_field[hit_pos.y][hit_pos.x] = '/';
		return false;
	}
}

bool Board::isntCorrectAttack(const Position& hit_pos)
{
	if ((hit_pos.x < 0 || hit_pos.x >= WIDTH) || (hit_pos.y < 0 || hit_pos.y >= HEIGHT))
	{
		std::cout << "Wrong coord!\nEnter coord: ";
		while (std::cin.get() != '\n')
			continue;
		return true;
	}
	else if (_field[hit_pos.y][hit_pos.x] == 'x' || _field[hit_pos.y][hit_pos.x] == '/')
	{
		std::cout << "You've already fired there\nEnter coord: ";
		return true;
	}
	return false;
}

void Board::DrawVisible()
{
	using std::cout; using std::endl;
	std::string str_board;
	char ch = 'A';
	str_board += "    ";
	for (int i = 0; i < WIDTH; i++)
	{
		str_board += ch;
		str_board += "  ";
		ch++;
	}
	str_board += '\n';
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
				str_board += (i < 9 ? " " : "") + std::to_string(i + 1) + "  ";
			str_board += _field[i][j];
			str_board += "  ";
		}
		str_board += '\n';
	}
	std::cout << str_board;
}

void Board::DrawInvisible()
{
	std::string str_board;
	using std::cout; using std::endl;
	char ch = 'A';
	str_board += "    ";
	for (int i = 0; i < WIDTH; i++)
	{
		str_board += ch;
		str_board += "  ";
		ch++;
	}
	str_board += '\n';
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
				str_board += (i < 9 ? " " : "") + std::to_string(i + 1) + "  ";
			if (_field[i][j] != 'x' && _field[i][j] != '/')
			{
				str_board += ".  ";
			}
			else
			{
				str_board += _field[i][j];
				str_board += "  ";
			}
		}
		str_board += '\n';
	}
	std::cout << str_board;
}

void Board::DrawBorders(const Ship& s)
{
	for (int j = 0; j < s.GetBordersCount(); j++)
	{
		_field[s.GetBorderPosY(j)][s.GetBorderPosX(j)] = '/';
	}
}

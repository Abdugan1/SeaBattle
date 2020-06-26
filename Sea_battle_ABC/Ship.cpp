#include "Ship.h"

bool Ship::isHorizontal()
{
	if (_dir == LEFT || _dir == RIGHT)
		return true;
	return false;
}

void Ship::GetNewPos()
{
	_dir = Direction(rand() % 4);
	_pos[0].x = rand() % WIDTH;
	_pos[0].y = rand() % HEIGHT;
	_borders_pos.clear();
	if (isHorizontal())
	{
		if (_pos[0].x + _length > WIDTH)
		{
			_dir = LEFT;
			for (int i = 1; i < _length; i++)
			{
				_pos[i].x = _pos[0].x - i;
				_pos[i].y = _pos[0].y;
			}
		}
		else
		{
			_dir = RIGHT;
			for (int i = 1; i < _length; i++)
			{
				_pos[i].x = _pos[0].x + i;
				_pos[i].y = _pos[0].y;
			}
		}
	}
	else
	{
		if (_pos[0].y + _length > HEIGHT)
		{
			_dir = UP;
			for (int i = 1; i < _length; i++)
			{
				_pos[i].x = _pos[0].x;
				_pos[i].y = _pos[0].y - i;
			}
		}
		else
		{
			_dir = DOWN;
			for (int i = 1; i < _length; i++)
			{
				_pos[i].x = _pos[0].x;
				_pos[i].y = _pos[0].y + i;
			}
		}
	}
	make_borders();
}

std::vector<Position> Ship::make_upper_borders()
{
	if (_pos[0].y <= 0)
	{
		return std::vector<Position>();
	}
	std::vector<Position> upper_borders;
	Position tmp_pos;
	if (isHorizontal())
	{//ad
		tmp_pos.y = _pos[0].y - 1;
		for (int i = 0; i < _length; i++)
		{
			tmp_pos.x = _pos[i].x;
			upper_borders.push_back(tmp_pos);
		}
	}
	else
	{//ad
		if (_dir == UP)
		{
			tmp_pos.y = _pos[_length - 1].y - 1;
		}
		else if (_dir == DOWN)
		{
			tmp_pos.y = _pos[0].y - 1;
		}

		for (int i = 0; i < 3; i++)
		{
			tmp_pos.x = _pos[0].x - 1 + i;
			if (tmp_pos.x >= 0 && tmp_pos.x <= WIDTH - 1)
			{
				upper_borders.push_back(tmp_pos);
			}
		}
	}
	return upper_borders;
}

std::vector<Position> Ship::make_left_borders()
{
	if (_pos[0].x <= 0)
	{
		return std::vector<Position>();
	}
	std::vector<Position> left_borders;
	Position tmp_pos;
	if (isHorizontal())
	{//ad
		if (_dir == LEFT)
		{
			tmp_pos.x = _pos[_length - 1].x - 1;
		}
		else if (_dir == RIGHT)
		{
			tmp_pos.x = _pos[0].x - 1;
		}
		for (int i = 0; i < 3; i++)
		{
			tmp_pos.y = _pos[0].y - 1 + i;
			if (tmp_pos.y >= 0 && tmp_pos.y <= WIDTH - 1)
			{
				left_borders.push_back(tmp_pos);
			}
		}
	}
	else
	{//ad
		tmp_pos.x = _pos[0].x - 1;
		for (int i = 0; i < _length; i++)
		{
			tmp_pos.y = _pos[i].y;
			left_borders.push_back(tmp_pos);
		}
	}
	return left_borders;
}

std::vector<Position> Ship::make_right_borders()
{
	if (_pos[_length - 1].x >= WIDTH - 1 || _pos[0].x >= WIDTH - 1)
	{
		return std::vector<Position>();
	}
	std::vector<Position> right_borders;
	Position tmp_pos;
	if (isHorizontal())
	{//ad
		if (_dir == LEFT)
		{
			tmp_pos.x = _pos[0].x + 1;
		}
		else if (_dir == RIGHT)
		{
			tmp_pos.x = _pos[_length - 1].x + 1;
		}
		for (int i = 0; i < 3; i++)
		{
			tmp_pos.y = _pos[0].y - 1 + i;
			if (tmp_pos.y >= 0 && tmp_pos.y <= WIDTH - 1)
			{
				right_borders.push_back(tmp_pos);
			}
		}
	}
	else
	{//ad
		tmp_pos.x = _pos[0].x + 1;
		for (int i = 0; i < _length; i++)
		{
			tmp_pos.y = _pos[i].y;
			right_borders.push_back(tmp_pos);
		}
	}
	return right_borders;
}

std::vector<Position> Ship::make_bottom_borders()
{
	if (_pos[_length - 1].y >= HEIGHT - 1 || _pos[0].y >= HEIGHT - 1)
	{
		return std::vector<Position>();
	}
	std::vector<Position> bottom_borders;
	Position tmp_pos;
	if (isHorizontal())
	{//ad
		tmp_pos.y = _pos[0].y + 1;
		for (int i = 0; i < _length; i++)
		{
			tmp_pos.x = _pos[i].x;
			bottom_borders.push_back(tmp_pos);
		}
	}
	else
	{
		if (_dir == UP)
		{
			tmp_pos.y = _pos[0].y + 1;
		}
		else if (_dir == DOWN)
		{
			tmp_pos.y = _pos[_length - 1].y + 1;
		}
		for (int i = 0; i < 3; i++)
		{
			tmp_pos.x = _pos[0].x - 1 + i;
			if (tmp_pos.x >= 0 && tmp_pos.x <= WIDTH - 1)
			{
				bottom_borders.push_back(tmp_pos);
			}
		}
	}
	return bottom_borders;
}

void Ship::make_borders()
{
	std::vector<Position> upper_borders = make_upper_borders();
	std::vector<Position> left_borders = make_left_borders();
	std::vector<Position> right_borders = make_right_borders();
	std::vector<Position> bottom_borders = make_bottom_borders();

	_borders_pos.insert(_borders_pos.end(), upper_borders.begin(), upper_borders.end());
	_borders_pos.insert(_borders_pos.end(), left_borders.begin(), left_borders.end());
	_borders_pos.insert(_borders_pos.end(), right_borders.begin(), right_borders.end());
	_borders_pos.insert(_borders_pos.end(), bottom_borders.begin(), bottom_borders.end());
}

Ship::Ship()
{
	_length = 0;
	_health = 0;
	_pos = nullptr;
}

Ship::Ship(int length)
{
	_length = length;
	_health = _length;
	GetNewPos();
}

Ship::Ship(const Ship& s)
{
	_length = s._length;
	_health = s._health;
	_dir = s._dir;
	delete[] _pos;
	for (int i = 0; i < _length; i++)
		_pos[i] = s._pos[i];
	_borders_pos = s._borders_pos;
}

Ship::~Ship()
{
	delete[] _pos;
}

Ship& Ship::operator=(const Ship& s)
{
	if (this == &s)
	{
		return *this;
	}
	_length = s._length;
	_health = s._health;
	_dir = s._dir;
	delete[] _pos;
	for (int i = 0; i < _length; i++)
		_pos[i] = s._pos[i];
	_borders_pos = s._borders_pos;
	return *this;// TODO: вставьте здесь оператор return
}

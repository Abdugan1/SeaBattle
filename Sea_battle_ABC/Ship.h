#pragma once
#include <vector>
#include "Constants.h"
class Ship
{
private:
	enum Direction {
		UP, DOWN, LEFT, RIGHT
	} _dir;
	Position* _pos;
	std::vector<Position> _borders_pos;
	int _length;
	int _health;

	bool isHorizontal();

	std::vector<Position> make_upper_borders();
	std::vector<Position> make_left_borders();
	std::vector<Position> make_right_borders();
	std::vector<Position> make_bottom_borders();
	void make_borders();
public:
	Ship();
	Ship(int length);
	Ship(const Ship& s);
	~Ship();
	Ship& operator=(const Ship& s);

	void GetNewPos();
	int GetHealth() const { return _health; };
	int GetLength() const { return _length; };
	void HurtDeck();
	int GetPosX(int i) const { return _pos[i].x; };
	int GetPosY(int i) const { return _pos[i].y; };
	int GetBorderPosX(int i) const { return _borders_pos[i].x; };
	int GetBorderPosY(int i) const { return _borders_pos[i].y; };
	int GetBordersCount() const { return _borders_pos.size(); };
};


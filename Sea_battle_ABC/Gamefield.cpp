#include "Gamefield.h"

void Gamefield::GenerateShips()
{
	int j = 0;
	for (size_t i = 0; i < FOUR_DECK_COUNT; i++) {
		_ships1[j] = Ship(FOUR_DECK_LENGTH);
		_ships2[j] = Ship(FOUR_DECK_LENGTH);
		j++;
	}

	for (size_t i = 0; i < THREE_DECK_COUNT; i++) {
		_ships1[j] = Ship(THREE_DECK_LENGTH);
		_ships2[j] = Ship(THREE_DECK_LENGTH);
		j++;
	}

	for (size_t i = 0; i < TWO_DECK_COUNT; i++) {
		_ships1[j] = Ship(TWO_DECK_LENGTH);
		_ships2[j] = Ship(TWO_DECK_LENGTH);
		j++;
	}

	for (size_t i = 0; i < ONE_DECK_COUNT; i++) {
		_ships1[j] = Ship(ONE_DECK_LENGTH);
		_ships2[j] = Ship(ONE_DECK_LENGTH);
		j++;
	}
}

void Gamefield::Player1View()
{
	system("cls");
	std::cout << "Player1\n";
	_board1.DrawVisible();
	std::cout << std::endl;
	std::cout << "Player2\n";
	_board2.DrawInvisible();
}

void Gamefield::Player2View()
{
	system("cls");
	std::cout << "Player1\n";
	_board1.DrawInvisible();
	std::cout << std::endl;
	std::cout << "Player2\n";
	_board2.DrawVisible();
}

void Gamefield::ShowWhoWon()
{
	if (!_player1->isHaveShips())
	{
		std::cout << "Player2 Won!\n";
	}
	else
	{
		std::cout << "Player1 Won!\n";
	}
}

Gamefield::Gamefield()
{
	//GenerateShips();
}

void Gamefield::Draw()
{
	if (_turn == 0)
	{
		do {
			Player1View();
		} while (_player1->Attack(*_player2));

		do {
			Player2View();
		} while (_player2->Attack(*_player1));
	}
	else
	{
		do {
			Player2View();
		} while (_player2->Attack(*_player1));

		do {
			Player1View();
		} while (_player1->Attack(*_player2));
	}
}

Gamefield::Gamefield(Player& player1, Player& player2)
{
	GenerateShips();
	_turn = rand() % 2;
	_player1 = &player1;
	_player2 = &player2;
	_player1->AssignBoard(_board1);
	_player2->AssignBoard(_board2);
	_player1->SetShipsToBoard(_ships1);
	_player2->SetShipsToBoard(_ships2);
}

bool Gamefield::GameOver()
{
	if (!_player1->isHaveShips() || !_player2->isHaveShips())
	{
		system("cls");
		ShowWhoWon();
		return true;
	}
	return false;
}

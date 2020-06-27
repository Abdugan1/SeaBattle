#include "Player.h"

void Player::AssignBoard(Board& board)
{
	_board = &board;
}

void Player::SetShipsToBoard()
{
	_board->SetShips(_ships);
}

Player::Player(Board& board, Ship* ships)
{
	//int j = 0;
	//for (size_t i = 0; i < FOUR_DECK_COUNT; i++) {
	//	_ships[j++] = Ship(FOUR_DECK_LENGTH);
	//}

	//for (size_t i = 0; i < THREE_DECK_COUNT; i++) {
	//	_ships[j++] = Ship(THREE_DECK_LENGTH);
	//}

	//for (size_t i = 0; i < TWO_DECK_COUNT; i++) {
	//	_ships[j++] = Ship(TWO_DECK_LENGTH);
	//}

	//for (size_t i = 0; i < ONE_DECK_COUNT; i++) {
	//	_ships[j++] = Ship(ONE_DECK_LENGTH);
	//}
	AssignBoard(board);
	SetShipsToBoard();
}

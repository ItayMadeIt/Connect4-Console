#include "Board.hpp"



Board::Board()
{
	for (int i = 0; i < LENGTH; i++)
	{
		boards[i] = 0;
	}
}
Board::Board(const char* game)
{
	for (int i = 0; i < LENGTH; i++)
	{
		boards[i] = 0;
	}
	
	for (int i = 0; i < strlen(game); i++)
	{
		char move = game[i];

		playMove(this, move - '1');
	}
}

void Board::printBoard(Board board)
{
	for (signed char row = ROWS - 1; row >= 0; row--)
	{
		for (signed char col = 0; col < COLUMNS; col++)
		{
			printf("%c", isBitOn(board.boards[ALL], col, row) ?
				((isBitOn(board.boards[CURRENT], col, row) ^ board.isRed) ?
					RED_CHAR
					:
					BLUE_CHAR)
				:
				EMPTY_CHAR);
			
		}
		std::cout << "\n";
	}
}

void Board::playMove(Board* board, unsigned char move)
{
	// add to the board (OR) the top move using a nice trick for adding a move ontop 
	board->boards[ALL] |= board->boards[ALL] + (1ll << (move * ROWS));

	// switch board
	board->boards[CURRENT] ^= board->boards[ALL];

	// switch turn
	board->isRed = !board->isRed;
}

bool Board::isMoveLegal(Board board, unsigned char move)
{
	return (board.boards[ALL] & TOP_MASKS[move]) == 0;
}

void Board::printInt64(int64 value)
{
	for (signed char row = ROWS-1; row >= 0; row--)
	{
		for (signed char col = 0; col < COLUMNS; col++)
		{
			if (isBitOn(value, col, row))
			{
				std::cout << "1";
			}
			else
			{
				std::cout << "0";
			}
		}
		std::cout << "\n";
	}
}

bool Board::isBitOn(int64 value, signed char col, signed char row)
{
	return ((value & (1ll << (row + col * (ROWS)))) != 0);
}

bool Board::isBitOn(int64 value, unsigned char position)
{
	return ((value & (1ll << (position))) != 0);
}

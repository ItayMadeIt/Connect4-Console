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

		playMove(boards, isRed, move - '0');
	}
}

void Board::printBoard(int64 boards[LENGTH])
{
	for (signed char row = ROWS - 1; row >= 0; row--)
	{
		for (signed char col = 0; col < COLUMNS; col++)
		{
			if (isBitOn(boards[ALL], col, row))
			{
				printf("%c", isBitOn(boards[RED], col, row) ? 'O' : 'X');
			}
			else
			{
				printf(" ");
			}
		}
		std::cout << "\n";
	}
}

void Board::playMove(int64 boards[LENGTH], bool isRed, unsigned char move)
{
	//boards[RED] |= (boards[RED] & ROWS_ARR[move]);
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
	return ((value & (1ull << (row * (COLUMNS + 1) + col))) != 0);
}

bool Board::isBitOn(int64 value, unsigned char position)
{
	return ((value & (1ull << (position))) != 0);
}

#include "Board.hpp"

void Board::printBoard()
{
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

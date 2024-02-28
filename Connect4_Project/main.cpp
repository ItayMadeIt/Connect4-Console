#include <iostream>
#include <stdint.h>
#include "Board.hpp"

int main(void)
{
	int64_t a = 1 << 1;

	Board b();

	for (size_t i = 0; i < COLUMNS; i++)
	{
		Board::printInt64(COLUMNS_ARR[i]);
		printf("\n");
	}

	for (size_t i = 0; i < ROWS; i++)
	{
		Board::printInt64(ROWS_ARR[i]);
		printf("\n");
	}
}
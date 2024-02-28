#include <iostream>
#include <stdint.h>
#include "Board.hpp"

int main(void)
{
	int64_t a = 1 << 1;

	for (int i = 0; i < ROWS * (COLUMNS + 1); i++)
	{
		printf("iter-%d\n", i);
		Board::printInt64(a-1);
		printf("%lld", a);
		getchar();
		a <<= 1;
	}	
}
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "Board.hpp"

int main(void)
{
	unsigned char move;

	Board mainBoard = Board();

	for (size_t i = 0; i < 42; i++)
	{
		
		Board::printBoard(mainBoard);

		printf("Enter move (1-7):\n");
		scanf_s("%hhu", &move);

		system("cls");
		
		if (!(move >= 1 && move <= 7))
		{
			printf("\n|The move {%d} was not legal (1-7 only)|\n", move);
			i -= 1;
			continue;
		}

		if (!Board::isMoveLegal(mainBoard, move-1))
		{
			printf("\n|The move {%d} was not legal (full column)|\n", move);
			i -= 1;
			continue;
		}

		printf("\nmove:%hhu\n", move);
		mainBoard.playMove(&mainBoard, move-1);
	}

	Board::printBoard(mainBoard);
}
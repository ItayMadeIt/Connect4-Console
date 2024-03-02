#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "Board.hpp"

int main(void)
{
	unsigned char move;

	unsigned char moves[42] = { 0 };

	Board mainBoard = Board("");

	printf("\n");

	for (size_t i = 0; i < 42; i++)
	{
		
		Board::printBoard(mainBoard);

		printf("Enter move (1-7):\n");
		scanf_s("%hhu", &move);

		system("cls");
		
		if (move == 8)
		{
			Board::printBoard(mainBoard);
			printf("Enter undo move (1-7):\n");
			scanf_s("%hhu", &move);

			mainBoard.undoMove(&mainBoard, move - 1);

			continue;
		}

		if (move == 9)
		{
			printf("Moves:");

			for (size_t i = 0; i < 42; i++)
			{
				if (i % 7 == 0)
				{
					printf("\n");
				}

				printf("%d ", moves[i]);
			}

			printf("\n");
		}

		if (!(move >= 1 && move <= 8))
		{
			printf("~~~The move [%hhu] was not legal (1-7 only)~~~\n", move);
			i -= 1;
			continue;
		}

		if (!Board::isMoveLegal(mainBoard, move-1))
		{
			printf("~~~The move [%hhu] was not legal (full column)~~~\n", move);
			i -= 1;
			continue;
		}

		moves[i] = move;

		mainBoard.playMove(&mainBoard, move-1);
		printf("move: [%hhu] -- state: [%s]\n", move, Board::didWin(mainBoard) ? "WON" : "Id\'k");
	}

	Board::printBoard(mainBoard);
}
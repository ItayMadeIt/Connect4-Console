#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "Board.hpp"
#include "Solver.hpp"

int main(void)
{
	unsigned char move;

	unsigned char moves[42] = { 0 };

	Board mainBoard = Board("44455554221");

	printf("\n");

	for (size_t i = 0; i < 42; i++)
	{
		Board::printBoard(mainBoard);

		int8 bestMove = -1;
		int8 bestEval = mainBoard.isRed ? -100 : 100;

		for (size_t i = 0; i < COLUMNS; i++)
		{
			printf("depth:[%d] | move[%d]", 4, i);

			int8 moveEval = Solver::minimax(mainBoard, 3, true);

			printf(" score:[%d]\n", moveEval);

			if (mainBoard.isRed && moveEval > bestEval)
			{
				bestEval = moveEval;
				bestMove = i;
			}
			else if (!mainBoard.isRed && moveEval < bestEval)
			{
				bestEval = moveEval;
				bestMove = i;
			}
		}

		printf("\nBEST MOVE IS [%d]", bestMove+1);

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

		if (!(move >= 1 && move <= 7))
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
		printf("move: [%hhu] -- state: [%s]\n", move, Board::didWin(mainBoard) ? "WON" : "Id\"k");
	}

	Board::printBoard(mainBoard);
}
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "Board.hpp"

int main(void)
{
	unsigned char move;

	Board mainBoard = Board("44455554221");

	printf("\n");

	for (size_t i = 0; i < 42; i++)
	{
		
		Board::printBoard(mainBoard);

		printf("Enter move (1-7):\n");
		scanf_s("%hhu", &move);

		system("cls");
		
		if (!(move >= 1 && move <= 8))
		{
			printf("~~~The move [%hhu] was not legal (1-7 only)~~~\n", move);
			i -= 1;
			continue;
		}

		if (move == 8)
		{
			Board::printBoard(mainBoard);
			printf("Enter undo move (1-7):\n");
			scanf_s("%hhu", &move);

			mainBoard.undoMove(&mainBoard, move - 1);
			
			continue;
		}

		if (!Board::isMoveLegal(mainBoard, move-1))
		{
			printf("~~~The move [%hhu] was not legal (full column)~~~\n", move);
			i -= 1;
			continue;
		}

		

		//printf("move: [%hhu] -- state: [%s]\n", move, Board::stateToStr(Board::getGameState(mainBoard)));
		mainBoard.playMove(&mainBoard, move-1);
	}

	Board::printBoard(mainBoard);
}
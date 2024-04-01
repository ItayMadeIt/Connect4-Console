#include "Solver.hpp"

int8 Solver::minimax(Board board, int depth, bool debug)
{
	if (board.didWin(board))
	{
		return (42 - board.moves) * (!board.isRed ? 1 : -1);
	}
	if (depth == 0)
	{
		return 0;
	}

	bool isMaximizingPlayer = board.isRed;

	int8 bestMove = 0;
	int8 bestEval = isMaximizingPlayer ? -100 : 100;

	for (int8 i = 0; i < COLUMNS; i++)
	{
		if (!Board::isMoveLegal(board, i))
		{
			continue;
		}

		Board moveBoard = Board(board);

		Board::playMove(&moveBoard, i);

		// maximizing player
		if (board.isRed)
		{
			if (debug)
			{
				for (size_t j = 0; j < (4 - depth); j++)
				{
					printf("  ");
				}
				printf("depth:[%d] | move[%d]", depth, i);

				int8 curScore = minimax(moveBoard, depth - 1, false);

				printf(" score:[%d]\n", curScore);
			}

			int8 curScore = minimax(moveBoard, depth - 1, debug);

			if ((moveBoard.boards[ALL] & COLUMNS_MASKS[2]) != 0)
			{
				//printf("RED | DEPTH:[%d] | MOVE:[%d] | SCORE:[%d]\n", depth, i, curScore);
				//Board::printBoard(moveBoard);

			}
			if (bestEval < curScore)
			{
				bestEval = curScore;
				bestMove = i;
			}

			//printf("BEST MOVE:[%d]", bestMove);
		}
		// minimizing player
		else
		{
			if (debug)
			{
				for (size_t j = 0; j < (4 - depth); j++)
				{
					printf("  ");
				}
				printf("depth:[%d] | move[%d]", depth, i);

				int8 curScore = minimax(moveBoard, depth - 1, false);

				printf(" score:[%d]\n", curScore);
			}

			int8 curScore = minimax(moveBoard, depth - 1, true);

			if ((moveBoard.boards[ALL] & COLUMNS_MASKS[2]) != 0)
			{
				//printf("BLUE | DEPTH:[%d] | MOVE:[%d] | SCORE:[%d]\n", depth, i, curScore);
				//Board::printBoard(moveBoard);

			}

			if (bestEval > curScore)
			{
				bestEval = curScore;
				bestMove = i;
			}
			//printf("BEST MOVE:[%d]", bestMove);
		}
	}

	return bestEval;
}

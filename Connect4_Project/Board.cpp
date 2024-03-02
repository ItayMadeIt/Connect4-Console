#include "Board.hpp"



Board::Board()
{
	// reset every board (CURRENT and ALL)
	for (int i = 0; i < LENGTH; i++)
	{
		boards[i] = 0;
	}
}
Board::Board(const char* game)
{
	// reset every board (CURRENT and ALL)
	for (int i = 0; i < LENGTH; i++)
	{
		boards[i] = 0;
	}
	
	// play each move
	for (int i = 0; i < strlen(game); i++)
	{
		unsigned char move = game[i] - '1';
		
		if (!isMoveLegal(*this, move))
		{
			printf("~~~Initalization move [%hhu] was not legal (full column), move's index is [%d]~~~\n", move+1, i);

			return;
		}

		playMove(this, move);
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
	// add to the board (OR) the top move using a nice trick for adding a move on top 
	board->boards[ALL] |= board->boards[ALL] + (1ll << (move * ROWS));

	// switch board
	board->boards[CURRENT] ^= board->boards[ALL];

	// switch turn
	board->isRed = !board->isRed;
}

void Board::undoMove(Board* board, unsigned char move)
{
	// remove the last bit by getting only the piece on the column | (((board->boards[ALL] & COLUMNS_MASKS[move]) >> 1) & COLUMNS_MASKS[move]) |
	// then getting placing it instead of the current column in all by remove the bits at the column | (board->boards[ALL] & ~COLUMNS_MASKS[move]) |
	// then ORing it to get a result
	board->boards[ALL] = (board->boards[ALL] & ~COLUMNS_MASKS[move]) | (((board->boards[ALL] & COLUMNS_MASKS[move]) >> 1) & COLUMNS_MASKS[move]);

	// switch board
	board->boards[CURRENT] ^= board->boards[ALL];

	// switch turn
	board->isRed = !board->isRed;
}

bool Board::didWin(Board board)
{
	if ((board.boards[CURRENT] & (board.boards[CURRENT] << 1) & (board.boards[CURRENT] << 2) & (board.boards[CURRENT] << 3)) != 0)
	{
		return true;
	}
	if ((board.boards[CURRENT] & (board.boards[CURRENT] << ROWS) & (board.boards[CURRENT] << 2 * ROWS) & (board.boards[CURRENT] << 3 * ROWS)) != 0)
	{
		return true;
	}
	if ((board.boards[CURRENT] & (board.boards[CURRENT] << (ROWS + 1)) & (board.boards[CURRENT] << 2 * (ROWS + 1)) & (board.boards[CURRENT] << 3 * (ROWS + 1))) != 0)
	{
		return true;
	}
	if ((board.boards[CURRENT] & (board.boards[CURRENT] << (ROWS - 1)) & (board.boards[CURRENT] << 2 * (ROWS - 1)) & (board.boards[CURRENT] << 3 * (ROWS - 1))) != 0)
	{
		return true;
	}
	return false;
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

#ifndef BOARD_HPP
#define BOARD_HPP

#include <stdint.h>
#include <iostream>

#define ROWS 6
#define COLUMNS 7
#define SIZE ROWS * COLUMNS

#define int64 int64_t

#define RED_CHAR 'X'
#define BLUE_CHAR 'O'
#define EMPTY_CHAR '|'

const int64 ROWS_MASKS[ROWS] =
{
	1ll | 1ll << (ROWS) | 1ll << 2 * (ROWS) | 1ll << 3 * (ROWS) | 1ll << 4 * (ROWS) | 1ll << 5 * (ROWS) | 1ll << 6 * (ROWS),
	ROWS_MASKS[0] << 1,
	ROWS_MASKS[1] << 1,
	ROWS_MASKS[2] << 1,
	ROWS_MASKS[3] << 1,
	ROWS_MASKS[4] << 1,
};

const int64 COLUMNS_MASKS[COLUMNS] =
{
	 0b111111,
	 COLUMNS_MASKS[0] << (ROWS),
	 COLUMNS_MASKS[1] << (ROWS),
	 COLUMNS_MASKS[2] << (ROWS),
	 COLUMNS_MASKS[3] << (ROWS),
	 COLUMNS_MASKS[4] << (ROWS),
	 COLUMNS_MASKS[5] << (ROWS),
};

const int64 TOP_MASKS[COLUMNS]
{
	 COLUMNS_MASKS[0] & ROWS_MASKS[ROWS - 1],
	 COLUMNS_MASKS[1] & ROWS_MASKS[ROWS - 1],
	 COLUMNS_MASKS[2] & ROWS_MASKS[ROWS - 1],
	 COLUMNS_MASKS[3] & ROWS_MASKS[ROWS - 1],
	 COLUMNS_MASKS[4] & ROWS_MASKS[ROWS - 1],
	 COLUMNS_MASKS[5] & ROWS_MASKS[ROWS - 1],
	 COLUMNS_MASKS[6] & ROWS_MASKS[ROWS - 1]
};

enum players
{
	ALL = 0,
	CURRENT = 1,
	LENGTH = 2
};

struct Board
{
	
	int moves = 0;
	bool isRed = true;
	int64 boards[LENGTH] = { 0 };

	Board();
	Board(const char* game);

	static void printBoard(Board board);
	static bool isMoveLegal(Board board, unsigned char move);
	static void playMove(Board* board, unsigned char move);
	static void undoMove(Board* board, unsigned char move);
	static bool didWin(Board board);
	
	static void printInt64(int64 value) ;
	static bool isBitOn(int64 value, unsigned char position);
	static bool isBitOn(int64 value, signed char col, signed char row);

};

#endif
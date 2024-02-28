#ifndef BOARD_HPP
#define BOARD_HPP

#include <stdint.h>
#include <iostream>

#define ROWS 6
#define COLUMNS 7
#define SIZE ROWS * COLUMNS

#define int64 int64_t

const int64 ROWS_ARR[ROWS] =
{
	0b1111111,
	ROWS_ARR[0] << (COLUMNS + 1),
	ROWS_ARR[1] << (COLUMNS + 1),
	ROWS_ARR[2] << (COLUMNS + 1),
	ROWS_ARR[3] << (COLUMNS + 1),
	ROWS_ARR[4] << (COLUMNS + 1),
};

const int64 COLUMNS_ARR[COLUMNS] =
{
	 1ll | 1ll << (COLUMNS + 1) | 1ll << 2 * (COLUMNS + 1) | 1ll << 3 * (COLUMNS + 1) | 1ll << 4 * (COLUMNS + 1) | 1ll << 5 * (COLUMNS + 1),
	 COLUMNS_ARR[0] << 1,
	 COLUMNS_ARR[1] << 1,
	 COLUMNS_ARR[2] << 1,
	 COLUMNS_ARR[3] << 1,
	 COLUMNS_ARR[4] << 1,
	 COLUMNS_ARR[5] << 1,
};

enum players
{
	RED = 0,
	BLUE = 1,
	ALL = 2,
	LENGTH = 3
};

struct Board
{
	

	bool isRed = true;
	int64 boards[LENGTH] = { 0 };

	Board();
	Board(const char* game);

	static void printBoard(int64 boards[LENGTH]);
	static void playMove(int64 boards[LENGTH], bool isRed, unsigned char move);
	static void printInt64(int64 value) ;
	static bool isBitOn(int64 value, unsigned char position);
	static bool isBitOn(int64 value, signed char col, signed char row);

};

#endif
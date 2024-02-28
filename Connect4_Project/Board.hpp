#ifndef BOARD_HPP
#define BOARD_HPP

#include <stdint.h>
#include <iostream>

#define ROWS 6
#define COLUMNS 7
#define SIZE ROWS * COLUMNS

#define int64 int64_t


struct Board
{
	int64 redBoard  = 0;
	int64 blueBoard = 0;
	int64 allBoard  = 0;

	void printBoard();

	static void printInt64(int64 value) ;
	static bool isBitOn(int64 value, unsigned char position);
	static bool isBitOn(int64 value, signed char col, signed char row);
};

#endif
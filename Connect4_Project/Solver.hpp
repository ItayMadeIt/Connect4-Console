#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "Board.hpp"

class Solver
{
public:
	static int8 minimax(Board board, int depth, bool debug);
};

#endif
#include "MoveChecker.h"
#include <array>

std::array<std::array<bool, 4>, 4> MoveChecker::getTruthBoard(Board t_board, TileType t_currentPlayer)
{
	for (auto row : t_board.m_board)
	{
		for (auto cell : row)
		{
			// If this cell is taken up by the current player, make it empty
			cell = (cell == t_currentPlayer) ? TileType::Empty : cell;
		}
	}

	// Simplify the board into empty (0) or non empty (1) cells
	std::array<std::array<bool, 4>, 4> truthBoard;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			// Set each cell to 1 if != empty, and 0 if == empty
			truthBoard.at(row).at(col) = (t_board.m_board.at(row).at(col) != TileType::Empty);
		}
	}

	return truthBoard;
}

/////////////////////////////////////////////////////////////////////////////////////

bool MoveChecker::isMovePossible(Board t_board, TileType t_currentPlayer)
{
	// Fail fast. Are there any blank sections that are 3 long?
	for (auto row : t_board.m_board)
	{
		for (auto cell : row)
		{
		}
	}

	return false;
}
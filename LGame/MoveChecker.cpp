#include "MoveChecker.h"

bool MoveChecker::isMovePossible(Board t_board, TileType t_currentPlayer)
{
	for (auto row : t_board.m_board)
	{
		for (auto cell : row)
		{
			// If this cell is taken up by the current player, make it empty
			cell = (cell == t_currentPlayer) ? TileType::Empty : cell;
		}
	}

	// Fail fast. Are there any blank sections that are 3 long?
	for (auto row : t_board.m_board)
	{
		for (auto cell : row)
		{
		}
	}
	
	// We check if the middle 'plus' of cells is occupied
	int blockedCount{ 0 };

	for (int row = 0; row < 4; row++)
	{
		for (int col = 1; col < 3; col++)
		{
			if (t_board.m_board.at(row).at(col) != TileType::Empty)
			{
				blockedCount++;
			}

			if (t_board.m_board.at(col).at(row) != TileType::Empty)
			{
				blockedCount++;
			}
		}
	}

	// If they're all occupied, it's not possible to move the piece
	if (blockedCount >= 16)
	{
		return false;
	}

	return false;
}
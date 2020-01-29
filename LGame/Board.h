#ifndef BOARD_H
#define BOARD_H

/// <summary>
/// @author: Aaron O Neill
/// @date: 15/1/20
/// </summary>

#include <array>
#include "TileType.h"

class Board
{
public:
	Board(std::array<std::array<TileType, 4>, 4> mock);
	~Board();

	std::array<std::array<TileType, 4>, 4> m_board;
};
#endif
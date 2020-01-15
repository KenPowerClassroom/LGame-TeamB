#ifndef BOARD_H
#define BOARD_H

/// <summary>
/// @author: Aaron O Neill
/// @date: 15/1/20
/// </summary>


#include <array>

class Board
{
public:
	Board();
	~Board();

	std::array<std::array<int, 4>, 4> m_board;
};

#endif
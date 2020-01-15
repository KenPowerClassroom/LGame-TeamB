#pragma once

#include <SFML/Graphics.hpp>
#include <array>

class Board
{
public:
	Board();
	~Board();

	std::array<std::array<int, 4>, 4> m_board;
};


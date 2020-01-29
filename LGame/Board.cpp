#include "Board.h"

Board::Board(std::array<std::array<TileType, 4>, 4> mock) :
	m_board(mock)
{
}

Board::~Board()
{
}

#include "LPiece.h"

LPiece::LPiece(TileType t_tileType, int t_rowOffset, int t_colOffset) :
	m_shape
	{ {
		{ t_tileType,		t_tileType, TileType::Empty },
		{ TileType::Empty,	t_tileType, TileType::Empty },
		{ TileType::Empty,	t_tileType, TileType::Empty }
	} },
	m_rowOffset{ t_rowOffset },
	m_colOffset{ t_colOffset },
	m_hidden{ true }
{
}

void LPiece::setHidden(bool t_state)
{
	m_hidden = t_state;
}

std::array<std::array<TileType, 3>, 3> LPiece::getShape()
{
	return m_shape;
}

int LPiece::getRowOffset()
{
	return m_rowOffset;
}

int LPiece::getColOffset()
{
	return m_colOffset;
}

bool LPiece::isHidden()
{
	return m_hidden;
}

std::array<std::array<TileType, 4>, 4> LPiece::getBoardRelativeData()
{
	std::array<std::array<TileType, 4>, 4> boardData;

	// Loop through the shape array
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			boardData[row][col] = TileType::Empty;
		}
	}

	// Loop through the shape array
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			// Check if the value is not blank
			if (m_shape[row][col] != TileType::Empty)
			{
				boardData[row + m_rowOffset][col + m_colOffset] = m_shape[row][col];
			}
		}
	}

	return boardData;
}

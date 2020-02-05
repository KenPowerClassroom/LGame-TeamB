#include "LPiece.h"

LPiece::LPiece(int t_pieceColour, int t_rowOffset, int t_colOffset) :
	m_shape
	{ {
		{ t_pieceColour, t_pieceColour, 0 },
		{ 0,			 t_pieceColour, 0 },
		{ 0,			 t_pieceColour, 0 }
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

std::array<std::array<int, 3>, 3> LPiece::getShape()
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

#ifndef L_PIECE_H
#define L_PIECE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 15/01/2020
/// </summary>

#include <array>
#include "TileType.h"

class LPiece
{
public:
	LPiece(TileType t_tileType, int t_rowOffset, int t_colOffset);

	/// <summary>
	/// @brief Rotates the l-piece clockwise by 90 degrees
	/// </summary>
	void rotate();

	void setHidden(bool t_state);

	std::array<std::array<TileType, 3>, 3> getShape();
	int getRowOffset();
	int getColOffset();
	bool isHidden();

	std::array<std::array<TileType, 4>, 4> getBoardRelativeData();

	void flip();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();


private:
	std::array<std::array<TileType, 3>, 3> m_shape;
	int m_rowOffset;
	int m_colOffset;
	bool m_hidden;
};

#endif // !L_PIECE_H
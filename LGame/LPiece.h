#ifndef L_PIECE_H
#define L_PIECE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 15/01/2020
/// </summary>

#include <array>

class LPiece
{
public:
	LPiece(int t_pieceColour, int t_rowOffset, int t_colOffset);

	/// <summary>
	/// @brief Rotates the l-piece clockwise by 90 degrees
	/// </summary>
	void rotate();

	void setHidden(bool t_state);

	std::array<std::array<int, 3>, 3> getShape();
	int getRowOffset();
	int getColOffset();
	bool isHidden();

	std::array<std::array<int, 4>, 4> getBoardRelativeData();

private:
	std::array<std::array<int, 3>, 3> m_shape;
	int m_rowOffset;
	int m_colOffset;
	bool m_hidden;
};

#endif // !L_PIECE_H
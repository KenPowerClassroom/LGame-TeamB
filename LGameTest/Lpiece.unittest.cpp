#include "pch.h"
#include "..//LGame/LPiece.h"

TEST(LPiece, RedLpieceConstructer)
{
	LPiece lPiece(TileType::PlayerOne, 0, 1);

	ASSERT_EQ(TileType::PlayerOne, lPiece.getShape()[0][0]);
	ASSERT_EQ(TileType::PlayerOne, lPiece.getShape()[0][1]);
	ASSERT_EQ(TileType::Empty, lPiece.getShape()[1][0]);
	ASSERT_EQ(TileType::Empty, lPiece.getShape()[2][0]);

	ASSERT_EQ(true, lPiece.isHidden());

	ASSERT_EQ(0, lPiece.getRowOffset());
	ASSERT_EQ(1, lPiece.getColOffset());
}

TEST(LPiece, LpieceShowPiece)
{
	LPiece lPiece(TileType::PlayerOne, 0, 1);

	lPiece.setHidden(false);

	ASSERT_EQ(false, lPiece.isHidden());
}

TEST(LPiece, LpieceBoardDataTest)
{
	LPiece lPiece(TileType::PlayerOne, 0, 1);

	ASSERT_EQ(TileType::PlayerOne, lPiece.getBoardRelativeData()[0][1]);
	ASSERT_EQ(TileType::Empty, lPiece.getBoardRelativeData()[1][1]);
}
#include "pch.h"
#include "..//LGame/LPiece.h"

TEST(LPiece, RedLpieceConstructer)
{
	LPiece lPiece(2, 0, 1);

	ASSERT_EQ(2, lPiece.getShape()[0][0]);
	ASSERT_EQ(2, lPiece.getShape()[0][1]);
	ASSERT_EQ(2, lPiece.getShape()[1][1]);
	ASSERT_EQ(2, lPiece.getShape()[2][1]);

	ASSERT_EQ(true, lPiece.isHidden());

	ASSERT_EQ(0, lPiece.getRowOffset());
	ASSERT_EQ(1, lPiece.getColOffset());
}

TEST(LPiece, LpieceShowPiece)
{
	LPiece lPiece(2, 0, 1);

	lPiece.setHidden(false);

	ASSERT_EQ(false, lPiece.isHidden());
}

TEST(LPiece, LpieceBoardDataTest)
{
	LPiece lPiece(2, 0, 1);

	ASSERT_EQ(2, lPiece.getBoardRelativeData()[0][1]);
	ASSERT_EQ(0, lPiece.getBoardRelativeData()[1][1]);
}
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

TEST(LPiece, FlipTest) 
{
	LPiece testPiece(2, 0, 0);

	std::array<std::array<int, 3>, 3> testArray; // create an array to hold the Lpiece info
	testPiece.flip(); // call the flip function
	testArray = testPiece.getShape(); // update the test array
	ASSERT_EQ(2, testArray[0][2]); // make sure the values match a flipped piece
	ASSERT_EQ(0, testArray[2][0]);
}
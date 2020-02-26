#include "pch.h"
#include "..//LGame/LPiece.h"

TEST(LPiece, RedLpieceConstructor)
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

TEST(LPiece, BlueLpieceConstructor)
{
	LPiece lPiece(TileType::PlayerTwo, 1, 0);

	ASSERT_EQ(TileType::PlayerTwo, lPiece.getShape()[0][0]);
	ASSERT_EQ(TileType::PlayerTwo, lPiece.getShape()[0][1]);
	ASSERT_EQ(TileType::Empty, lPiece.getShape()[1][0]);
	ASSERT_EQ(TileType::Empty, lPiece.getShape()[2][0]);

	ASSERT_EQ(1, lPiece.getRowOffset());
	ASSERT_EQ(0, lPiece.getColOffset());
}

TEST(LPiece, LpieceShowPiece)
{
	LPiece testPiece(static_cast<TileType>(2), 0, 0);

	std::array<std::array<TileType, 3>, 3> testArray; // create an array to hold the Lpiece info
	testPiece.flip(); // call the flip function
	testArray = testPiece.getShape(); // update the test array

	LPiece lPiece(TileType::PlayerOne, 0, 1);

	lPiece.setHidden(false);

	ASSERT_EQ(false, lPiece.isHidden());
	ASSERT_EQ(static_cast<TileType>(2), testArray[0][2]); // make sure the values match a flipped piece
	ASSERT_EQ(static_cast<TileType>(0), testArray[2][0]);
}

TEST(LPiece, FlipTest_2)
{
	LPiece lPiece(TileType::PlayerOne, 0, 0);
	lPiece.rotate();
	lPiece.rotate();
	lPiece.rotate();

	std::array<std::array<TileType, 3>, 3> originalPos
	{
		{
			{TileType::Empty,	TileType::Empty,	TileType::Empty},
			{TileType::PlayerOne,	TileType::PlayerOne,TileType::PlayerOne},
			{TileType::PlayerOne,		TileType::Empty,	TileType::Empty}
		}
	};

	std::array<std::array<TileType, 3>, 3> flippedPos
	{
		{
			{TileType::Empty,		TileType::Empty,		TileType::Empty},
			{TileType::PlayerOne,	TileType::PlayerOne,	TileType::PlayerOne},
			{TileType::Empty,		TileType::Empty,		TileType::PlayerOne}
		}
	};

	ASSERT_EQ(originalPos, lPiece.getShape());

	lPiece.flip();

	ASSERT_EQ(flippedPos, lPiece.getShape());
}

TEST(LPiece, LpieceBoardDataTest)
{
	LPiece lPiece(TileType::PlayerOne, 0, 1);

	ASSERT_EQ(TileType::PlayerOne, lPiece.getBoardRelativeData()[0][1]);
	ASSERT_EQ(TileType::Empty, lPiece.getBoardRelativeData()[1][1]);
}


TEST(LPiece, FlipTest)
{
	LPiece testPiece(TileType::PlayerOne, 0, 0);

	std::array<std::array<TileType, 3>, 3> testArray; // create an array to hold the Lpiece info
	testPiece.flip(); // call the flip function
	testArray = testPiece.getShape(); // update the test array
	ASSERT_EQ(TileType::PlayerOne, testArray[0][2]); // make sure the values match a flipped piece
	ASSERT_EQ(TileType::Empty, testArray[2][0]);
}

TEST(LPiece, LpieceRotate)
{
	LPiece lPiece(TileType::PlayerOne, 0, 0);

	std::array<std::array<TileType, 3>, 3> originalPos
	{
		{
			{TileType::PlayerOne,	TileType::PlayerOne,	TileType::Empty},
			{TileType::Empty,		TileType::PlayerOne,	TileType::Empty},
			{TileType::Empty,		TileType::PlayerOne,	TileType::Empty}
		}
	};

	std::array<std::array<TileType, 3>, 3> rotatedPos
	{
		{
			{TileType::Empty,		TileType::Empty,		TileType::PlayerOne},
			{TileType::PlayerOne,	TileType::PlayerOne,	TileType::PlayerOne},
			{TileType::Empty,		TileType::Empty,		TileType::Empty}
		}
	};

	ASSERT_EQ(originalPos, lPiece.getShape());

	lPiece.rotate();

	ASSERT_EQ(rotatedPos, lPiece.getShape());
}

TEST(LPiece, LpieceMoveUp)
{
	LPiece lPiece(TileType::PlayerOne, 1, 0);

	int originalOffset = 1;

	int movedOffset = 0;

	ASSERT_EQ(originalOffset, lPiece.getRowOffset());

	lPiece.moveUp();

	ASSERT_EQ(movedOffset, lPiece.getRowOffset());
}

TEST(LPiece, LpieceMoveDown)
{
	LPiece lPiece(TileType::PlayerOne, 2, 0);

	int originalOffset = 2;

	int movedOffset = 2;

	ASSERT_EQ(originalOffset, lPiece.getRowOffset());

	lPiece.moveDown();

	ASSERT_EQ(movedOffset, lPiece.getRowOffset());
}

TEST(LPiece, LpieceMoveRight)
{
	LPiece lpiece(TileType::PlayerOne, 0, 1);

	int originalOffset = 1;

	int movedOffset = 2;

	ASSERT_EQ(originalOffset, lpiece.getColOffset());

	lpiece.moveRight();

	ASSERT_EQ(movedOffset, lpiece.getColOffset());
}

TEST(LPiece, LpieceMoveLeft)
{
	LPiece lpiece(TileType::PlayerOne, 0, 1);

	int originalOffset = 1;

	int movedOffset = 0;

	ASSERT_EQ(originalOffset, lpiece.getColOffset());

	lpiece.moveLeft();

	ASSERT_EQ(movedOffset, lpiece.getColOffset());
}

TEST(LPiece, LPieceRotateOnInput)
{
	LPiece testPiece(TileType::PlayerOne, 0, 1);

}
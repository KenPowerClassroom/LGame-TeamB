#include "pch.h"
#include "..//LGame/PieceUpdater.h"

TEST(PieceUpdater, MoveDown) 
{
    PieceUpdater m_updater;
    LPiece lpiece(TileType::PlayerOne, 0, 0);
    SFMLKeyboardInput m_input;

    m_input.m_down = true;
    ASSERT_EQ(0, lpiece.getRowOffset());

    m_updater.update(&lpiece, &m_input);

    ASSERT_EQ(1, lpiece.getRowOffset());
}

TEST(PieceUpdater, MoveUp)
{
    PieceUpdater m_updater;
    LPiece lpiece(TileType::PlayerOne, 1, 0);
    SFMLKeyboardInput m_input;

    m_input.m_up = true;

    ASSERT_EQ(1, lpiece.getRowOffset());

    m_updater.update(&lpiece, &m_input);

    ASSERT_EQ(0, lpiece.getRowOffset());
}

TEST(PieceUpdater, MoveRight)
{
    PieceUpdater m_updater;
    LPiece lpiece(TileType::PlayerOne, 0, 0);
    SFMLKeyboardInput m_input;

    m_input.m_right = true;

    ASSERT_EQ(0, lpiece.getColOffset());

    m_updater.update(&lpiece, &m_input);

    ASSERT_EQ(1, lpiece.getColOffset());
}

TEST(PieceUpdater, MoveLeft)
{
    PieceUpdater m_updater;
    LPiece lpiece(TileType::PlayerOne, 0, 1);
    SFMLKeyboardInput m_input;

    m_input.m_left = true;

    ASSERT_EQ(1, lpiece.getColOffset());

    m_updater.update(&lpiece, &m_input);

    ASSERT_EQ(0, lpiece.getColOffset());
}

TEST(PieceUpdater, Flip)
{
    PieceUpdater m_updater;
    SFMLKeyboardInput m_input;
    LPiece testPiece(TileType::PlayerOne, 0, 0);

    std::array<std::array<TileType, 3>, 3> testArray; // create an array to hold the Lpiece info
    m_input.m_flip = true;
    m_updater.update(&testPiece, &m_input);

    testArray = testPiece.getShape(); // update the test array
    ASSERT_EQ(TileType::PlayerOne, testArray[0][2]); // make sure the values match a flipped piece
    ASSERT_EQ(TileType::Empty, testArray[2][0]);
}

TEST(PieceUpdater, Rotate)
{
    PieceUpdater m_updater;
    SFMLKeyboardInput m_input;
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

    m_input.m_rotate = true;
    m_updater.update(&lPiece, &m_input);

	ASSERT_EQ(rotatedPos, lPiece.getShape());
}

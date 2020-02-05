#include "pch.h"
#include "..//LGame/Board.h"

TEST(Board, ConstructorTest) {
	std::array<std::array<int, 4>, 4> m_board =
	{ {
		{1,2,2,0},
		{0,3,2,0},
		{0,3,2,0},
		{0,3,3,1}
	} };

	std::array<std::array<TileType, 4>, 4> mockBoard;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			mockBoard[row][col] = static_cast<TileType>(m_board[row][col]);
		}
	}

	Board testBoard(mockBoard);

	EXPECT_EQ(testBoard.m_board[1][1], static_cast<TileType>(3));

	EXPECT_EQ(testBoard.m_board[3][1], static_cast<TileType>(3));

	EXPECT_EQ(testBoard.m_board[2][0], static_cast<TileType>(0));
}

//TEST(Board, ConstructorTest) {
//	std::array<std::array<int, 4>, 4> m_board =
//	{ {
//		{1,2,2,0},
//		{0,3,2,0},
//		{0,3,2,0},
//		{0,3,3,1}
//	} };
//	
//	Board testBoard(m_board);
//
//	EXPECT_EQ(testBoard.m_board[1][1], 3);
//
//	EXPECT_EQ(testBoard.m_board[3][1], 3);
//
//	EXPECT_EQ(testBoard.m_board[2][0], 0);
//}

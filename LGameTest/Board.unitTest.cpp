#include "pch.h"
#include "../LGame/Board.h"

TEST(BoardTest, ValueCheck ) {
	Board TestBoard;

	EXPECT_EQ(TestBoard.m_board[1][1], 3);
}

TEST(TestCaseName0, TestName0) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
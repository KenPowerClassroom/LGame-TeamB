#include "pch.h"
#include "..//LGame/Board.h"

TEST(Board, DefaultValueCheck) {
	Board mockBoard;
	EXPECT_EQ(mockBoard.m_board[1][1], 3);
	EXPECT_TRUE(true);
}
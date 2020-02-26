#include "pch.h"
#include "..//LGame/MoveChecker.h"

TEST(MoveChecker, truthBoardTest)
{
	std::array<std::array<TileType, 4>, 4> boardData
	{
		{
			{ TileType::Coin, TileType::PlayerOne, TileType::PlayerOne, TileType::Empty },
			{ TileType::Empty,TileType::PlayerTwo ,TileType::PlayerOne ,TileType::Empty },
			{ TileType::Empty,TileType::PlayerTwo ,TileType::PlayerOne ,TileType::Empty },
			{ TileType::Empty,TileType::PlayerTwo ,TileType::PlayerTwo ,TileType::Coin }
		}
	};

	Board board(boardData);

	std::array<std::array<bool, 4>, 4> expectedResult
	{
		{
			{true,false,false,false},
			{false,true,false,false},
			{false,true,false,false},
			{false,true,true,true}
		}
	};

	ASSERT_EQ(MoveChecker::getTruthBoard(board, TileType::PlayerOne), expectedResult);
}
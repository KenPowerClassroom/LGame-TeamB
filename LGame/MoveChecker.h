#pragma once

// @Author: Ben Millar
// @Date: 26/02/2020

#include "Board.h"
#include "TileType.h"
#include "LPiece.h"

class MoveChecker
{
public:
	MoveChecker() = default;
	~MoveChecker() = default;

	/// <summary>
	/// @brief Generate a board of bools showing which cells are empty
	/// </summary>
	/// <param name="t_board">Game board to process</param>
	/// <param name="t_currentPlayer">Player whose turn it is (to remove from board)</param>
	/// <returns>4x4 array of bools; 0 if empty, 1 if not empty</returns>
	static std::array<std::array<bool, 4>, 4> getTruthBoard(Board t_board, TileType t_currentPlayer = TileType::PlayerOne);

	/// <summary>
	/// @brief Determines if at least 1 move is possible for the current player
	/// </summary>
	/// <param name="t_board">Game board to process</param>
	/// <param name="t_currentPlayer">Player whose turn it is (to remove from board)</param>
	/// <returns>True if >=1 move is possible, false otherwise</returns>
	static bool isMovePossible(Board t_board, TileType t_currentPlayer = TileType::PlayerOne);

private:
};
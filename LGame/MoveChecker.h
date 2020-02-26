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

	static bool isMovePossible(Board t_board, TileType t_currentPlayer = TileType::PlayerOne);

private:
};
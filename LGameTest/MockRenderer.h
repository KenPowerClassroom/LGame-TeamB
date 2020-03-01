#pragma once

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 01/03/2020
/// </summary>

#include "../LGame/Render.h"

class MockRenderer : public Render
{
public:

	virtual void draw(std::array<std::array<TileType, 4>, 4> const& t_boardData) override
	{

	}


protected:

	virtual void drawPiece(TileType, unsigned int t_row, unsigned int t_col) override
	{

	}
};


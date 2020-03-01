#ifndef GAME_H
#define GAME_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 26/02/2020
/// </summary>

#include "GameState.h"
#include "Render.h"
#include "Input.h"
#include "Board.h"
#include "LPiece.h"

class Game
{
public:

	Game(Input & t_input, Render & t_renderer);

	void start();

	void updateGameState(Input const* t_input);

	const GameState getGameState() const;

private:

	void update();

	GameState m_gameState;

	Render & m_renderer;

	Input & m_input;

	Board m_board;
	LPiece m_lPiece;
};

#endif // !GAME_H
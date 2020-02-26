#ifndef GAME_H
#define GAME_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 26/02/2020
/// </summary>

#include "SFMLRenderer.h"
#include "Board.h"
#include "LPiece.h"
#include "SFMLKeyboardInput.h"
#include "GameState.h"

class Game
{
public:

	Game();

	void start();

	void updateGameState(Input const* t_input);

	const GameState getGameState() const;

private:

	void update();

	void updateGameState(Input const* t_input, GameState& t_gameStateRef);

	void updateLPiece(Input const* t_input, LPiece * t_player);

	GameState m_gameState;

	sf::RenderWindow m_window;
	SFMLRenderer m_renderer;

	SFMLKeyboardInput m_input;

	Board m_board;
	LPiece m_lPiece;
};

#endif // !GAME_H
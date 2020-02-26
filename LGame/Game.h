#ifndef GAME_H
#define GAME_H

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
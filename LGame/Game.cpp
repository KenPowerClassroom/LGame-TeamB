#include "Game.h"

/////////////////////////////////////////////////////////////////////////////////////
Game::Game(Input& t_input, Render& t_renderer) :
	m_gameState{ GameState::View },
	m_lPiece{ TileType::PlayerOne, 0, 1 },
	m_input{ t_input },
	m_renderer{ t_renderer },
	m_board{ std::array<std::array<TileType, 4>, 4>
	{ {
		{ TileType::Coin, TileType::PlayerOne, TileType::PlayerOne, TileType::Empty },
		{ TileType::Empty, TileType::PlayerTwo,TileType::PlayerOne, TileType::Empty},
		{ TileType::Empty, TileType::PlayerTwo,TileType::PlayerOne, TileType::Empty},
		{ TileType::Empty, TileType::PlayerTwo, TileType::PlayerTwo, TileType::Coin }
	} } }
{
}

/////////////////////////////////////////////////////////////////////////////////////
void Game::start()
{
	update();
}

/////////////////////////////////////////////////////////////////////////////////////
void Game::update()
{
	while (!m_input.m_gameClosed)
	{
		m_input.update();

		updateGameState(&m_input);

		if (GameState::View == m_gameState)
		{
			m_renderer.draw(m_board.m_board);
		}
		else
		{
			m_renderer.draw(m_lPiece.getBoardRelativeData());
			m_pieceUpdater.update(&m_lPiece, &m_input);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////
void Game::updateGameState(Input const* t_input)
{
	if (t_input->m_continue)
	{
		switch (m_gameState)
		{
		case GameState::View:
			m_gameState = GameState::MoveLPiece;
			break;
		case GameState::MoveLPiece:
			m_gameState = GameState::View;
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////
const GameState Game::getGameState() const
{
	return m_gameState;
}

/////////////////////////////////////////////////////////////////////////////////////
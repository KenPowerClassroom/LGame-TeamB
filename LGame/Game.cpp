#include "Game.h"

/////////////////////////////////////////////////////////////////////////////////////
Game::Game() :
	m_gameState{ GameState::View },
	m_window{ sf::VideoMode(1100, 620, 32U), "L Game", sf::Style::Default },
	m_lPiece{ TileType::PlayerOne, 0, 1 },
	m_board{ std::array<std::array<TileType, 4>, 4>
	{ {
		{ TileType::Coin, TileType::PlayerOne, TileType::PlayerOne, TileType::Empty },
		{ TileType::Empty, TileType::PlayerTwo,TileType::PlayerOne, TileType::Empty},
		{ TileType::Empty, TileType::PlayerTwo,TileType::PlayerOne, TileType::Empty},
		{ TileType::Empty, TileType::PlayerTwo, TileType::PlayerTwo, TileType::Coin }
	} } }
{
	m_renderer.setWindowRef(m_window);
	m_input.setWindowRef(m_window);
}

/////////////////////////////////////////////////////////////////////////////////////
void Game::start()
{
	update();
}

/////////////////////////////////////////////////////////////////////////////////////
void Game::update()
{
	while (m_window.isOpen())
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
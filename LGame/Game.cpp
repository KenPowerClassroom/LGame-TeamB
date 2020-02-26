#include "Game.h"

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

void Game::start()
{
	update();
}

void Game::update()
{
	while (m_window.isOpen())
	{
		m_input.update();

		updateGameState(&m_input, m_gameState);

		if (GameState::View == m_gameState)
		{
			m_renderer.draw(m_board.m_board);
		}
		else
		{
			m_renderer.draw(m_lPiece.getBoardRelativeData());
		}
	}
}

void Game::updateGameState(Input const* t_input, GameState& t_gameStateRef)
{
	if (t_input->m_continue)
	{
		switch (t_gameStateRef)
		{
		case GameState::View:
			t_gameStateRef = GameState::MoveLPiece;
			break;
		case GameState::MoveLPiece:
			t_gameStateRef = GameState::View;
			break;
		}
	}
}

#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer() :
	m_window{ nullptr },
	m_square{TILE_SIZE},
	TILE_SIZE{ 100.f,100.f },
	TILE_OFFSET{ 100 },
	TILE_COLOURS{
		sf::Color::White,
		sf::Color::Black,
		sf::Color::Red,
		sf::Color::Blue
	}
{
	m_square.setOutlineColor(sf::Color::Black);
	m_square.setOutlineThickness(1.0f);
}

/////////////////////////////////////////////////////////////////////////////////////
void SFMLRenderer::setWindowRef(sf::RenderWindow& t_windowRef)
{
	m_window = &t_windowRef;
}

/////////////////////////////////////////////////////////////////////////////////////
void SFMLRenderer::draw(std::array<std::array<TileType, 4>, 4> const& t_boardData)
{
	if (m_window == nullptr)
	{
		throw("ERROR: Renderers window reference is nullptr");
	}

	m_window->clear(sf::Color::White);

	for (int row = 0; row < t_boardData.size(); row++) // Loop through board data rows
	{
		for (int col = 0; col < t_boardData.size(); col++) // Loop through board data cols
		{
			drawPiece(t_boardData[row][col], row, col);
		}
	}

	m_window->display();
}

/////////////////////////////////////////////////////////////////////////////////////
void SFMLRenderer::drawPiece(TileType t_type, unsigned int t_row, unsigned int t_col)
{
	m_square.setFillColor(TILE_COLOURS[static_cast<int>(t_type)]);
	m_square.setPosition(TILE_OFFSET + (TILE_SIZE.x * t_col), TILE_OFFSET + (TILE_SIZE.y * t_row));

	m_window->draw(m_square); // draw the tile
}
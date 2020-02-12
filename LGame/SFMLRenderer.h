#pragma once
#include <SFML/Graphics.hpp>
#include "Render.h"

class SFMLRenderer :
	public Render
{
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	SFMLRenderer();

	/// <summary>
	/// Default Destructor
	/// </summary>
	~SFMLRenderer() override = default;

	void setWindowRef(sf::RenderWindow& t_windowRef);

	virtual void draw(std::array<std::array<TileType, 4>, 4> const& t_boardData) override;

private:

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	/// <param name=""></param>
	virtual void drawPiece(TileType, unsigned int, unsigned int) override;

	// Data members

	/// <summary>
	/// SFML Render window for displaying game
	/// </summary>
	sf::RenderWindow * m_window;
	
	/// <summary>
	/// the size of each tile
	/// </summary>
	const sf::Vector2f TILE_SIZE; 

	/// <summary>
	/// amount of pixels between the board and the edge of the screen 
	/// </summary>
	const int TILE_OFFSET; 

	/// <summary>
	/// all the possible colours
	/// </summary>
	const std::array<sf::Color, 4> TILE_COLOURS;
	 
	/// <summary>
	/// represents all the tiles
	/// </summary>
	sf::RectangleShape m_square;
};
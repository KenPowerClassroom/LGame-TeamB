#pragma once

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

class Render
{
public:

	/// <summary>
	/// Default Constructor
	/// </summary>
	Render();

	/// <summary>
	/// Default Destructor
	/// </summary>
	~Render() = default;

	void draw(Board t_board);

private:
	/// <summary>
	/// SFML Render window for displaying game
	/// </summary>
	sf::RenderWindow m_window; 
	sf::RectangleShape m_square; // represents all the tiles
	std::array<sf::Color, 4> m_tileColours; // all the possible colours
	sf::Vector2f m_tileSize; // the size of each tile
	int m_tileOffset; // amount of pixels between the board and the edge of the screen 

};
#include "Render.h"

Render::Render() : m_window{ sf::VideoMode(1100, 620, 32U), "L Game", sf::Style::Default },
m_tileColours({ sf::Color::White, sf::Color::Black, sf::Color::Red, sf::Color::Blue }), 
m_tileSize{ 100.f,100.f },
m_tileOffset{ 100 }
{
}

////////////////////////////////////////////////

void Render::draw()
{
	m_window.clear(sf::Color::White	); // clear the screen white
	sf::RectangleShape m_square; // create a square to represent the tile
	m_square.setOutlineThickness(1.f); // set a border on the square
	m_square.setOutlineColor(sf::Color::Black); // make it black 
	m_square.setSize(m_tileSize); // square size

	for(int i =0; i < m_mockBoard.m_board.size(); i++) // loop through all the array
		for (int j = 0; j < m_mockBoard.m_board.size(); j++)
		{
			m_square.setFillColor(m_tileColours[m_mockBoard.m_board[i][j]]);// assign the colour based on the tile colour array 
			m_square.setPosition(m_tileOffset + (m_tileSize.x * j), m_tileOffset + (m_tileSize.y * i)); // set the position with an offset
			m_window.draw(m_square); // draw every tile
		}

	m_window.display(); // display the tile
}
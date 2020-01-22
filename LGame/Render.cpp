#include "Render.h"

Render::Render() : m_window{ sf::VideoMode(1100, 620, 32U), "L Game", sf::Style::Default },
m_tileColours({ sf::Color::White, sf::Color::Black, sf::Color::Red, sf::Color::Blue }), 
m_tileSize{ 100.f,100.f },
m_tileOffset{ 100 }
{
	m_square.setOutlineThickness(1.f); // set a border on the square
	m_square.setOutlineColor(sf::Color::Black); // make it black 
	m_square.setSize(m_tileSize); // square size
}

////////////////////////////////////////////////

void Render::draw(Board t_board)
{
	m_window.clear(sf::Color::White	); // clear the screen white

	for (int i = 0; i < t_board.m_board.size(); i++) // loop through all the array
	{
		for (int j = 0; j < t_board.m_board.size(); j++)
		{
			m_square.setFillColor(m_tileColours[t_board.m_board[i][j]]);// assign the colour based on the tile colour array 
			m_square.setPosition(m_tileOffset + (m_tileSize.x * j), m_tileOffset + (m_tileSize.y * i)); // set the position with an offset
			m_window.draw(m_square); // draw every tile
		}
	}

	m_window.display(); // display the tile
}


//sf:Rectangle getPiece(m_mockBoard, i, j) {
//m_square.setFillColor(m_tileColours[m_mockBoard.m_board[i][j]]);// assign the colour based on the tile colour array 
//m_square.setPosition(m_tileOffset + (m_tileSize.x * j), m_tileOffset + (m_tileSize.y * i)); // set the position with an offset
//
//return square;
//}
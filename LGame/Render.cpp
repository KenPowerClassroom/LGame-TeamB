#include "Render.h"

Render::Render() : m_window{ sf::VideoMode(1100, 620, 32U), "L Game", sf::Style::Default }
{
}

////////////////////////////////////////////////

void Render::draw()
{
	m_window.display();
}
#include "SFMLKeyboardInput.h"

/////////////////////////////////////////////////////////////////////////////////////
SFMLKeyboardInput::SFMLKeyboardInput() :
	m_window{ nullptr }
{
}

/////////////////////////////////////////////////////////////////////////////////////
void SFMLKeyboardInput::setWindowRef(sf::RenderWindow& t_window)
{
	m_window = &t_window;
}

/////////////////////////////////////////////////////////////////////////////////////
void SFMLKeyboardInput::update()
{
	m_continue = false;
	m_left = false;
	m_right = false;
	m_up = false;
	m_down = false;

	sf::Event nextEvent;

	if (m_window == nullptr)
	{
		throw ("ERROR: Input's window reference is nullptr");
	}

	while (m_window->pollEvent(nextEvent))
	{
		if (sf::Event::Closed == nextEvent.type)
		{
			m_window->close();
		}
		if (sf::Event::KeyPressed == nextEvent.type)
		{
			switch (nextEvent.key.code)
			{
			case sf::Keyboard::Left:
				m_left = true;
				break;
			case sf::Keyboard::Right:
				m_right = true;
				break;
			case sf::Keyboard::Up:
				m_up = true;
				break;
			case sf::Keyboard::Down:
				m_down = true;
				break;
			case sf::Keyboard::Space:
				m_continue = true;
				break;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////
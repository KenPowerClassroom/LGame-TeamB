#pragma once

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 12/02/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include "Input.h"

class SFMLKeyboardInput : public Input
{
public:
	SFMLKeyboardInput();

	void setWindowRef(sf::RenderWindow& t_window);

	virtual void update() override;

private:

	sf::RenderWindow* m_window;

};


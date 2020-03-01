// LGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Game.h"
#include "SFMLKeyboardInput.h"
#include "SFMLRenderer.h"

int main()
{
	sf::RenderWindow window{ sf::VideoMode(1100, 620, 32U), "L Game", sf::Style::Default };

	SFMLKeyboardInput input;
	SFMLRenderer renderer;

	renderer.setWindowRef(window);
	input.setWindowRef(window);

	Game game(input, renderer);
	game.start();

	return 0;
}
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

	void draw();

private:
	/// <summary>
	/// SFML Render window for displaying game
	/// </summary>
	sf::RenderWindow m_window;
};
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
#include "Board.h"
#include "TileType.h"

class Render
{
public:
	/// <summary>
	/// Default Constructor
	/// </summary>
	Render() = default;

	/// <summary>
	/// Default Destructor
	/// </summary>
	virtual ~Render() = default;

	virtual void draw(std::array<std::array<TileType, 4>, 4> const & t_boardData) = 0;


protected:

	virtual void drawPiece(TileType , unsigned int , unsigned int ) = 0;
};
// LGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Render.h"
#include "Board.h"

int main()
{
	Render renderer;
	std::array<std::array<int, 4>, 4> m_board =
	{ {
		{1,2,2,0},
		{0,3,2,0},
		{0,3,2,0},
		{0,3,3,1}
	} };

	Board testBoard(m_board);

	renderer.draw(testBoard);
	system("pause");

	return 0;
}
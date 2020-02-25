// LGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "SFMLRenderer.h"
#include "Board.h"
#include "LPiece.h"

int main()
{
	Render* renderer = new SFMLRenderer;
	std::array<std::array<int, 4>, 4> m_integerBoard =
	{ {
		{1,2,2,0},
		{0,3,2,0},
		{0,3,2,0},
		{0,3,3,1}
	} };

	std::array<std::array<TileType, 4>, 4> m_board;

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			m_board[row][col] = static_cast<TileType>(m_integerBoard[row][col]);
		}
	}

	Board testBoard(m_board);

	renderer->draw(testBoard.m_board);

	system("pause");

	LPiece lPiece(TileType::PlayerOne, 0, 1);
	lPiece.moveRight();
	renderer->draw(lPiece.getBoardRelativeData());
	system("pause");
	lPiece.moveLeft();
	renderer->draw(lPiece.getBoardRelativeData());
	system("pause");
	lPiece.moveUp();
	renderer->draw(lPiece.getBoardRelativeData());
	system("pause");
	lPiece.moveDown();
	renderer->draw(lPiece.getBoardRelativeData());

	system("pause");

	LPiece lPieceTwo(TileType::PlayerTwo, 1, 0);
	lPieceTwo.rotate();
	lPieceTwo.rotate();

	renderer->draw(lPieceTwo.getBoardRelativeData());

	system("pause");

	return 0;
}
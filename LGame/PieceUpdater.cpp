#include "PieceUpdater.h"

PieceUpdater::PieceUpdater()
{
}

void PieceUpdater::update(LPiece* t_player, Input const* t_input)
{
	if (t_input->m_down)
	{
		t_player->moveDown();
	}
	else if (t_input->m_up)
	{
		t_player->moveUp();
	}
	else if (t_input->m_right)
	{
		t_player->moveRight();
	}
	else if (t_input->m_left)
	{
		t_player->moveLeft();
	}
	else if (t_input->m_flip)
	{
		t_player->flip();
	}
	else if (t_input->m_rotate)
	{
		t_player->rotate();
	}
	
}

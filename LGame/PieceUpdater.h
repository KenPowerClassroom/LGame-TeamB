#pragma once
#include "LPiece.h"
#include "SFMLKeyboardInput.h"

class PieceUpdater
{
public:
	PieceUpdater();

	void update(LPiece* t_player, Input const* t_input);

};


#pragma once

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 12/02/2020
/// </summary>

class Input
{
public:
	Input();

	virtual void update() = 0;

	bool m_left;
	bool m_right;
	bool m_up;
	bool m_down;
	bool m_continue;
	bool m_gameClosed;
};


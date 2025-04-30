#include "square.h"
#include "raymath.h"

void Square::update()
{
	//
}

void Square::draw()
{
	DrawRectangleV((m_position - Vector2{m_size/2, m_size/2}), Vector2{m_size, m_size}, m_color);
};


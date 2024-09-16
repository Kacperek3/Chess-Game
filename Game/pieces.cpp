// pieces.cpp
#include "pieces.h"

Piece::Piece(int color, sf::Vector2f position, PieceType type)
    : m_color(color), m_position(position), m_type(type) 
{
    
}

Piece::~Piece() {}

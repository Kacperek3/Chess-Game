// pieces.cpp
#include "Pieces.h"

Piece::Piece(int color, sf::Vector2f position, PieceType type)
    : m_color(color), m_position(position), m_type(type) 
{
    
}
sf::Sprite& Piece::getSprite() {
    return sprite;
}

sf::Vector2f Piece::getPosition() {
    return m_position;
}

Piece::Piece() {}

Piece::~Piece() {}

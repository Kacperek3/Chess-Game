// pieces.cpp
#include "Pieces.h"

Piece::Piece(int color, sf::Vector2f position, PieceType type, int boardX, int boardY)
    : m_color(color), m_position(position), m_type(type) 
{
    boardPosition = Coordinate(boardX, boardY);
}
sf::Sprite& Piece::getSprite() {
    return sprite;
}

sf::Vector2f Piece::getPosition() {
    return m_position;
}

Coordinate Piece::getBoardPosition(){
    return boardPosition;
}


Piece::Piece() {}

Piece::~Piece() {}

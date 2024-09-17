// pawn.cpp
#include "pawn.h"

Pawn::Pawn() {
    
}

Pawn::Pawn(int color, int boardX, int boardY)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::Pawn) 
{
    if (color == 0) {
        texture.loadFromFile("/home/kacper/Pulpit/chess/assets/pieces/wPawn.png");
    } else {
        texture.loadFromFile("assets/black_pawn.png");
    }
    sprite.setTexture(texture);
    sprite.setPosition(m_position);
}


Pawn::~Pawn() {}

void Pawn::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Pawn::move(sf::Vector2f newPosition) {
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

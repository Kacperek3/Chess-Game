// Rock.cpp
#include "Rook.h"

Rook::Rook() {
    
}

Rook::Rook(int color, int boardX, int boardY)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::Rook) 
{
    std::filesystem::path currentPath = std::filesystem::current_path().parent_path();
    std::string filePath;

    if (color == 0) {
        filePath = (currentPath / "assets/pieces/wRook.png").string();
    } else {
        filePath = (currentPath / "assets/pieces/bRook.png").string();
    }

    if (!texture.loadFromFile(filePath)) {
        // todo error handling
    }

    sprite.setTexture(texture);
    sprite.setPosition(m_position);
}


Rook::~Rook() {}

void Rook::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


void Rook::move(sf::Vector2f newPosition) {
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

void Rook::move(int boardX, int boardY) {
    sf::Vector2f newPosition = Position(boardX, boardY).getPixelPosition();
    m_position = newPosition;
    sprite.setPosition(newPosition);
}
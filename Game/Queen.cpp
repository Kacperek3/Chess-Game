// Queen.cpp
#include "Queen.h"

Queen::Queen() {
    
}

Queen::Queen(int color, int boardX, int boardY)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::Queen) 
{
    std::filesystem::path currentPath = std::filesystem::current_path().parent_path();
    std::string filePath;

    if (color == 0) {
        filePath = (currentPath / "assets/pieces/wQueen.png").string();
    } else {
        filePath = (currentPath / "assets/pieces/bQueen.png").string();
    }

    if (!texture.loadFromFile(filePath)) {
        // todo error handling
    }

    sprite.setTexture(texture);
    sprite.setPosition(m_position);
}


Queen::~Queen() {}

void Queen::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


void Queen::move(sf::Vector2f newPosition) {
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

void Queen::move(int boardX, int boardY) {
    sf::Vector2f newPosition = Position(boardX, boardY).getPixelPosition();
    m_position = newPosition;
    sprite.setPosition(newPosition);
}
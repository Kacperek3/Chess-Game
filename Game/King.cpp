// King.cpp
#include "King.h"

King::King() {
    
}

King::King(int color, int boardX, int boardY)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::King) 
{

    std::filesystem::path currentPath = std::filesystem::current_path().parent_path();
    std::string filePath;

    std::cout << currentPath << std::endl;
    if (color == 0) {
        filePath = (currentPath / "assets/pieces/wKing.png").string();
    } else {
        filePath = (currentPath / "assets/pieces/wKing.png").string();
    }

    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Error loading texture: " << filePath << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(m_position);
}

King::~King() {}

void King::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


void King::move(sf::Vector2f newPosition) {
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

void King::move(int boardX, int boardY) {
    sf::Vector2f newPosition = Position(boardX, boardY).getPixelPosition();
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

// Knight.cpp
#include "Knight.h"

Knight::Knight() {
    
}

Knight::Knight(int color, int boardX, int boardY)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::Knight) 
{

    std::filesystem::path currentPath = std::filesystem::current_path().parent_path();
    std::string filePath;

    std::cout << currentPath << std::endl;
    if (color == 0) {
        filePath = (currentPath / "assets/pieces/wKnight.png").string();
    } else {
        filePath = (currentPath / "assets/pieces/bKnight.png").string();
    }

    if (!texture.loadFromFile(filePath)) {
        std::cerr << "Error loading texture: " << filePath << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setPosition(m_position);
}

Knight::~Knight() {}

void Knight::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


void Knight::move(sf::Vector2f newPosition) {
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

void Knight::move(int boardX, int boardY) {
    sf::Vector2f newPosition = Position(boardX, boardY).getPixelPosition();
    m_position = newPosition;
    sprite.setPosition(newPosition);
}

#include "Board.h"

Board::Board() {
    // Inicjalizacja planszy, np. ładowanie tekstur
    b_pieces.push_back(new Knight(BLACK, 1, 0));
    b_pieces.push_back(new Knight(WHITE, 2, 1));
    
}

void Board::draw(sf::RenderWindow& window) {
    
    sf::Color lightColor(238, 238, 210); 
    sf::Color darkColor(118, 150, 86); 

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            sf::RectangleShape tile(sf::Vector2f(75, 75));
            tile.setPosition(col * 75, row * 75);
            if ((row + col) % 2 == 0) {
                    tile.setFillColor(lightColor); 
            } else {
                tile.setFillColor(darkColor);
            }
            window.draw(tile);
        }
    }
    for (auto& piece : b_pieces) {
        piece->draw(window);
    }
}

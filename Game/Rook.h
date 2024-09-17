#pragma once

#include <SFML/Graphics.hpp>
#include "Pieces.h"


class Rook : public Piece {
public:
    Rook(int color, int boardX, int boardY);
    Rook();
    ~Rook();

    void draw(sf::RenderWindow& window) override;
    void move(int boardX, int boardY) override;
    void move(sf::Vector2f newPosition) override;
    
private:
    
};

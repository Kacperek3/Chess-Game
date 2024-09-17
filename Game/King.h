#pragma once

#include <SFML/Graphics.hpp>
#include "Pieces.h"
#include <iostream>


class King : public Piece {
public:
    King(int color, int boardX, int boardY);
    King();
    ~King();

    void draw(sf::RenderWindow& window) override;
    void move(int boardX, int boardY) override;
    void move(sf::Vector2f newPosition) override;
    
private:
    
};

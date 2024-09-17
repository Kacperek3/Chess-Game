#pragma once

#include <SFML/Graphics.hpp>
#include "Pieces.h"



class Queen : public Piece {
public:
    Queen(int color, int boardX, int boardY);
    Queen();
    ~Queen();

    void draw(sf::RenderWindow& window) override;
    void move(int boardX, int boardY) override;
    void move(sf::Vector2f newPosition) override;
    
private:
    
};

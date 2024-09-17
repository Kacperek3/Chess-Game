#pragma once

#include <SFML/Graphics.hpp>
#include "pieces.h"
#include "Positions.h"


class Pawn : public Piece {
public:
    Pawn(int color, int boardX, int boardY);
    Pawn();
    ~Pawn();

    void draw(sf::RenderWindow& window) override;
    void move(sf::Vector2f newPosition) override;
private:
    
};

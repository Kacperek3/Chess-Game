#pragma once

#include <SFML/Graphics.hpp>
#include "pieces.h"


class Pawn : public Piece {
public:
    Pawn(int color, sf::Vector2f position);
    ~Pawn();

    void draw(sf::RenderWindow& window) override;
    void move(sf::Vector2f newPosition) override;
private:
    
};

#pragma once

#include <SFML/Graphics.hpp>
#include "Pieces.h"
#include <iostream>


class Bishop : public Piece {
public:
    Bishop(int color, int boardX, int boardY, Board* board);
    Bishop();
    ~Bishop();

    void draw(sf::RenderWindow& window) override;
    void move(int boardX, int boardY) override;
    void move(sf::Vector2f newPosition) override;
    bool isValidMove(int boardX, int boardY);
    
private:
    
};

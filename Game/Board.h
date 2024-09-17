#pragma once


#include <SFML/Graphics.hpp>
#include <vector>
#include "pawn.h"

class Board {
public:
    Board();  
    void draw(sf::RenderWindow& window);  
    std::vector<Piece*> b_pieces;
private:
    // Możesz dodać zmienne, które będą reprezentować stan planszy
};
#pragma once


#include <SFML/Graphics.hpp>
#include <vector>
#include "pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"


class Board {
public:
    Board();  
    void draw(sf::RenderWindow& window);  
    std::vector<Piece*> b_pieces;
private:
    // Możesz dodać zmienne, które będą reprezentować stan planszy
};
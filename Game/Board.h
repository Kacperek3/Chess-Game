#pragma once


#include <SFML/Graphics.hpp>
#include <map>
#include "pawn.h"

class Board {
public:
    Board();  // Konstruktor
    void draw(sf::RenderWindow& window);  // Funkcja rysująca planszę

private:
    // Możesz dodać zmienne, które będą reprezentować stan planszy
};
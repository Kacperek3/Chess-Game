// pieces.h
#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "Positions.h"

#define WHITE 0
#define BLACK 1

class Piece {
public:
    enum class PieceType {
        Pawn, Rook, Knight, Bishop, Queen, King
    };

    Piece(int color, sf::Vector2f position, PieceType type);
    Piece();
    virtual ~Piece();  // Ensure this is virtual

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void move(int boardX, int boardY) = 0;
    virtual void move(sf::Vector2f newPosition) = 0;


    sf::Sprite& getSprite();
    sf::Vector2f getPosition();
    

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f m_position;
    int m_color;
    PieceType m_type;
};

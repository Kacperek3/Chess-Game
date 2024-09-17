// pieces.h
#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "Positions.h"

#define WHITE 0
#define BLACK 1


class Board;

struct Coordinate {
    int x, y;
    Coordinate() : x(0), y(0) {}  
    Coordinate(int x, int y) : x(x), y(y) {}
};


class Piece {
public:
    enum class PieceType {
        Pawn, Rook, Knight, Bishop, Queen, King
    };

    Piece(int color, sf::Vector2f position, PieceType type, int boardX, int boardY);
    Piece();
    virtual ~Piece();  // Ensure this is virtual

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void move(int boardX, int boardY) = 0;
    virtual void move(sf::Vector2f newPosition) = 0;


    sf::Sprite& getSprite();
    sf::Vector2f getPosition();
    Coordinate getBoardPosition();
    int getColor() { return m_color; }
    PieceType getType() { return m_type; }
    

protected:
    Board* board;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f m_position;
    int m_color;
    PieceType m_type;
    Coordinate boardPosition;

};

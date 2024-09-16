// pieces.h
#pragma once
#include <SFML/Graphics.hpp>

class Piece {
public:
    enum class PieceType {
        Pawn, Rook, Knight, Bishop, Queen, King
    };

    Piece(int color, sf::Vector2f position, PieceType type);
    virtual ~Piece();  // Ensure this is virtual

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void move(sf::Vector2f newPosition) = 0;

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f m_position;
    int m_color;
    PieceType m_type;
};

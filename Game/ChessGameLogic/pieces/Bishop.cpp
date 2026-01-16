#include "Bishop.h"
#include "Board.h"

Bishop::Bishop() {
    
}

Bishop::Bishop(int color, int boardX, int boardY, Board* board, sf::Texture& bishopTexture)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::Bishop, boardX, boardY, 3) 
{
    this->board = board;
    sprite.setTexture(bishopTexture);
    sprite.setPosition(m_position);
}

std::vector<Coordinate> Bishop::getPossibleMoves() {
    std::vector<Coordinate> possibleMoves;

    int directions[4][2] = {
        {1, 1},   
        {-1, 1},  
        {-1, -1}, 
        {1, -1}   
    };

    for (auto& direction : directions) {
        int dx = direction[0];
        int dy = direction[1];

        int x = boardPosition.x;
        int y = boardPosition.y;

        while (true) {
            x += dx;
            y += dy;

            if (board->isWithinBounds(x, y)) {
                if (board->isEmpty(x, y)) {
                    possibleMoves.push_back(Coordinate(x, y));
                } else {
                    if (board->isEnemyPieceAt(x, y, m_color)) {
                        possibleMoves.push_back(Coordinate(x, y));
                    }
                    break; 
                }
            } else {
                break; 
            }
        }
    }

    return possibleMoves;
}

std::vector<Coordinate> Bishop::getPossibleCaptures() {
    std::vector<Coordinate> possibleCaptures;

    int directions[4][2] = {
        {1, 1},  
        {-1, 1}, 
        {-1, -1}, 
        {1, -1}   
    };

    for (auto& direction : directions) {
        int dx = direction[0];
        int dy = direction[1];

        int x = boardPosition.x;
        int y = boardPosition.y;

        while (true) {
            x += dx;
            y += dy;

            if (board->isWithinBounds(x, y)) {
                if (!board->isEmpty(x, y)) {
                    if (board->isEnemyPieceAt(x, y, m_color)) {
                        possibleCaptures.push_back(Coordinate(x, y));
                    }
                    break; 
                }
            } else {
                break; 
            }
        }
    }

    return possibleCaptures;
}

bool Bishop::isValidMove(int boardX, int boardY) {
    if (!board->isWithinBounds(this->boardPosition.x, this->boardPosition.y) || !board->isWithinBounds(boardX, boardY)) {
        return false;  
    }

    int dx = abs(boardX - boardPosition.x);
    int dy = abs(boardY - boardPosition.y);

    if (dx == dy) {
        int xDirection = (boardX - boardPosition.x > 0) ? 1 : -1;
        int yDirection = (boardY - boardPosition.y > 0) ? 1 : -1;
        
        for (int i = 1; i < dx; ++i) {  
            if (!board->isEmpty(boardPosition.x + i * xDirection, boardPosition.y + i * yDirection)) {
                return false;  
            }
        }

        if (board->isEmpty(boardX, boardY)) {
            return true;
        } else if (board->isEnemyPieceAt(boardX, boardY, m_color)) {
            return true;
        }
    }

    return false;  
}

void Bishop::rotatePiece() {
    Piece::rotatePiece();
}

Bishop::~Bishop() {}

void Bishop::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

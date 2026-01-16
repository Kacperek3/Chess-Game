#include "Knight.h"
#include "Board.h"

Knight::Knight() {
    
}

Knight::Knight(int color, int boardX, int boardY, Board* board, sf::Texture& knightTexture)
    : Piece(color, Position(boardX, boardY).getPixelPosition(), Piece::PieceType::Knight, boardX, boardY, 3) 
{
    this->board = board;
    sprite.setTexture(knightTexture);
    sprite.setPosition(m_position);
}


std::vector<Coordinate> Knight::getPossibleMoves() {
    std::vector<Coordinate> possibleMoves;

    int directions[8][2] = {
        {2, 1},  
        {1, 2},  
        {-1, 2}, 
        {-2, 1}, 
        {-2, -1},
        {-1, -2},
        {1, -2}, 
        {2, -1}  
    };

    for (auto& direction : directions) {
        int dx = direction[0];
        int dy = direction[1];

        int x = boardPosition.x + dx;
        int y = boardPosition.y + dy;

        if (board->isWithinBounds(x, y)) {
            if (board->isEmpty(x, y) || board->isEnemyPieceAt(x, y, m_color)) {
                possibleMoves.push_back(Coordinate(x, y));
            }
        }
    }

    return possibleMoves;
}

std::vector<Coordinate> Knight::getPossibleCaptures() {
    std::vector<Coordinate> possibleCaptures;

    int directions[8][2] = {
        {2, 1},  
        {1, 2},  
        {-1, 2}, 
        {-2, 1}, 
        {-2, -1},
        {-1, -2},
        {1, -2}, 
        {2, -1}  
    };

    for (auto& direction : directions) {
        int dx = direction[0];
        int dy = direction[1];

        int x = boardPosition.x + dx;
        int y = boardPosition.y + dy;

        if (board->isWithinBounds(x, y) && board->isEnemyPieceAt(x, y, m_color)) {
            possibleCaptures.push_back(Coordinate(x, y));
        }
    }

    return possibleCaptures;
}


bool Knight::isValidMove(int boardX, int boardY) {

    if (!board->isWithinBounds(this->boardPosition.x, this->boardPosition.y) || !board->isWithinBounds(boardX, boardY)) {
        return false;  
    }

    int dx = abs(boardX - boardPosition.x);
    int dy = abs(boardY - boardPosition.y);

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        if (board->isEmpty(boardX, boardY)) {
            return true;  
        } else if (board->isEnemyPieceAt(boardX, boardY, m_color)) {
            return true;
        }
    }
    
    return false;  
}

void Knight::rotatePiece() {
    Piece::rotatePiece();    
}

Knight::~Knight() {}

void Knight::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

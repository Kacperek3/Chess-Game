#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>
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
    void draw(sf::RenderWindow& window, bool showCoordinates);  
    bool isEmpty(int x, int y);
    bool isEnemyPieceAt(int boardX, int boardY, int color) const;
    void removePiece(int boardX, int boardY);
    bool isKingInCheck(int color);
    bool canKingMove(int color);
    bool canPreventCheck(int color);
    bool isWithinBounds(int x, int y);
    bool isCheckmate(int color);
    std::vector<Piece*> b_pieces; // wektor przechowujący wskaźniki na obiekty klasy Piece





    
    
    bool isKingInCheckAfterMove(Piece* movedPiece, Coordinate targetPosition);
    std::vector<Coordinate> getValidMoves(Piece* piece);
    void simulateMove(Piece* piece, Coordinate targetPosition);
    void undoMove(Piece* piece, Coordinate originalPosition, Piece* capturedPiece);


private:
    Piece* findKing(int color);
    std::vector<Piece*> playerPieces(int color);
    std::vector<Piece*> enemyPieces(int color) const;
};
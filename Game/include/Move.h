#pragma once
struct Move {
    Piece* piece;
    int fromX, fromY;
    int toX, toY;
    int score; // Do sortowania

    Move() : piece(nullptr), fromX(0), fromY(0), toX(0), toY(0), score(0) {}
    Move(Piece* p, int tx, int ty) : piece(p), toX(tx), toY(ty), score(0) {
        if(p) {
            Coordinate pos = p->getBoardPosition();
            fromX = pos.x;
            fromY = pos.y;
        }
    }
};

// Szybka lista ruchów bez alokacji dynamicznej
struct MoveList {
    Move moves[256]; // W szachach rzadko jest więcej niż 218 ruchów
    int count = 0;

    void add(Piece* p, int tx, int ty) {
        if (count < 256) {
            moves[count] = Move(p, tx, ty);
            count++;
        }
    }
    
    // Umożliwia iterację pętlą for(:)
    Move* begin() { return &moves[0]; }
    Move* end() { return &moves[count]; }
};
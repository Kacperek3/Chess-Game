#pragma once
#include "Board.h"
#include "Game.h"
#include <vector>
#include <random>
#include <cstdint>
#include <unordered_map>


class AiLogic {
public:

    AiLogic(GameDataRef data);
    ~AiLogic();
    float evaluatePositionWhite(int color, Piece* RecentlyMovedPiece, int depth);
    float evaluatePositionBlack(int color, Piece* RecentlyMovedPiece, int depthfloat);

    float minimax(int depth, int color, bool maximizingPlayer, float alpha, float beta, Piece* RecentlyMovedPiece);
    std::pair<Piece*, Coordinate> getBestMove(int depth, int color);
    void aiMove(int color);

    Board *_board;

private:
    float getPositionValue(Piece* piece);
    bool canBeCaptured(Piece* piece);
    int canBeCapturedRecursive(Piece* piece);
    void handleCastle(Piece* movedPiece, const Coordinate& target, Piece*& rook, Coordinate& rookOriginalPosition, Coordinate& rookTargetPosition);
    void undoCastle(Piece* movedPiece, const Coordinate& target);
    void initializeZobristTable();
    uint64_t computeZobristHash(Board* board);
    bool isPromisingMove(Piece* movedPiece, Coordinate target);


    std::vector<std::pair<Piece*, Coordinate>>getAllMovesSorted(int color);
    std::pair<Piece*, Coordinate> getBestMoveIterative(int maxDepth, int color);

    GameDataRef _data;

    uint64_t zobristTable[64][12];
    std::unordered_map<uint64_t, float> transpositionTable;

    const float pawnBlackPositionValues[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0.3, 0.3, 0.5, -0.5, -0.5, 0.5, 0.3, 0.3},
        {0.3, 0.1, 0.0, 0.5, 0.5, 0.0, 0.1, 0.3},
        {0, 0.1, 0.5, 1, 1, 0.5, 0.1, 0},
        {0.3, 0.5, 0.7, 1.2, 1.2, 0.7, 0.5, 0.3},
        {0.5, 0.7, 1.0, 1.5, 1.5, 1.0, 0.7, 0.5},
        {1.0, 1.0, 1.2, 1.5, 1.5, 1.2, 1.0, 1.0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };


    const float pawnWhitePositionValues[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1.0, 1.0, 1.2, 1.5, 1.5, 1.2, 1.0, 1.0},
        {0.5, 0.7, 1.0, 1.5, 1.5, 1.0, 0.7, 0.5},
        {0.3, 0.5, 0.7, 1.2, 1.2, 0.7, 0.5, 0.3},
        {0, 0.1, 0.5, 1, 1, 0.5, 0.1, 0},
        {0.3, 0.1, 0.0, 0.5, 0.5, 0.0, 0.1, 0.3},
        {0.3, 0.3, 0.5, -0.5, -0.5, 0.5, 0.3, 0.3},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    const float knightPositionValues[8][8] = {
        {-2.5, -2.0, -1.5, -1.5, -1.5, -1.5, -2.0, -2.5},
        {-1.5, -1.0, -0.5, -0.5, -0.5, -0.5, -1.0, -1.5},
        {-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0, -1.0},
        {-0.5, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, -0.5},
        {-0.5, 0.5, 1.0, 1.5, 1.5, 1.0, 0.5, -0.5},
        {-1.0, 0.0, 0.5, 1.0, 1.0, 0.5, 0.0, -1.0},
        {-1.5, -1.0, -0.5, -0.5, -0.5, -0.5, -1.0, -1.5},
        {-2.5, -2.0, -1.5, -1.5, -1.5, -1.5, -2.0, -2.5}
    };


    const float bishopPositionValues[8][8] = {
    {-1.0, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -1.0},
    {-0.5, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, -0.5},
    {-0.5, 0.0, 0.5, 0.5, 0.5, 0.5, 0.0, -0.5},
    {-0.5, 0.5, 0.5, 0.7, 0.7, 0.5, 0.5, -0.5},
    {-0.5, 0.0, 0.7, 0.7, 0.7, 0.7, 0.0, -0.5},
    {-0.5, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, -0.5},
    {-0.5, 0.5, 0.0, 0.0, 0.0, 0.0, 0.5, -0.5},
    {-1.0, -0.5, -0.5, -0.5, -0.5, -0.5, -0.5, -1.0}
};


   const float rookPositionValues[8][8] = {
    {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0},
    {0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5},
    {0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0},
    {0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0},
    {0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0},
    {0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.0},
    {0.5, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.5},
    {0.0, 0.0, 0.0, 0.5, 0.5, 0.0, 0.0, 0.0}
};


    const float queenPositionValues[8][8] = {
    {-0.5, -0.3, -0.3, -0.1, -0.1, -0.3, -0.3, -0.5},
    {-0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.3},
    {-0.3, 0.0, 0.2, 0.2, 0.2, 0.2, 0.0, -0.3},
    {-0.1, 0.0, 0.2, 0.3, 0.3, 0.2, 0.0, -0.1},
    {-0.1, 0.0, 0.2, 0.3, 0.3, 0.2, 0.0, -0.1},
    {-0.3, 0.2, 0.2, 0.2, 0.2, 0.2, 0.0, -0.3},
    {-0.3, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, -0.3},
    {-0.5, -0.3, -0.3, -0.1, -0.1, -0.3, -0.3, -0.5}
};


    const float kingPositionValuesWhite[8][8] = {
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-2, -3, -3, -4, -4, -3, -3, -2},
        {-1, -2, -2, -2, -2, -2, -2, -1},
        {2, 2, 0, 0, 0, 0, 2, 2},
        {2, 3, 1, 0, 0, 1, 3, 2}
    };

    const float kingPositionValuesBlack[8][8] = {
        {2, 3, 1, 0, 0, 1, 3, 2},
        {2, 2, 0, 0, 0, 0, 2, 2},
        {-1, -2, -2, -2, -2, -2, -2, -1},
        {-2, -3, -3, -4, -4, -3, -3, -2},
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-3, -4, -4, -5, -5, -4, -4, -3},
        {-3, -4, -4, -5, -5, -4, -4, -3}
    };

};
#pragma once
#include "Board.h"
#include "Game.h"
#include <vector>


class AiLogic {
public:

    AiLogic(GameDataRef data);
    ~AiLogic();
    int evaluatePosition(int color);
    int minimax(int depth, int color, bool maximizingPlayer, int alpha, int beta);
    std::pair<Piece*, Coordinate> getBestMove(int depth, int color);
    void aiMove(int color);


    Board *_board;

private:
    GameDataRef _data;


};
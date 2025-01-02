#include "AiLogic.h"


AiLogic::AiLogic(GameDataRef data): _data(data){
    _board = new Board(data);
    _board->Init();
}

AiLogic::~AiLogic(){
    delete _board;
}


int AiLogic::evaluatePosition(int color) {
    int score = 0;

    // Dodaj wartości materiału
    for (Piece* piece : _board->playerPieces(color)) {
        if(piece->getBoardPosition().x == -1 && piece->getBoardPosition().y == -1){
            continue;
        }
        score += piece->getValue();
    }
    for (Piece* piece : _board->enemyPieces(color)) {
        if(piece->getBoardPosition().x == -1 && piece->getBoardPosition().y == -1){
            continue;
        }
        score -= piece->getValue();
    }

    // Dodaj inne kryteria
    if (_board->isKingInCheck(color)) {
        score -= 5; // kara za szach
    }
    if (_board->isKingInCheck(1 - color)) {
        score += 5; // nagroda za szach przeciwnika
    }

    if(_board->isCheckmate(1 - color)){
        score -= 10000;
    }
    if(_board->isCheckmate(color)){
        score += 10000;
    }



    return score;
}


int AiLogic::minimax(int depth, int color, bool maximizingPlayer) {

    if (depth == 0 || _board->isCheckmate(color) || _board->isStalemate(color)) {
        int eval = evaluatePosition(color);
        return eval;
    }

    int bestScore = maximizingPlayer ? -10000 : 10000;

    // Pobierz wszystkie ruchy
    auto allMoves = _board->getAllMoves(color);

    for (const auto& move : allMoves) {
        Piece* movedPiece = move.first;
        Coordinate target = move.second;
        Piece* capturedPiece = _board->getPieceAt(target.x, target.y);

        if (!movedPiece) {
            std::cerr << "Error: movedPiece is null! Skipping move." << std::endl;
            continue;
        }

        Coordinate originalPosition = movedPiece->getBoardPosition();

        // Wykonaj ruch
        movedPiece->simulateMove(target.x, target.y);
        if (capturedPiece) {
            capturedPiece->simulateMove(-1, -1); // Usuń zbity pionek
        }

        // Rekurencja
        int score = minimax(depth - 1, 1 - color, !maximizingPlayer);

        // Cofnij ruch
        movedPiece->simulateMove(originalPosition.x, originalPosition.y);
        if (capturedPiece) {
            capturedPiece->simulateMove(target.x, target.y);
        }
        
        // Aktualizuj najlepszy wynik
        if (maximizingPlayer) {
            bestScore = std::max(bestScore, score);
        } else {
            bestScore = std::min(bestScore, score);
        }
    }

    return bestScore;
}


std::pair<Piece*, Coordinate> AiLogic::getBestMove(int depth, int color) {
    int bestScore = -10000;
    std::pair<Piece*, Coordinate> bestMove;
    auto allMoves = _board->getAllMoves(color);

    for (const auto& move : allMoves) {
        Piece* movedPiece = move.first;
        Coordinate target = move.second;
        Piece* capturedPiece = _board->getPieceAt(target.x, target.y);

        Coordinate originalPosition = movedPiece->getBoardPosition();

        // Wykonaj ruch
        movedPiece->move(target.x, target.y);
        if (capturedPiece) capturedPiece->simulateMove(-1, -1);

        // Sprawdź wynik
        int score = minimax(depth - 1, 1 - color, false);

        // Cofnij ruch
        movedPiece->simulateMove(originalPosition.x, originalPosition.y);
        if (capturedPiece) {
            capturedPiece->simulateMove(target.x, target.y);
        }

        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }

    return bestMove;
}


void AiLogic::aiMove(int color) {
    std::pair<Piece*, Coordinate> bestMove = getBestMove(4, color);
    Piece* movedPiece = bestMove.first;
    Coordinate target = bestMove.second;


    Piece* capturedPiece = _board->getPieceAt(target.x, target.y);


    if (capturedPiece) _board->removePiece(target.x, target.y, nullptr);
    // Wykonaj ruch
    movedPiece->move(target.x, target.y);
    
}




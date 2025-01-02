#pragma once

#include "Game.h"
#include <vector>
#include <iostream>


#define WHITE 0
#define BLACK 1


#define checkmate 1
#define stalemate 2
#define timeEnd 3
#define resignation 4


#define newGame 1
#define goToMainMenu 2

class GameOver {
public:
    GameOver(GameDataRef data);
    ~GameOver();
    void Init();
    void whoWins(int color, int reason);
    void Update();
    bool UserInput();
    void Draw();
    
private:
    GameDataRef _data;
   
    sf::Font _font;
    sf::Text *_textFielHeader;
    sf::Text *_textFielReason;

    sf::Sprite _playAgainButton;
    sf::Sprite _goToMenuButton;

    sf::RectangleShape* _backround;
    sf::RectangleShape* _backgroundToHeader;
};
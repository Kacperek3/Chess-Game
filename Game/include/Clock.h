#pragma once


#include <SFML/Graphics.hpp>
#include "Game.h"

class ClockWidget {

public:
    ClockWidget(GameDataRef data);
    ~ClockWidget() = default;
    void Init();
    void Draw();
      
private:
    GameDataRef _data;
    sf::Clock _clock;
    float _dt;

    sf::RectangleShape _rec;
    sf::Sprite _startButton;
      
};
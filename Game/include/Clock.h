#pragma once


#include <SFML/Graphics.hpp>
#include "Game.h"
#include <sstream>
#include <iomanip>

class ClockWidget {

public:
    ClockWidget(GameDataRef data);
    ~ClockWidget();
    void Init();
    void isStartButtonPressed();
    void inputTime(sf::Event event);
    void Update();

    void Draw();




      
private:
    GameDataRef _data;
    sf::Clock _clock;

    sf::Sprite _startButton;
    sf::Font _font;



    sf::Text *_textFieldBlack;
    std::string inputTextBlack = "";
    sf::Clock countdownClockBlack;
    int remainingTimeInSecondsBlack = 0;
    bool isCountdownActiveBlack = false;
    sf::Sprite _backgroudn_to_textFieldBlack;

    sf::Text *_textFieldWhite;
    //std::string inputTextWhite = "";
    //sf::Clock countdownClockWhite;
    //int remainingTimeInSecondsWhite = 0;
    //bool isCountdownActiveWhite = false;
    //sf::Sprite _backgroudn_to_textFieldWhite;
};
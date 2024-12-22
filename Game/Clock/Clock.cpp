#include "Clock.h"

ClockWidget::ClockWidget(GameDataRef data) : _data(data) {
    
}

ClockWidget::~ClockWidget() {
    std::cout << "ClockWidget destructor" << std::endl;
    delete _textFieldBlack;
}

void ClockWidget::Init() {
    _data->assetManager.LoadTexture("START_BUTTON", "../assets/GameWithFriendState/Buttons/StartButton.png");
    _data->assetManager.LoadTexture("START_BUTTON_HOVER", "../assets/GameWithFriendState/Buttons/StartButton_hover.png");
    _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON"));
    _startButton.setPosition(610, 271);
    _startButton.setScale(0.90, 0.90);

    _data->assetManager.LoadFont("Poppins", "../assets/fonts/Poppins-Thin.ttf");
    _font = _data->assetManager.GetFont("Poppins");

    _textFieldBlack = new sf::Text();
    _textFieldBlack->setFont(_font);
    _textFieldBlack->setCharacterSize(24);
    _textFieldBlack->setFillColor(sf::Color::Black);
    _textFieldBlack->setPosition(665, 35);
    _textFieldBlack->setOutlineColor(sf::Color::White);
    _textFieldBlack->setOutlineThickness(1);
    _textFieldBlack->setString("00:00");
    _textFieldBlack->setStyle(sf::Text::Bold);


    _textFieldWhite = new sf::Text();
    _textFieldWhite->setFont(_font);
    _textFieldWhite->setCharacterSize(24);
    _textFieldWhite->setFillColor(sf::Color::Black);
    _textFieldWhite->setPosition(665, 400);
    _textFieldWhite->setOutlineColor(sf::Color::White);
    _textFieldWhite->setOutlineThickness(1);
    _textFieldWhite->setString("00:00");
    _textFieldWhite->setStyle(sf::Text::Bold);



    _data->assetManager.LoadTexture("BACKGROUND_TO_TEXTFIELD", "../assets/TextClockBackground.png");
    _data->assetManager.LoadTexture("BACKGROUND_TO_TEXTFIELD_POINTED", "../assets/TextClockBackgroundPointed.png");

    _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
    _backgroudn_to_textFieldBlack.setPosition(620, 25);
}


void ClockWidget::isStartButtonPressed() {
    if (_data->inputManager.IsSpriteClicked(_startButton, sf::Mouse::Left, _data->window)) {
        // Pobierz czas z _textField i aktywuj odliczanie
        try {
            int minutes = std::stoi(inputTextBlack.substr(0, 2));
            int seconds = std::stoi(inputTextBlack.substr(3, 2));
            remainingTimeInSecondsBlack = minutes * 60 + seconds;
            countdownClockBlack.restart();
            isCountdownActiveBlack = true;
        } catch (...) {
            std::cout << "Nieprawidłowy format czasu" << std::endl;
        }
    }
}

void ClockWidget::inputTime(sf::Event event) {
    if (std::isdigit(event.text.unicode)) {
        inputTextBlack += static_cast<char>(event.text.unicode);
    }
    else if (event.text.unicode == 58) { 
        inputTextBlack += ":";
    }
    else if (event.text.unicode == 8 && !inputTextBlack.empty()) {
        inputTextBlack.pop_back();
    }
    _textFieldBlack->setString(inputTextBlack);
}


void ClockWidget::Update(){
    if(_data->inputManager.IsSpriteHover(_startButton, sf::Mouse::Left, _data->window)){
        _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON_HOVER"));
    } else {
        _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON"));
    }

    if(_data->inputManager.IsSpriteHover(_backgroudn_to_textFieldBlack, sf::Mouse::Left, _data->window)){
        _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_POINTED"));
    }
    else{
        _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
    }



    if (isCountdownActiveBlack) {
        sf::Time elapsed = countdownClockBlack.getElapsedTime();
        if (elapsed.asSeconds() >= 1) {
            remainingTimeInSecondsBlack -= static_cast<int>(elapsed.asSeconds());
            countdownClockBlack.restart();

            if (remainingTimeInSecondsBlack <= 0) {
                isCountdownActiveBlack = false;
                remainingTimeInSecondsBlack = 0;
                std::cout << "Koniec odliczania!" << std::endl;
            }

            // Aktualizuj tekst wyświetlany w _textField
            int minutes = remainingTimeInSecondsBlack / 60;
            int seconds = remainingTimeInSecondsBlack % 60;
            std::ostringstream timeStream;
            timeStream << std::setw(2) << std::setfill('0') << minutes << ":"
                    << std::setw(2) << std::setfill('0') << seconds;
            _textFieldBlack->setString(timeStream.str());
        }
    }
}

void ClockWidget::Draw() {


    _data->window.draw(_startButton);
    //_data->window.draw(*_backgroud_to_textField1);
    _data->window.draw(_backgroudn_to_textFieldBlack);
    _data->window.draw(*_textFieldBlack);
    _data->window.draw(*_textFieldWhite);
}




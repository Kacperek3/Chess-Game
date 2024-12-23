#include "Clock.h"

ClockWidget::ClockWidget(GameDataRef data) : _data(data) {
    
}

ClockWidget::~ClockWidget() {
    std::cout << "ClockWidget destructor" << std::endl;
    delete _textFieldBlack;
    delete _textFieldWhite;
    delete countdownClockBlack;
    delete countdownClockWhite;
}

void ClockWidget::Init() {
    _data->assetManager.LoadTexture("START_BUTTON", "../assets/GameWithFriendState/Buttons/StartButton.png");
    _data->assetManager.LoadTexture("START_BUTTON_HOVER", "../assets/GameWithFriendState/Buttons/StartButton_hover.png");
    _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON"));
    _startButton.setPosition(610, 271);
    _startButton.setScale(0.90, 0.90);

    _data->assetManager.LoadFont("Poppins", "../assets/fonts/Poppins-Thin.ttf");
    _font = _data->assetManager.GetFont("Poppins");

   
    countdownClockBlack = new sf::Clock();
    countdownClockWhite = new sf::Clock();

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
    _textFieldWhite->setPosition(665, 530);
    _textFieldWhite->setOutlineColor(sf::Color::White);
    _textFieldWhite->setOutlineThickness(1);
    _textFieldWhite->setString("00:00");
    _textFieldWhite->setStyle(sf::Text::Bold);



    _data->assetManager.LoadTexture("BACKGROUND_TO_TEXTFIELD", "../assets/TextClockBackground.png");
    _data->assetManager.LoadTexture("BACKGROUND_TO_TEXTFIELD_POINTED", "../assets/TextClockBackgroundPointed.png");
    _data->assetManager.LoadTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME", "../assets/TextClockBackgroundLowTime.png");

    _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
    _backgroudn_to_textFieldBlack.setPosition(620, 25);


    _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
    _backgroudn_to_textFieldWhite.setPosition(620, 520);
}


void ClockWidget::StartButtonPressed() {
    if(_data->inputManager.IsSpriteClicked(_backgroudn_to_textFieldBlack, sf::Mouse::Left, _data->window)){
        _whichClockPointed = BLACK;
        _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_POINTED"));
        _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
    }
    else if(_data->inputManager.IsSpriteClicked(_backgroudn_to_textFieldWhite, sf::Mouse::Left, _data->window)){
        _whichClockPointed = WHITE;
        _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_POINTED"));
        _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
    }


    if (_data->inputManager.IsSpriteClicked(_startButton, sf::Mouse::Left, _data->window)) {
        try {
            //konwertowanie czasu z inputText na int i zapisanie go w remainingTimeInSeconds
            int minutes = std::stoi(inputTextBlack.substr(0, 2));
            int seconds = std::stoi(inputTextBlack.substr(3, 2));
            remainingTimeInSecondsBlack = minutes * 60 + seconds;
            countdownClockBlack->restart();
            isCountdownActiveBlack = false;

            // to samo ale dla bialego
            minutes = std::stoi(inputTextWhite.substr(0, 2));
            seconds = std::stoi(inputTextWhite.substr(3, 2));
            remainingTimeInSecondsWhite = minutes * 60 + seconds;
            countdownClockWhite->restart();
            isCountdownActiveWhite = true;

            //Ustawienie aby na poczatku zegar bialego byl podswietlony
            _whichClockPointed = WHITE;
            _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));
            _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_POINTED"));

            _isClockTimeSet = true;
        } catch (...) {

            std::cout << "Nieprawidłowy format czasu" << std::endl;
            _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME"));
            _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME"));
            _isClockTimeSet = false;
        }
    }
}

void ClockWidget::inputTime(sf::Event event) {

    if(_whichClockPointed == BLACK){
        inputTimeBlack(event);
    }
    else if(_whichClockPointed == WHITE){
        inputTimeWhite(event);
    }
}

void ClockWidget::inputTimeBlack(sf::Event event) {
    if (std::isdigit(event.text.unicode)) {
        if(inputTextBlack.size() > 4){
            return;
        }
        inputTextBlack += static_cast<char>(event.text.unicode);
    }
    else if (event.text.unicode == 8 && !inputTextBlack.empty()) {
        inputTextBlack.pop_back();

        if(inputTextBlack.size() == 2){
            inputTextBlack.pop_back();
        }
    }


    if(inputTextBlack.size() == 2){
        inputTextBlack += ":";
    }
    _textFieldBlack->setString(inputTextBlack);
}

void ClockWidget::inputTimeWhite(sf::Event event) {
    if (std::isdigit(event.text.unicode)) {
        if(inputTextWhite.size() > 4){
            return;
        }

        inputTextWhite += static_cast<char>(event.text.unicode);
    }
    else if (event.text.unicode == 8 && !inputTextWhite.empty()) {
        inputTextWhite.pop_back();

        if(inputTextWhite.size() == 2){
            inputTextWhite.pop_back();
        }
    }

    if(inputTextWhite.size() == 2){
        inputTextWhite += ":";
    }

    _textFieldWhite->setString(inputTextWhite);
}



void ClockWidget::Update(){
    if(_data->inputManager.IsSpriteHover(_startButton, sf::Mouse::Left, _data->window)){
        _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON_HOVER"));
    } 
    else {
        _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON"));
    }

   sf::Time elapsed;

    if (isCountdownActiveBlack) {
        elapsed = countdownClockBlack->getElapsedTime();
        if (elapsed.asSeconds() >= 1) {
            remainingTimeInSecondsBlack -= static_cast<int>(elapsed.asSeconds());
            countdownClockBlack->restart();

            if (remainingTimeInSecondsBlack <= 40) {
                _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME"));
            }

            if (remainingTimeInSecondsBlack <= 0) {
                isCountdownActiveBlack = false;
                remainingTimeInSecondsBlack = 0;
                std::cout << "Koniec odliczania dla czarnego!" << std::endl;
            }

            // Aktualizuj tekst wyświetlany w _textFieldBlack
            int minutes = remainingTimeInSecondsBlack / 60;
            int seconds = remainingTimeInSecondsBlack % 60;
            std::ostringstream timeStream;
            timeStream << std::setw(2) << std::setfill('0') << minutes << ":"
                       << std::setw(2) << std::setfill('0') << seconds;
            _textFieldBlack->setString(timeStream.str());
        }
    }

    if (isCountdownActiveWhite) {
        elapsed = countdownClockWhite->getElapsedTime();
        if (elapsed.asSeconds() >= 1) {
            remainingTimeInSecondsWhite -= static_cast<int>(elapsed.asSeconds());
            countdownClockWhite->restart();

            if (remainingTimeInSecondsWhite <= 40) {
                _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME"));
            }

            if (remainingTimeInSecondsWhite <= 0) {
                isCountdownActiveWhite = false;
                remainingTimeInSecondsWhite = 0;
                std::cout << "Koniec odliczania dla białego!" << std::endl;
            }

            // Aktualizuj tekst wyświetlany w _textFieldWhite
            int minutes = remainingTimeInSecondsWhite / 60;
            int seconds = remainingTimeInSecondsWhite % 60;
            std::ostringstream timeStream;
            timeStream << std::setw(2) << std::setfill('0') << minutes << ":"
                       << std::setw(2) << std::setfill('0') << seconds;
            _textFieldWhite->setString(timeStream.str());
        }
    }
}

void ClockWidget::togglePlayerTime() {
    if (_whichClockPointed == BLACK) {
        isCountdownActiveBlack = false;
        isCountdownActiveWhite = true;

        countdownClockWhite->restart();

        _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));

        if (remainingTimeInSecondsWhite <= 40) {
            _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME"));
        } else {
            _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_POINTED"));
        }

        _whichClockPointed = WHITE;
    } 
    else if (_whichClockPointed == WHITE) {
        isCountdownActiveWhite = false;
        isCountdownActiveBlack = true;

        countdownClockBlack->restart();

        _backgroudn_to_textFieldWhite.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD"));

        if (remainingTimeInSecondsBlack <= 40) {
            _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_LOW_TIME"));
        } else {
            _backgroudn_to_textFieldBlack.setTexture(_data->assetManager.GetTexture("BACKGROUND_TO_TEXTFIELD_POINTED"));
        }

        _whichClockPointed = BLACK;
    }
}


void ClockWidget::rotatePositionClocks(){
     if (whoOnTop) {
        _backgroudn_to_textFieldWhite.setPosition(620, 25);
        _backgroudn_to_textFieldBlack.setPosition(620, 520);

        _textFieldWhite->setPosition(665, 35);
        _textFieldBlack->setPosition(665, 530);
    } else {
        _backgroudn_to_textFieldWhite.setPosition(620, 520);
        _backgroudn_to_textFieldBlack.setPosition(620, 25);

        _textFieldWhite->setPosition(665, 530);
        _textFieldBlack->setPosition(665, 35);
    }
    whoOnTop = !whoOnTop;
}



void ClockWidget::Draw() {
    _data->window.draw(_startButton);
    //_data->window.draw(*_backgroud_to_textField1);
    _data->window.draw(_backgroudn_to_textFieldBlack);
    _data->window.draw(*_textFieldBlack);

    _data->window.draw(_backgroudn_to_textFieldWhite);
    _data->window.draw(*_textFieldWhite);
}




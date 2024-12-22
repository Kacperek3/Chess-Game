#include "Clock.h"

ClockWidget::ClockWidget(GameDataRef data) : _data(data) {
    
}

void ClockWidget::Init() {
    _rec.setSize(sf::Vector2f(100, 100));
    _rec.setFillColor(sf::Color::Red);
    _rec.setPosition(100, 100);
    _rec.setOutlineColor(sf::Color::Black);

    

    _startButton.setTexture(_data->assetManager.GetTexture("START_BUTTON"));
    _startButton.setPosition(300, 271);

    _dt = 0.0f;
}

void ClockWidget::Draw() {
    _data->window.draw(_rec);
    _data->window.draw(_startButton);
}




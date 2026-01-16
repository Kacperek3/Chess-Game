#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "State.h"

class testState : public State {
public:
    testState(GameDataRef data);
    void Init() override;

    void HandleInput() override;
    void Update() override;
    void Draw() override;


private:
    GameDataRef _data;
    
    sf::Font _font;
    sf::Text _textField;
    std::string inputText = "";

    sf::RectangleShape *_rec;

   // sf::RectangleShape _rec;

    void UpdateSpriteTexture(sf::Sprite& sprite, const std::string& normalTexture, const std::string& hoverTexture);
};

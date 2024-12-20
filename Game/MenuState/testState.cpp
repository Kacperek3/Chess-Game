#include "testState.h"
#include "GameWith2State.h"
#include "MenuState.h"


testState::testState(GameDataRef data) : _data(data) {
    
}

void testState::Init(){
    _data->assetManager.LoadFont("Poppins", "../assets/fonts/Poppins-Thin.ttf");
    _font = _data->assetManager.GetFont("Poppins");

    _textField.setFont(_font);
    //std::cout << "jestem tu" << std::endl;
    _textField.setString("kacper");
    _textField.setCharacterSize(24);
    _textField.setFillColor(sf::Color::Black);
    _textField.setPosition(300, 200);
    _textField.setOutlineColor(sf::Color::White);
    _textField.setOutlineThickness(1);


    _rec = new sf::RectangleShape();
    _rec->setSize(sf::Vector2f(100, 100));
    _rec->setFillColor(sf::Color::Red);
    _rec->setPosition(100, 100);


}

void testState::HandleInput() {
    sf::Event event;
    while (_data->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _data->window.close();
            return;
        }
        if(event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::R) {
               // _data->stateManager.AddState(StateRef(new MenuState(_data)), false);
            }
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = _data->inputManager.GetMousePosition(_data->window);
            
        }
        if(event.type == sf::Event::TextEntered){
            if (std::isdigit(event.text.unicode)) {
                // Add digit to input
                inputText += static_cast<char>(event.text.unicode);
            } else if (event.text.unicode == 8 && !inputText.empty()) { // Backspace
                // Remove last character
                inputText.pop_back();
            }
            _textField.setString(inputText);
        
        }
    }
}

void testState::Update() {

}

void testState::UpdateSpriteTexture(sf::Sprite& sprite, const std::string& normalTexture, const std::string& hoverTexture) {
    if (_data->inputManager.IsSpriteHover(sprite, sf::Mouse::Left, _data->window)) {
        sprite.setTexture(_data->assetManager.GetTexture(hoverTexture));
    } else {
        sprite.setTexture(_data->assetManager.GetTexture(normalTexture));
    }
}


void testState::Draw() {
    _data->window.clear();


    
    _data->window.draw(*_rec);

    _data->window.draw(_textField);


    _data->window.display();
}
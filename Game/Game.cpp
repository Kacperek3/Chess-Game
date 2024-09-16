#include "Game.h"

Game::Game() 
: window(sf::VideoMode(800, 800), "Szachy"), board() {
    // Inicjalizacja innych elementów, jeśli potrzeba
}

void Game::run() {
    // Główna pętla gry
    while (window.isOpen()) {
        processEvents();  // Przetwarzanie zdarzeń
        update();         // Aktualizacja stanu gry
        render();         // Renderowanie gry
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            // Można dodać więcej zdarzeń np. obsługę ruchu pionków, kliknięcia
        }
    }
}

void Game::update() {
    // Logika gry np. sprawdzanie ruchów, zmiana tur, AI itp.
}

void Game::render() {
    window.clear();

    // Rysowanie planszy i elementów gry
    board.draw(window);

    window.display();
}

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Wyświetlanie grafiki");

    sf::Texture texture;
    if (!texture.loadFromFile("/home/kacper/Pulpit/chess/assets/pieces/wRock.png")) {
        return -1; // Obsłuż błąd
    }

    sf::Sprite sprite(texture);

    // Ustawienie koloru tła na jasnozielony
    sf::Color lightGreen(144, 238, 144); // RGB dla jasnozielonego koloru

    bool isDragging = false; // Czy obiekt jest przeciągany

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (sprite.getGlobalBounds().contains(window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y}))) {
                            isDragging = true;
                        }
                    }
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        isDragging = false;
                    }
                    break;
                case sf::Event::MouseMoved:
                    if (isDragging) {
                        sprite.setPosition(window.mapPixelToCoords({event.mouseMove.x-26, event.mouseMove.y-22}));
                    }
                    break;
            }
        }

        window.clear(lightGreen); // Użyj jasnozielonego koloru jako tła
        window.draw(sprite);
        window.display();
    }

    return 0;
}
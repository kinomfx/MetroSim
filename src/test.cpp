#include <SFML/Graphics.hpp>

int testmain() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Metro Sim");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}

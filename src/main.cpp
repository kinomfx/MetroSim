#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Station class representing each metro station
class Station {
public:
    std::string name;
    sf::Vector2f position;
    sf::CircleShape shape;

    Station(const std::string& name, float x, float y) 
        : name(name), position(x, y) 
    {
        shape.setRadius(10);
        shape.setFillColor(sf::Color::Blue);
        shape.setOrigin(10, 10); // Center the circle
        shape.setPosition(position);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Delhi Metro Visualizer");

    // Hardcoded stations
    std::vector<Station> stations = {
        Station("Dwarka Sector 21", 100, 100),
        Station("Dwarka Sector 8", 200, 150),
        Station("Dwarka Sector 9", 300, 200),
        Station("Dwarka Sector 10", 400, 250),
        Station("Dwarka Sector 11", 500, 300)
    };

    // Main render loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Draw lines between stations (simple sequential connection for now)
        for (size_t i = 1; i < stations.size(); ++i) {
            sf::Vertex line[] = {
                sf::Vertex(stations[i - 1].position, sf::Color::Black),
                sf::Vertex(stations[i].position, sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
        }

        // Draw each station
        for (auto& station : stations) {
            station.draw(window);
        }

        window.display();
    }

    return 0;
}

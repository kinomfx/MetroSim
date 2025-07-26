// Passenger.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Passenger {
public:
    std::string from, to;
    sf::Vector2f position;
    bool onboard;

    Passenger(std::string from, std::string to);
    void draw(sf::RenderWindow &window);
};

// Station.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Station {
public:
    std::string name;
    sf::Vector2f position;
    int passengerCount = 0;

    Station(std::string name, sf::Vector2f pos);
    void draw(sf::RenderWindow &window);
};

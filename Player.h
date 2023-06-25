#pragma once

#include "Entities.h"
#include <SFML/Graphics.hpp>



class Player :public Entity{
private:
    sf::RectangleShape player;
public:
    explicit Player(int hp_);
    void movement(int sens) override;
    void draw(sf::RenderWindow &window) override;
    sf::Vector2f get_x_y() override;
    void setStarter(sf::Vector2f size, sf::Vector2f position) override;
    void setTexture(sf::Texture &help) override;

};



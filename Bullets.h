//
// Created by Iulian on 5/18/2023.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Entities.h"

class Bullet: public Entity
        {
private:
    sf::RectangleShape bullet;
    int speed;
public:
    Bullet(int speed_, int hp_);


    void movement(int sens) override;
    void draw(sf::RenderWindow &window) override;
    sf::Vector2f get_x_y() override;
    void setStarter(sf::Vector2f size, sf::Vector2f position) override;
    void setTexture(sf::Texture &help) override;

};


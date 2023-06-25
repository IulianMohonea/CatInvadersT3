#ifndef TEMA_2_ENTITIES_H
#define TEMA_2_ENTITIES_H
#pragma once
#include <SFML/Graphics.hpp>
class Entity {
private:

    int hp;

public:
    explicit Entity(int hp_);
    void hit();
    [[nodiscard]] int get_hp()const;
    virtual void setStarter(sf::Vector2f size, sf::Vector2f position) = 0;
    virtual void movement(int x) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual sf::Vector2f get_x_y() = 0;
    virtual void setTexture(sf::Texture &help) = 0;
};



#endif //TEMA_2_ENTITIES_H

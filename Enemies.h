
#pragma once
#include "Entities.h"
#include <SFML/Graphics.hpp>
class Enemy: public Entity
{
private:
    sf::RectangleShape enemy;
    int speed;
    static char inline mes[50] = "An enemy has just died";
public:
    Enemy(int hp_, int speed);
    void changeway();
    static void enemyDead();

    // Factory style
    static Enemy normalEnemy();
    //
    /*
    void increaseSpeed();
     */
    void movement(int sens) override;
    void draw(sf::RenderWindow &window) override;
    sf::Vector2f get_x_y() override;
    void setStarter(sf::Vector2f size, sf::Vector2f position) override;
    void setTexture(sf::Texture &help) override;
};


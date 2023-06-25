
#include "Enemies.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Enemy ::Enemy(int hp_, int speed_): Entity(hp_),  speed(speed_){

}
Enemy Enemy:: normalEnemy() { return Enemy(1,2); }


void Enemy::setStarter(sf::Vector2f size, sf::Vector2f position) {

    enemy.setSize(size);
    enemy.setPosition(position);
}
void Enemy::draw(sf::RenderWindow &window) {

    window.draw(enemy);
}
void Enemy::changeway() {
    enemy.move(0,50);
}
void Enemy::movement(int sens) {

    if(sens != 0) {
        enemy.move(speed * sens, 0);
    }
    else{
        changeway();
    }

}
sf::Vector2f Enemy::get_x_y() {
    return enemy.getPosition();
}
void Enemy::setTexture(sf::Texture &help) {
    enemy.setTexture(&help);
}
/*
void Enemy::increaseSpeed() {
    speed += 2;
}
 */
void Enemy::enemyDead(){
    std::cout<< mes << '\n';
}



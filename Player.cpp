
#include "Player.h"

#include <SFML/Graphics.hpp>
#include "Errors.h"

Player::Player(int hp_): Entity(hp_){

}

void Player::setStarter(sf::Vector2f size, sf::Vector2f position) {

    player.setSize(size);
    player.setPosition(position);
}
void Player::draw(sf::RenderWindow &window) {

    window.draw(player);
}
void Player::setTexture(sf::Texture &help) {
    player.setTexture(&help);
}
sf::Vector2f Player::get_x_y() {
    return player.getPosition();
}
void Player::movement(int sens) {
    sf::Vector2f helper;
    helper = get_x_y();
    if(sens == 1) {
        if (helper.x <= 900)
            player.move(10, 0);
    }
    else {
        if (helper.x >= 0)
            player.move(-10, 0);
    }
}


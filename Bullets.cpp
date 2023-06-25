#include "Bullets.h"

Bullet::Bullet(int speed_, int hp_):Entity(hp_), speed{speed_}{

}

void Bullet::movement(int sens) {
    bullet.move(0, sens*speed);
}

sf::Vector2f Bullet::get_x_y(){
    return bullet.getPosition();
}

void Bullet::draw(sf::RenderWindow &window) {
    window.draw(bullet);
}

void Bullet::setStarter(sf::Vector2f size, sf::Vector2f position) {

    bullet.setSize(size);
    bullet.setPosition(position);
}
void Bullet::setTexture(sf::Texture &help){
    bullet.setTexture(&help);

}


#include "Timer.h"
#include "Game.h"
#include "Player.h"
#include "Enemies.h"
#include "Bullets.h"
#include "Errors.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


void Game::prepareGame() {
    initiateEnemies();
    initiatePlayer();
    putBackground();
}

sf::RectangleShape Game::putBackground() {
    sf::Texture backkground;
    backkground.loadFromFile("finalback.png");
    sf::Vector2f backgroundsize(1000.0f, 1000.0f);
    sf::RectangleShape background(backgroundsize);
    background.setTexture(&backkground);
    return background;
}
void Game::initiatePlayer() {
    sf::Texture playerTexture;
    playerTexture.loadFromFile("test.png");

    sf::Vector2f playerposition(450, 900);
    sf::Vector2f playersize(100.0f, 100.0f);

    me->setTexture(playerTexture);
    me->setStarter(playersize,playerposition);
}

void Game::initiateBullets(){

    sf::Vector2f bulletsize(10,50);
    sf::Vector2f playerposition;
    playerposition = me->get_x_y();
    auto* newBullet = new Bullet(3,1);
    newBullet->setStarter(bulletsize,playerposition);
    bulletVec.push_back(newBullet);
}

void Game::initiateEnemies() {
    float actualx = 125;
    float actualy = 50;
    sf::Texture enemyPhoto;
    enemyPhoto.loadFromFile("mouse00.png");
    sf::Vector2f enemySize (50,50);
    for( int i = 0; i < 3; i++)
    {
        for ( int j = 0; j <= 10; j++)
        {
            Enemy e = Enemy::normalEnemy();
            Entity* newenemy = new Enemy(e);
            sf::Vector2f enemyPosition(actualx,actualy);
            newenemy->setStarter(enemySize,enemyPosition);
            enemyVec.push_back(newenemy);


            actualx += 75;

        }
        actualy +=75;
        actualx = 125;
    }
}

void Game::timediff(float dt, float lf){
    if(dt - lf <= 0.3) {
        std::string mesajj;
        mesajj = std::to_string(dt - lf);
        throw fireErrors(mesajj);
    }

}
void Game::allowedMove(int sens){
    if(me->get_x_y().x <= 3 and sens == -1)
    {
        std::string mesajj = "Esti prea la stanga!!";
        throw playerErrors(mesajj);
    }
    else if (me->get_x_y().x >= 900 and sens == 1)
    {
        std::string mesajj = "Esti prea la dreapta!!";
        throw playerErrors(mesajj);
    }
    me->movement(sens);
}
void Game::startGame(){
    prepareGame();
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Window", sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(60);


    sf::Texture playerTexture;
    playerTexture.loadFromFile("test.png");

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Texture bulletTexture;
    bulletTexture.loadFromFile("bullet.png");


    sf::Texture backkground;
    backkground.loadFromFile("finalback.png");
    sf::Vector2f backgroundsize(1000.0f, 1000.0f);
    sf::RectangleShape background(backgroundsize);
    background.setTexture(&backkground);



    sf::Texture enemyPhoto;
    enemyPhoto.loadFromFile("mouse00.png");


    std::string help;
    bool isFiring = false;
    float lastFired = -1;
    int sens = 1;
    int ver = 1;
    int state = 1;
    sf:: Clock dtClock;
    float dt = 0;

    //Class template pt Timer
    Timer<float>realtime(0.0f);



    // Buttons play/exit start
    sf::RectangleShape playButton(sf::Vector2f(200, 50));
    playButton.setPosition(300, 200);
    playButton.setFillColor(sf::Color::Green);

    // Create the "Exit" button
    sf::RectangleShape exitButton(sf::Vector2f(200, 50));
    exitButton.setPosition(300, 300);
    exitButton.setFillColor(sf::Color::Red);
    // Buttons fin

    // MainMenu fin

    while (window.isOpen()) {
        if (state == 1 and dt < 1000) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                // Check if the "Play" button is clicked
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (playButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // Action to perform when "Play" button is clicked
                        state = 2;
                        dt = dtClock.getElapsedTime().asSeconds();
                        realtime.set_time(dt);
                    }
                    else if (exitButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // Action to perform when "Exit" button is clicked
                        window.close();
                    }
                }

            }

            window.clear();
            window.draw(playButton);
            window.draw(exitButton);
            window.display();
        } else if(state == 2 and dt < 1000){


            sf::Event eve{};
            while (window.pollEvent(eve)) {

                switch (eve.type) {

                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        break;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    isFiring = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    try{
                        allowedMove(-1);
                    }catch(playerErrors& err){
                        std:: cout<< "Player movement error: " <<err.what() << '\n';
                    }
                    me->movement(-1);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    try{
                        allowedMove(1);
                    }catch(playerErrors& err){
                        std:: cout<< "Player movement error: " <<err.what() << '\n';
                    }
                    me->movement(1);
                }
                if (enemyVec.empty()){
                    window.close();
                }
                if(enemyVec[0]->get_x_y().y >= 900){
                    window.close();
                }
            }
            window.clear(sf::Color::Black);
            window.draw(background);
            // Delta time start
            dt = dtClock.getElapsedTime().asSeconds();
            // Delta time fin

            //Bullets start

            if (isFiring) {
                int hh = 0;
                try{
                    timediff(dt,lastFired);
                }catch(fireErrors& err){
                    std:: cout<< "bullets error: " <<err.what() << '\n';
                    hh = 1;
                }
                if(hh == 0) {
                    initiateBullets();
                    lastFired = dt;
                }
                isFiring = false;
            }

            for (auto & i : bulletVec) {
                if(i->get_hp() > 0){
                    i->movement(-1);
                    i->setTexture(bulletTexture);
                    i->draw(window);
                }


            }

            // Bullets fin
            for(auto &i:enemyVec){
                float helpo = i->get_x_y().x;
                if(helpo <= 3) {
                    sens *= -1;
                    ver = 0;
                    break;
                }
                else if(helpo >= 950) {
                    sens *= -1;
                    ver = 0;
                    break;
                }
            }
            if(ver == 0)
            {
                for(auto &i :enemyVec){
                    i->movement(ver);
                }
            }
            ver = 1;
            for (auto & i : enemyVec) {

                i->movement(sens);
                i->setTexture(enemyPhoto);
                i->draw(window);

            }
            sf::Vector2f enemyPos;
            sf::Vector2f bulletPos;
            for(size_t i = 0;i < bulletVec.size();i++)
            {
                if(bulletVec[i]->get_x_y().y <= 0) {
                    bulletVec.erase(bulletVec.begin() + i);
                }
            }
            for(size_t j = 0;j < bulletVec.size();j++){
                bulletPos = bulletVec[j]->get_x_y();


                    for (size_t i = 0; i < enemyVec.size(); i++) {
                        enemyPos = enemyVec[i]->get_x_y();

                        if (bulletPos.x <= enemyPos.x + 50 and bulletPos.x + 10 >= enemyPos.x and
                            bulletPos.y < enemyPos.y + 50 and bulletPos.y + 50 >= enemyPos.y) {

                            bulletVec[j]->hit();
                            try {
                                auto *pointerEnemy = dynamic_cast<Enemy *>(bulletVec[j]);
                                pointerEnemy->enemyDead();
                            } catch (std::bad_cast &err) {
                                std::cout << "err: " << err.what() << "\n";
                            }
                            bulletVec.erase(bulletVec.begin() + j);
                            enemyVec[i]->hit();
                            enemyVec.erase(enemyVec.begin() + i);
                        }

                }
            }



            // time


            // dt //

            float realbro;

            realbro = dt - realtime.get_time();





            sf::Text text;
            text.setFont(font); // font is a sf::Font
            help = std::to_string(realbro);

            text.setString(help);

            text.setCharacterSize(24); // in pixels, not points!
            text.setFillColor(sf::Color::Green);
            //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text.setPosition(800, 25);
            window.draw(text);
            // time

            me->setTexture(playerTexture);
            me->draw( window);

            window.display();
        }

    }
    std::destroy(enemyVec.begin(), enemyVec.end());
    std::destroy(bulletVec.begin(), bulletVec.end());
}

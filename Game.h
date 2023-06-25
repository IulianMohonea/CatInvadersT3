
#ifndef TEMA_2_GAME_H
#define TEMA_2_GAME_H
#include "Player.h"
#include "Enemies.h"
#include "Bullets.h"
#include "Timer.h"

class Game {
private:
    Game() = default;

    Entity* me = new Player(3);
    std::vector<Entity*> enemyVec;
    std::vector<Entity*> bulletVec;
public:
    // Singleton
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game& get_app() {
        static Game app;
        app.startGame();
        return app;
    }

    void startGame();
    void initiatePlayer();
    static sf::RectangleShape putBackground();
    void initiateBullets();
    void initiateEnemies();
    void prepareGame();
    static void timediff(float dt,float lf);
    void allowedMove(int sens);
};


#endif //TEMA_2_GAME_H

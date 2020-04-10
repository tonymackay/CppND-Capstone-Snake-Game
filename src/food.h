#ifndef FOOD_H
#define FOOD_H

#include "game_object.h"
#include "snake.h"
#include <random>

class Food : public GameObject
{
public:
    Food(std::shared_ptr<Snake> snake);
    virtual void Update();
    virtual void Render(SDL_Renderer* renderer);
private:
    std::shared_ptr<Snake> _snake;
    void PlaceFood();

    std::random_device _dev;
    std::mt19937 _engine;
    std::uniform_int_distribution<int> _random_w;
    std::uniform_int_distribution<int> _random_h;
};

#endif
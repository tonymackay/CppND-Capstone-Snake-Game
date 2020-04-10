#ifndef SNAKE_H
#define SNAKE_H

#include "game_object.h"
#include "score.h"
#include <vector>

class Snake : public GameObject
{
public:
    Snake(std::shared_ptr<Score> score);
    virtual void Update();
    virtual void Render(SDL_Renderer* renderer);
    void HandleInput(const SDL_Keycode& input);
    enum class Direction { Up, Down, Left, Right };
    bool SnakeCell(int x, int y);
    void GrowBody();
private:
    std::shared_ptr<Score> _score;
    bool _growing{false};
    bool _alive{true};
    float _speed{0.1f};
    int _size{1};
    std::vector<SDL_Point> _body{};
    Direction _direction{Direction::Up};

    void ChangeDirection(Direction input, Direction opposite);
    void UpdateHead();
    void UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell);
};

#endif
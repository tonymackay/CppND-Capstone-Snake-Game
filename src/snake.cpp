#include "snake.h"
#include <iostream>

Snake::Snake(std::shared_ptr<Score> score) : _score(score)
{
    X = 16;
    Y = 16;
}

void Snake::Update()
{
    if (!_alive)
        return;

    // We first capture the head's cell before updating.
    SDL_Point prev_cell{static_cast<int>(X), static_cast<int>(Y)};

    UpdateHead();

    // Capture the head's cell after updating.
    SDL_Point current_cell{static_cast<int>(X), static_cast<int>(Y)};

    // Update all of the body vector items if the snake head has moved to a new
    // cell.
    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
    {
        UpdateBody(current_cell, prev_cell);
    }
}

void Snake::UpdateHead()
{
    switch (_direction)
    {
    case Direction::Up:
        Y -= _speed;
        break;

    case Direction::Down:
        Y += _speed;
        break;

    case Direction::Left:
        X -= _speed;
        break;

    case Direction::Right:
        X += _speed;
        break;
    }

    // Wrap the Snake around to the beginning if going off of the screen.
    X = fmod(X + 32, 32);
    Y = fmod(Y + 32, 32);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
    // Add previous head location to vector
    _body.push_back(prev_head_cell);

    if (!_growing)
    {
        // Remove the tail from the vector.
        _body.erase(_body.begin());
    }
    else
    {
        _growing = false;
        _size++;
    }

    // Check if the snake has died.
    for (auto const &item : _body)
    {
        if (current_head_cell.x == item.x && current_head_cell.y == item.y)
        {
            _alive = false;
        }
    }
}

void Snake::Render(SDL_Renderer *renderer)
{
    SDL_Rect block;
    block.w = 640 / 32; // screen / grid
    block.h = 640 / 32;

    // Render snake's body
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (SDL_Point const &point : _body)
    {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(X) * block.w;
    block.y = static_cast<int>(Y) * block.h;

    if (_alive)
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x7A, 0xCC, 0xFF);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(renderer, &block);
}

void Snake::HandleInput(const SDL_Keycode &input)
{
    switch (input)
    {
    case SDLK_UP:
        ChangeDirection(Direction::Up, Direction::Down);
        break;
    case SDLK_DOWN:
        ChangeDirection(Direction::Down, Direction::Up);
        break;
    case SDLK_LEFT:
        ChangeDirection(Direction::Left, Direction::Right);
        break;
    case SDLK_RIGHT:
        ChangeDirection(Direction::Right, Direction::Left);
        break;
    default:
        break;
    }
}

void Snake::ChangeDirection(Direction input, Direction opposite)
{
    if (_direction != opposite || _size == 1)
    {
        _direction = input;
    }
}

bool Snake::SnakeCell(int x, int y)
{
    if (x == static_cast<int>(X) && y == static_cast<int>(Y))
    {
        return true;
    }
    for (auto const &item : _body)
    {
        if (x == item.x && y == item.y)
        {
            return true;
        }
    }
    return false;
}

void Snake::GrowBody()
{
    _score->Increase();
    _growing = true;
    _speed += 0.02;
}
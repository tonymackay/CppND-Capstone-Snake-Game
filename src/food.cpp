#include "food.h"

Food::Food(std::shared_ptr<Snake> snake) : _snake(snake),
                                           _engine(_dev()),
                                           _random_w(0, 31),
                                           _random_h(0, 31)
{
    PlaceFood();
}

void Food::Update()
{
    int new_x = static_cast<int>(_snake->X);
    int new_y = static_cast<int>(_snake->Y);

    if (X == new_x && Y == new_y)
    {
        _snake->GrowBody();
        PlaceFood();
    }
}

void Food::Render(SDL_Renderer *renderer)
{
    SDL_Rect block;
    block.w = 640 / 32; // screen / grid
    block.h = 640 / 32;

    // Render food
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xCC, 0x00, 0xFF);
    block.x = X * block.w;
    block.y = Y * block.h;
    SDL_RenderFillRect(renderer, &block);
}

void Food::PlaceFood()
{
    int x, y;
    while (true)
    {
        x = _random_w(_engine);
        y = _random_h(_engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!_snake->SnakeCell(x, y))
        {
            X = x;
            Y = y;
            return;
        }
    }
}
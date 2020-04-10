#include "sdl_w.h"
#include "game.h"
#include "snake.h"
#include "score.h"
#include "food.h"
#include <iostream>

int main()
{
    sdlw::Init();
    {
        auto score = std::make_shared<Score>();
        auto snake = std::make_shared<Snake>(score);
        auto food = std::make_shared<Food>(snake);

        Game game{640, 640};

        game.GetScene().AddObject(snake);
        game.GetScene().AddObject(food);
        game.GetScene().AddObject(score);

        game.OnKeyDown(
            [&](SDL_Keycode key) {
                if (key == SDLK_ESCAPE)
                    game.Quit();

                if (key == SDLK_SPACE)
                    game.PauseUnpause();

                if (!game.Paused())
                    snake->HandleInput(key);
            });

        game.Run(1000 / 60);
    }
    sdlw::Quit();
    return 0;
}
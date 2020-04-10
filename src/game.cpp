#include "game.h"
#include "scene.h"
#include "snake.h"
#include "food.h"
#include "score.h"
#include <iostream>

Game::Game(int screen_w, int screen_h)
{
    _window = sdlw::CreateWindow(
        "Snake Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screen_w,
        screen_h,
        SDL_WINDOW_SHOWN
    );

    if (_window.get() == nullptr)
    {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    _renderer = sdlw::CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED);

    if (_renderer.get() == nullptr)
    {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
        return;
    }
}

Game::~Game()
{
}

void Game::Run(Uint32 target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    _running = true;

    while (_running)
    {
        frame_start = SDL_GetTicks();

        // handle input (only send to snake when playing)
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                Quit();
            }
            if (e.type == SDL_KEYDOWN)
            {
                for(auto c : _input)
                {
                    c(e.key.keysym.sym);
                }
            }
        }

        // update all game objects here
        if (!_paused)
        {
            _scene.Update();
        }

        _scene.Render(_renderer.get());

        // time since work done
        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            if (_paused)
            {
                std::string title{"PAUSED - FPS: " + std::to_string(frame_count)};
                SDL_SetWindowTitle(_window.get(), title.c_str());
            }
            else
            {
                std::string title{"PLAYING - FPS: " + std::to_string(frame_count)};
                SDL_SetWindowTitle(_window.get(), title.c_str());
            }
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::Quit()
{
    _running = false;
}

void Game::OnKeyDown(std::function<void(int)> f)
{
    _input.push_back(f);
}

Scene& Game::GetScene()
{
    return _scene;
}

bool Game::Paused() const 
{
    return _paused;
}

void Game::PauseUnpause()
{
    _paused = _paused = !_paused;
}
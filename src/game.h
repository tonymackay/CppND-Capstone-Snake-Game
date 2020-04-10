#ifndef GAME_H
#define GAME_H

#include "sdl_w.h"
#include "scene.h"
#include <memory>
#include <functional>
#include <vector>

class Game
{
public:
  Game(int screen_w, int screen_h);
  ~Game();
  void Run(Uint32 target_frame_duration);
  void Quit();
  void OnKeyDown(std::function<void(SDL_Keycode)> f);
  Scene& GetScene();
  bool Paused() const;
  void PauseUnpause();

private:
  Scene _scene{};
  bool _paused{false};
  bool _running{false};
  std::unique_ptr<SDL_Window, sdlw::SDL_Deleter> _window;
  std::unique_ptr<SDL_Renderer, sdlw::SDL_Deleter> _renderer;
  std::vector<std::function<void(SDL_Keycode)>> _input{};
};

#endif
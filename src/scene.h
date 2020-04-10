#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"
#include "game_object.h"
#include <vector>
#include <memory>

class Scene
{
public:
    void Update();
    void Render(SDL_Renderer* renderer);
    void AddObject(std::shared_ptr<GameObject> object);

private:
    std::vector<std::shared_ptr<GameObject>> _objects{};
};

#endif
#include "scene.h"
#include <iostream>

void Scene::Update()
{
    for (auto &obj : _objects)
    {
        obj->Update();
    }
}

void Scene::AddObject(std::shared_ptr<GameObject> object)
{
    _objects.push_back(object);
}

void Scene::Render(SDL_Renderer *renderer)
{
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(renderer);

    for (auto &obj : _objects)
    {
        obj->Render(renderer);
    }

    // Update Screen
    SDL_RenderPresent(renderer);
}
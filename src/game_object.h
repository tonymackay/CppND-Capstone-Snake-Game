#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SDL.h"

class GameObject
{
public:
    float X, Y;
    int Width, Height;
    virtual ~GameObject() = default;
    virtual void Update() = 0;
    virtual void Render(SDL_Renderer* renderer) = 0;
};

#endif
#include "sdl_w.h"
#include <iostream>

using sdlw::SDL_Deleter;

bool sdlw::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }

    if (TTF_Init() != 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
        return false;
    }

    return true;
}

void sdlw::Quit()
{
    TTF_Quit();
    SDL_Quit();
}

std::unique_ptr<SDL_Window, SDL_Deleter> sdlw::CreateWindow(std::string title, int x, int y, int w, int h, Uint32 flags)
{
    return std::unique_ptr<SDL_Window, SDL_Deleter>(SDL_CreateWindow(
        title.c_str(), x, y, w, h, flags));
}

std::unique_ptr<SDL_Renderer, SDL_Deleter> sdlw::CreateRenderer(SDL_Window *window, int index, Uint32 flags)
{
    return std::unique_ptr<SDL_Renderer, SDL_Deleter>(SDL_CreateRenderer(window, index, flags));
}

std::unique_ptr<TTF_Font, SDL_Deleter> sdlw::OpenFont(std::string path, int size)
{
    return std::unique_ptr<TTF_Font, SDL_Deleter>(
        TTF_OpenFont(path.c_str(), size));
}

std::unique_ptr<SDL_Surface, SDL_Deleter> sdlw::RenderTextBlended(TTF_Font *font, std::string text, SDL_Color color)
{
    return std::unique_ptr<SDL_Surface, SDL_Deleter>(
        TTF_RenderText_Blended(font, text.c_str(), color));
}

std::unique_ptr<SDL_Texture, SDL_Deleter> sdlw::CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    return std::unique_ptr<SDL_Texture, SDL_Deleter>(
        SDL_CreateTextureFromSurface(renderer, surface));
}
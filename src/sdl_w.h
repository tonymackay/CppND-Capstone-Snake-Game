#ifndef SDL_W_H
#define SDL_W_H

#include "SDL.h"
#include "SDL_ttf.h"
#include <memory>
#include <string>
#include <stdint.h>
#include <stdlib.h>

namespace sdlw
{
struct SDL_Deleter
{
    void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
    void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
    void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
    void operator()(SDL_Surface *p) const { SDL_FreeSurface(p); }
    void operator()(TTF_Font *p) const { TTF_CloseFont(p); }
};

bool Init();
void Quit();
std::unique_ptr<SDL_Window, SDL_Deleter> CreateWindow(std::string title, int x, int y, int w, int h, Uint32 flags);
std::unique_ptr<SDL_Renderer, SDL_Deleter> CreateRenderer(SDL_Window *window, int index, Uint32 flags);
std::unique_ptr<TTF_Font, SDL_Deleter> OpenFont(std::string path, int size);
std::unique_ptr<SDL_Surface, SDL_Deleter> RenderTextBlended(TTF_Font *font, std::string text, SDL_Color color);
std::unique_ptr<SDL_Texture, SDL_Deleter> CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);

} // namespace sdlw
#endif


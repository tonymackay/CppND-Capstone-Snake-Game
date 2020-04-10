#ifndef SCORE_H
#define SCORE_H

#include "game_object.h"
#include "sdl_w.h"
#include <string>

class Score : public GameObject
{
public:
    Score();
    ~Score();
    virtual void Update();
    virtual void Render(SDL_Renderer* renderer);
    void Increase();
    int GetScore() const;
    int GetHighScore() const;
private:
    int _score{0};
    int _high_score{0};
    std::unique_ptr<TTF_Font, sdlw::SDL_Deleter> _font;
    void DrawText(SDL_Renderer* renderer, std::string text, int x, int y);
};

#endif
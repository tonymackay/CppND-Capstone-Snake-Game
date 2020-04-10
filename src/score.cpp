#include "score.h"
#include <fstream>
#include <sstream>

Score::Score()
{
    _font = sdlw::OpenFont("Verdana.ttf", 20);

    std::ifstream file_stream("scores.txt");
    if (file_stream.is_open()) {
        std::string line, key, high_score;
        while (std::getline(file_stream, line)) {
          std::istringstream string_stream(line);
          while (string_stream >> key >> high_score) {
            if (key == "HighScore:") {
              _high_score = std::stoi(high_score);
            }
          }
        }
    }
}

Score::~Score()
{
    std::ofstream file_stream("scores.txt");
    if (file_stream.is_open())
    {
        file_stream << "HighScore: " << std::to_string(_high_score) << std::endl;
    }
    file_stream.close();
}

void Score::Update()
{
}

void Score::Render(SDL_Renderer *renderer)
{
    DrawText(renderer, "Score: " + std::to_string(_score), 5, 1);
    DrawText(renderer, "High Score: " + std::to_string(_high_score), 5, 25);
}

void Score::Increase()
{
    _score++;
    if (_score >= _high_score)
    {
        _high_score = _score;
    }
}

int Score::GetScore() const
{
    return _score;
}

int Score::GetHighScore() const
{
    return _high_score;
}

void Score::DrawText(SDL_Renderer *renderer, std::string text, int x, int y)
{
    SDL_Color color = {255, 255, 255, 255};

    auto surface = sdlw::RenderTextBlended(_font.get(), text, color);
    auto texture = sdlw::CreateTextureFromSurface(renderer, surface.get());

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;

    SDL_QueryTexture(texture.get(), NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture.get(), NULL, &rect);
}
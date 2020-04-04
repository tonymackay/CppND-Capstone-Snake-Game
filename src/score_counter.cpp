#include "score_counter.h"
#include <fstream>
#include <string>
#include <sstream>

ScoreCounter::ScoreCounter()
{
    Load();
}

ScoreCounter::~ScoreCounter()
{
    Save();
}

int ScoreCounter::Score() const
{
    return _score;
}

int ScoreCounter::HighScore() const
{
    return _high_score;
}

void ScoreCounter::IncreaseScore()
{
    _score++;
    if (_score >= _high_score)
    {
        _high_score = _score;
    }
}

void ScoreCounter::Save()
{
    std::ofstream file_stream("scores.txt");
    if (file_stream.is_open()) {
        file_stream << "HighScore: " << std::to_string(_high_score) << std::endl;
    }
    file_stream.close();
}

void ScoreCounter::Load()
{
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
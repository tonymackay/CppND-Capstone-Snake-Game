#include "score_counter.h"

int ScoreCounter::Score() const {
    return _score;
}

int ScoreCounter::HighScore() const {
    return _high_score;
}

void ScoreCounter::IncreaseScore() {
    _score++;
    if (_score >= _high_score) {
        _high_score = _score;
    }
}
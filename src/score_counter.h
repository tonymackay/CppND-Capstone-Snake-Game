#ifndef SCORE_COUNTER_H
#define SCORE_COUNTER_H

class ScoreCounter
{
public:
  int Score() const;
  int HighScore() const;
  void IncreaseScore();
  
private:
  int _score{0};
  int _high_score{0}; 
};

#endif
#pragma once

class Player {
public:
  Player(int x = 0, int y = 0, int score = 0) : x{x}, y{y}, score{score} {}
  ~Player() {}

  void setX(const int val) { x = val; }
  int getX() const { return x; }
  void setY(const int val) { y = val; }
  int getY() const { return y; }
  void setScore(const int val) { score = val; }
  int getScore() const { return score; }

private:
  int x, y, score;
};
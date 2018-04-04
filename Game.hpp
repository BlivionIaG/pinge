#pragma once

#include "Ball.hpp"
#include "Player.hpp"

class Game {
public:
  Game(int width, int height)
      : width{width}, height{height}, ball{(int)width / 4, (int)height / 4,
                                           (int)height / 12, 5},
        one{10, (int)height / 2}, two{width - 10, (int)height / 2} {}
  ~Game() {}

  void setWidth(const int val) { width = val; }
  void setHeight(const int val) { height = val; }

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  Ball &getBall() { return ball; }
  Player &getPlayerOne() { return one; }
  Player &getPlayerTwo() { return two; }

  void moveBall();

private:
  int width, height;
  Ball ball;
  Player one, two;
};
#ifndef PINGE_GAME_HPP
#define PINGE_GAME_HPP

#include "Entity.hpp"
#include <cmath>
#include <iostream>

class Game {
public:
  Game(int width, int height)
      : width{width}, height{height}, ball{(int)width / 2, (int)height / 2,
                                           (int)height / 16, (int)height / 16,
                                           5},
        one{10, (int)height / 2, 20, 100, 10},
        two{width - 30, (int)height / 2, 20, 100, 10}, paused{true} {}
  ~Game() {}

  void setWidth(const int val) { width = val; }
  void setHeight(const int val) { height = val; }

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  Entity &getBall() { return ball; }
  Entity &getPlayerOne() { return one; }
  Entity &getPlayerTwo() { return two; }

  bool isPaused() const { return paused; }
  void togglePause() { paused = !paused; }

  void moveBall();
  void movePlayerOne();
  void movePlayerTwo();

  void keepIn(int x0, int y0, int x1, int y1);
  template <typename T> void collide(T x0, T y0, T x1, T y1);

  template <typename T> T max(T a, T b) { return (a > b) ? a : b; }
  template <typename T> T min(T a, T b) { return (a < b) ? a : b; }

private:
  int width, height;
  Entity ball, one, two;
  bool paused;
};

#endif /* PINGE_GAME_HPP */
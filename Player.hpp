#pragma once

class Player {
public:
  Player(int x = 0, int y = 0, int width = 20, int height = 100, int speed = 1,
         int score = 0)
      : x{x}, y{y}, width{width}, height{height}, speed{speed}, score{score} {
    dx = dy = -1;
  }
  ~Player() {}

  void setX(const int val) { x = val; }
  int getX() const { return x; }
  void setY(const int val) { y = val; }
  int getY() const { return y; }
  void setScore(const int val) { score = val; }
  int getScore() const { return score; }
  void setWidth(const int val) { width = val; }
  void setHeight(const int val) { height = val; }

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void setSpeed(const int val) { speed = val; }
  int getSpeed() const { return speed; }

  void setDY(const int val) { dy = val; }
  void setDX(const int val) { dx = val; }
  int getDX() const { return dx; }
  int getDY() const { return dy; }
  void toggleDX() { dx = -dx; }
  void toggleDY() { dy = -dy; }

private:
  int x, y, width, height, speed, score, dx, dy;
};
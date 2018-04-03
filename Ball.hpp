#pragma once

class Ball {
public:
  Ball(int x = 0, int y = 0, int speed = 1) : x{x}, y{y}, speed{speed} {}
  ~Ball() {}

  void setX(const int val) { x = val; }
  int getX() const { return x; }
  void setY(const int val) { y = val; }
  int getY() const { return y; }
  void setSpeed(const int val) { speed = val; }
  int getSpeed() const { return speed; }

private:
  int x, y, speed;
};
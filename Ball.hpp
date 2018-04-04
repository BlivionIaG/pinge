#pragma once

class Ball {
public:
  Ball(int x = 0, int y = 0, int size = 1, int speed = 1)
      : x{x}, y{y}, size{size}, speed{speed} {
    dx = dy = -1;
  }
  ~Ball() {}

  void setX(const int val) { x = val; }
  int getX() const { return x; }
  void setY(const int val) { y = val; }
  int getY() const { return y; }
  void setSpeed(const int val) { speed = val; }
  int getSpeed() const { return speed; }
  void setSize(const int val) { size = val; }
  int getSize() const { return size; }

  int getDX() const { return dx; }
  int getDY() const { return dy; }
  void toggleDX() { dx = -dx; }
  void toggleDY() { dy = -dy; }

private:
  int x, y, size, speed, dx, dy;
};
#include "Game.hpp"

void Game::moveBall() {
  keepIn(0, 0, width, height);
  collide(one.getX(), one.getY(), one.getX() + one.getWidth(),
          one.getY() + one.getHeight());
  collide(two.getX(), two.getY(), two.getX() + two.getWidth(),
          two.getY() + two.getHeight());

  ball.setX(ball.getX() + ball.getDX() * ball.getSpeed());
  ball.setY(ball.getY() + ball.getDY() * ball.getSpeed());
}

void Game::keepIn(int x0, int y0, int x1, int y1) {
  if (ball.getX() >= x1 - ball.getSize() || ball.getX() <= x0) {
    ball.toggleDX();
    if (ball.getX() <= x0) {
      two.setScore(two.getScore() + 1);
    } else if (ball.getX() >= x1 - ball.getSize()) {
      one.setScore(one.getScore() + 1);
    }
  }
  if (ball.getY() >= y1 - ball.getSize() || ball.getY() <= y0)
    ball.toggleDY();
}

template <typename T> void Game::collide(T x0, T y0, T x1, T y1) {
  T r = ball.getSize() / 2;
  T x = ball.getX() + r;
  T y = ball.getY() + r;

  T dx = x - max(x0, min(x, x1));
  T dy = y - max(y0, min(y, y1));

  if ((dx * dx + dy * dy) < (r * r)) {
    ball.toggleDX();
    ball.toggleDY();
  }
}
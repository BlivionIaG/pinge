#include "Game.hpp"

void Game::moveBall() {
  if (ball.getX() >= width - ball.getSize() || ball.getX() <= 0)
    ball.toggleDX();
  if (ball.getY() >= height - ball.getSize() || ball.getY() <= 0)
    ball.toggleDY();

  ball.setX(ball.getX() + ball.getDX() * ball.getSpeed());
  ball.setY(ball.getY() + ball.getDY() * ball.getSpeed());
}
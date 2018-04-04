#include "Scene.hpp"

Scene::Scene(int width, int height, QObject *parent)
    : QGraphicsScene(parent), width{width}, height{height}, game{width,
                                                                 height} {
  screen = new QGraphicsRectItem(0, 0, width, height);
  screen->setPos(0, 0);

  this->addItem(screen);

  initBall(game.getBall());
}

void Scene::initBall(Ball &b) {
  ball = new QGraphicsEllipseItem(0, 0, b.getSize(), b.getSize());
  ball->setPos(b.getX(), b.getY());
  this->addItem(ball);

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateBall()));
  timer->start(30);
}

void Scene::updateBall() {
  auto &tmp = game.getBall();
  ball->setPos(tmp.getX(), tmp.getY());

  game.moveBall();
}

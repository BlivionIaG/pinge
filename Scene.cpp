#include "Scene.hpp"

Scene::Scene(int width, int height, QObject *parent)
    : QGraphicsScene(parent), width{width}, height{height}, game{width,
                                                                 height} {
  screen = new QGraphicsRectItem(0, 0, width, height);
  screen->setPos(0, 0);

  this->addItem(screen);

  initGameGraphics();
}

void Scene::initGameGraphics() {
  ball = new QGraphicsEllipseItem(0, 0, game.getBall().getSize(),
                                  game.getBall().getSize());
  ball->setPos(game.getBall().getX(), game.getBall().getY());
  this->addItem(ball);

  one = new QGraphicsRectItem(0, 0, game.getPlayerOne().getWidth(),
                              game.getPlayerOne().getHeight());
  one->setPos(game.getPlayerOne().getX(), game.getPlayerOne().getY());
  this->addItem(one);

  two = new QGraphicsRectItem(0, 0, game.getPlayerTwo().getWidth(),
                              game.getPlayerTwo().getHeight());
  two->setPos(game.getPlayerTwo().getX(), game.getPlayerTwo().getY());
  this->addItem(two);

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(30);
}

void Scene::update() {
  ball->setPos(game.getBall().getX(), game.getBall().getY());
  one->setPos(game.getPlayerOne().getX(), game.getPlayerOne().getY());
  two->setPos(game.getPlayerTwo().getX(), game.getPlayerTwo().getY());

  game.moveBall();
}

void Scene::keyPressEvent(QKeyEvent *ev) {

  auto &p1 = game.getPlayerOne(), &p2 = game.getPlayerTwo();
  switch (ev->key()) {
  case Qt::Key_Up:
    p2.setY(p2.getY() - p2.getSpeed());
    break;
  case Qt::Key_Down:
    p2.setY(p2.getY() + p2.getSpeed());
    break;
  case Qt::Key_Z:
    p1.setY(p1.getY() - p1.getSpeed());
    break;
  case Qt::Key_S:
    p1.setY(p1.getY() + p1.getSpeed());
    break;
  }
}
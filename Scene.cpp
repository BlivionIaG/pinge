#include "Scene.hpp"

Scene::Scene(int width, int height, QObject *parent)
    : QGraphicsScene(parent), width{width}, height{height}, game{width,
                                                                 height} {
  keys[256] = {false};
  keys[38] = false;
  keys[39] = false;

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

  scoreOne =
      new QGraphicsTextItem(QString::number(game.getPlayerOne().getScore()));
  scoreOne->setPos(3 * width / 8, height / 16);
  this->addItem(scoreOne);

  scoreTwo =
      new QGraphicsTextItem(QString::number(game.getPlayerTwo().getScore()));
  scoreTwo->setPos(5 * width / 8, height / 16);
  this->addItem(scoreTwo);

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(30);
}

void Scene::update() {
  ball->setPos(game.getBall().getX(), game.getBall().getY());
  one->setPos(game.getPlayerOne().getX(), game.getPlayerOne().getY());
  two->setPos(game.getPlayerTwo().getX(), game.getPlayerTwo().getY());
  scoreOne->setPlainText(QString::number(game.getPlayerOne().getScore()));
  scoreTwo->setPlainText(QString::number(game.getPlayerTwo().getScore()));

  game.moveBall();
  if (keys['Z'] || keys['S'])
    game.movePlayerOne();
  if (keys[38] || keys[39])
    game.movePlayerTwo();
}

void Scene::keyPressEvent(QKeyEvent *ev) {

  auto &p1 = game.getPlayerOne(), &p2 = game.getPlayerTwo();
  switch (ev->key()) {
  case Qt::Key_Up:
    p2.setDY(-1);
    keys[38] = true;
    break;
  case Qt::Key_Down:
    p2.setDY(1);
    keys[39] = true;
    break;
  case Qt::Key_Z:
    p1.setDY(-1);
    keys['Z'] = true;
    break;
  case Qt::Key_S:
    p1.setDY(1);
    keys['S'] = true;
    break;
  }
}

void Scene::keyReleaseEvent(QKeyEvent *ev) {
  switch (ev->key()) {
  case Qt::Key_Up:
    keys[38] = false;
    break;
  case Qt::Key_Down:
    keys[39] = false;
    break;
  case Qt::Key_Z:
    keys['Z'] = false;
    break;
  case Qt::Key_S:
    keys['S'] = false;
    break;
  }
}
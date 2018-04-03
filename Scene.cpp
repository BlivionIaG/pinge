#include "Scene.hpp"

Scene::Scene(int width, int height, QObject *parent)
    : QGraphicsScene(parent), width{width}, height{height} {
  screen = new QGraphicsRectItem(0, 0, width, height);
  this->addItem(screen);

  boule.setX(0);
  boule.setY(0);
  ball = new QGraphicsEllipseItem;
  ball->setRect(0, 0, 20, 20);
  this->addItem(ball);

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(30);
}

void Scene::update() {
  ball->setPos(boule.getX(), boule.getY());
  boule.setX(boule.getX() + 1);
}
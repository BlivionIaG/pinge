#pragma once

#include "Game.hpp"
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QWidget>
#include <memory>

class Scene : public QGraphicsScene {
  Q_OBJECT
public:
  Scene(int width, int height, QObject *parent = 0);
  ~Scene() noexcept {}

  void initBall(Ball &b);
public slots:
  void updateBall();

private:
  int width, height;
  QGraphicsRectItem *screen;
  QGraphicsEllipseItem *ball;
  Game game;
  QTimer *timer;
};
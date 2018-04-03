#pragma once

#include "Ball.hpp"
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
  ~Scene() {}

public slots:
  void update();

private:
  QGraphicsRectItem *screen;
  QGraphicsEllipseItem *ball;
  QTimer *timer;
  Ball boule;
  int width, height;
};
#ifndef PINGE_SCENE_HPP
#define PINGE_SCENE_HPP

#include "Game.hpp"
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QWidget>

class Scene : public QGraphicsScene {
  Q_OBJECT
public:
  Scene(int width, int height, QObject *parent = 0);
  ~Scene() noexcept {}

  void initGameGraphics();
  void keyPressEvent(QKeyEvent *ev);
public slots:
  void update();

private:
  int width, height;

  QGraphicsRectItem *screen, *one, *two;
  // QTextItem *scoreOne, *score2;
  QGraphicsEllipseItem *ball;

  Game game;
  QTimer *timer;
};

#endif /* PINGE_SCENE_HPP */
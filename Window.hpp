#pragma once

#include "Scene.hpp"
#include <QApplication>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QWidget>

class Window : public QMainWindow {
  Q_OBJECT
public:
  Window(QString title, QWidget *parent = 0);

private:
  QWidget *main;
  Scene *scene;
  QGraphicsView *view;
};
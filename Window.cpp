#include "Window.hpp"

Window::Window(QString title, QWidget *parent) : QMainWindow(parent) {
  this->setWindowTitle(title);

  main = new QWidget;
  QHBoxLayout *layout = new QHBoxLayout;
  main->setLayout(layout);
  this->setCentralWidget(main);

  scene = new Scene(640, 480, this);
  view = new QGraphicsView;
  view->setScene(scene);

  layout->addWidget(view);
}
#include "Window.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Window window("HYBER PINGE 2POW42 EXPERT EDITION XTRA PLITINIUM");

  window.show();

  return app.exec();
}
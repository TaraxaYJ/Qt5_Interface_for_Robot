//main.cpp
#include <QApplication>
#include "mydialog.h"
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MyDialog dialog;
  dialog.show();
  return a.exec();
}

#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QDialog>
class QToolBox;
class MyDialog : public QDialog
{
  Q_OBJECT
public:
  explicit MyDialog(QWidget *parent = 0);
signals:
public slots:
private:
  QToolBox *toolBox;
};
#endif // MYDIALOG_H

//mydialog.cpp
#include "mydialog.h"
#include <QToolBox>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
MyDialog::MyDialog(QWidget *parent) :
  QDialog(parent)
{
  //新建一个QToolBox
  toolBox = new QToolBox(this);

  //新建一个QWidget 添加到QToolBox中
  QWidget *widget = new QWidget();
  QIcon iconHahaya(":/new/ico/images/hahaya.ico");
  QPushButton *buttonHahaya = new QPushButton(iconHahaya, "hahaya");
  QIcon iconZhangSan(":/new/ico/images/zhangsan.ico");
  QPushButton *buttonZhangSan = new QPushButton(iconZhangSan, "zhangsan");
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(buttonHahaya);
  layout->addWidget(buttonZhangSan);
  widget->setLayout(layout);

  //新建一个QPushButton 添加到QToolBox中
  QIcon iconLiSi(":/new/ico/images/lisi.ico");
  QPushButton *buttonStrange = new QPushButton(iconLiSi, "lisi");

  //向QToolBox中添加第一个抽屉 名字为Friend
  toolBox->addItem(widget, "Friend");
  QIcon iconFriend(":/new/ico/images/friend.ico");
  //设置第一个抽屉的图标
  toolBox->setItemIcon(0, iconFriend);

  //向QToolBox中添加第二个抽屉 名字为Strange
  toolBox->addItem(buttonStrange, "Strange");
  QIcon iconStrange(":/new/ico/images/strange.ico");
  toolBox->setItemIcon(1, iconStrange);

   //设置抽屉内控件距离
  toolBox->layout()->setSpacing(0);


  QHBoxLayout *hLayout = new QHBoxLayout();
  hLayout->addWidget(toolBox);
  hLayout->setMargin(0);

  this->setLayout(hLayout);
  this->resize(100, 200);
  this->setWindowTitle("QToolBoxDemo");
}

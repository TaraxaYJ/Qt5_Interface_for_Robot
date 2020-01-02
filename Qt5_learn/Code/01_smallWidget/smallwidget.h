#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget   //派生类名是：SmallWidget  基类是：QWidget 采用public继承方式，使用频率最高的方式
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = 0);   //explicit作用：在构造函数中，避免隐式的转换。
    ~SmallWidget();

    //设置数字
    void setNum(int num);

    //获取数字
    int getNum();

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H

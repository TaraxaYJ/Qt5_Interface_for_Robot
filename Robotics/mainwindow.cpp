#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include "moreinfo.h"
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("://picture/EAIrobot.png"));
    setWindowTitle(tr("Intelligent Robotic Platform"));
    initMenu();
    ui->connect1->setEnabled(true);
    ui->disconnect1->setEnabled(false);
    ui->connect2->setEnabled(true);
    ui->disconnect2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMenu()
{
    QMenu *aboutMenu=new QMenu("Help",ui->menuBar);


   // QAction *myAc1 = new QAction(this);
  //  myAc1->setText(QString::fromLocal8Bit("Edit"));
   // ui->menuBar->addAction(myAc1);

    QAction *action=new QAction;


    makeAction(action,aboutMenu,"About(A)", Qt::CTRL + Qt::Key_A);
    connect(action,SIGNAL(triggered()),this,SLOT(aboutSlots()));
    aboutMenu->addAction(action);

    makeAction(action,aboutMenu,"OpenSource(O)", Qt::CTRL + Qt::Key_O);
    connect(action,SIGNAL(triggered()),this,SLOT(OpenSourceDialog()));
    aboutMenu->addAction(action);

    makeAction(action,aboutMenu,"Explanation(E)", Qt::CTRL + Qt::Key_E);
    connect(action,SIGNAL(triggered()),this,SLOT(useDialog()));
    aboutMenu->addAction(action);

    ui->menuBar->addMenu(aboutMenu);

    QMenu *aboutMenu1 = new QMenu("Edit",ui->menuBar);
    QAction *action1=new QAction;
    aboutMenu1->addAction(action1);
    ui->menuBar->addMenu(aboutMenu1);

    QMenu *aboutMenu2 = new QMenu("Build",ui->menuBar);
    QAction *action2=new QAction;
    aboutMenu2->addAction(action2);
    ui->menuBar->addMenu(aboutMenu2);

    QMenu *aboutMenu3 = new QMenu("File",ui->menuBar);
    QAction *action3=new QAction;
    aboutMenu3->addAction(action3);
    ui->menuBar->addMenu(aboutMenu3);

    QMenu *aboutMenu4 = new QMenu("Debug",ui->menuBar);
    QAction *action4=new QAction;
    aboutMenu4->addAction(action4);
    ui->menuBar->addMenu(aboutMenu4);

    QMenu *aboutMenu5 = new QMenu("Analyze",ui->menuBar);
    QAction *action5=new QAction;
    aboutMenu5->addAction(action5);
    ui->menuBar->addMenu(aboutMenu5);

    QMenu *aboutMenu6 = new QMenu("ToolBox",ui->menuBar);
    QAction *action6=new QAction;
    aboutMenu6->addAction(action6);
    ui->menuBar->addMenu(aboutMenu6);

    QMenu *aboutMenu7 = new QMenu("Widget",ui->menuBar);
    QAction *action7=new QAction;
    aboutMenu7->addAction(action7);
    ui->menuBar->addMenu(aboutMenu7);
}


bool MainWindow::makeAction(QAction*& action, QWidget* parent, QString text, int key)
{
    bool ret = true;

    action = new QAction(text, parent);

    if( action != NULL )
    {
        action->setShortcut(QKeySequence(key));
    }
    else
    {
        ret = false;
    }

    return ret;
}
bool MainWindow::makeAction(QAction*& action, QWidget* parent, QString tip, QString icon)//配置Qaction选项 用于工具栏里的action
{
    bool ret = true;

    action = new QAction("", parent);

    if( action != NULL )
    {
        action->setToolTip(tip);
        action->setIcon(QIcon(icon));
    }
    else
    {
        ret = false;
    }

    return ret;
}

void MainWindow::useDialog()
{
          //---实例化消息对话框对象

         msgBox = new QMessageBox("Explanation",       //--这里是设置消息框标题
        "This is an Intelligent Robotic Platform\n\nCopyright Reserved From SJTU_CPS Group",                       //--这里是设置消息框显示的内容
        QMessageBox::Information,                          //--这里是在消息框显示的图标
        QMessageBox::Ok ,     //---这里是显示消息框上的按钮情况
        0,                                                      //---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
        0);                                                     //---这里是 定义第三个按钮， 该例子 只是 了显示2个按钮
        msgBox->exec();       //---显示消息框
        delete msgBox;
}


void MainWindow::aboutSlots()
{
    MoreInfo(this).exec();
}

void MainWindow::OpenSourceDialog()
{
    QDesktopServices::openUrl(QUrl("https://blog.csdn.net/weixin_44504987/article/details/95099876"));
}

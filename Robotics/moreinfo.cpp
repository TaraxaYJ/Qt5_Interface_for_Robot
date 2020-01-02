#include "moreinfo.h"
#include <QPixmap>
#include <QPalette>

MoreInfo::MoreInfo(QWidget *parent) : QDialog(parent,Qt::WindowCloseButtonHint),m_logoLbl(this),m_qqLbl(this),m_infoEdit(this),
    m_closeBtn(this)
{
      QPixmap pm(":/picture/EAIrobot.png");
      pm = pm.scaled(120, 120, Qt::KeepAspectRatio);

      m_logoLbl.setPixmap(pm);
      m_logoLbl.move(20, 20);
      m_logoLbl.resize(120, 120);

      QPalette p = m_infoEdit.palette();

      p.setColor(QPalette::Active, QPalette::Base, palette().color(QPalette::Active, QPalette::Background));
      p.setColor(QPalette::Inactive, QPalette::Base, palette().color(QPalette::Inactive, QPalette::Background));

      m_infoEdit.move(200, 30);
      m_infoEdit.resize(180, 130);
      m_infoEdit.setPalette(p);
      m_infoEdit.setFrameStyle(QFrame::NoFrame);
      m_infoEdit.setReadOnly(true);
      m_infoEdit.insertPlainText("Inteliigent Robotics Platform  Project\n\nPlatform: Qt 5.10.0\n\nVersion:  1.0.0\n\nAuthor:   YYJ");

      m_qqLbl.move(22, 184);
      m_qqLbl.setText("Email: 915105465@qq.com");

      m_closeBtn.setText("Close");
      m_closeBtn.move(273, 175);
      m_closeBtn.resize(100, 30);

      setFixedSize(390, 230);
      setWindowTitle("About This Project");

      connect(&m_closeBtn, SIGNAL(clicked()), this, SLOT(close()));
}


#ifndef MOREINFO_H
#define MOREINFO_H

#include <QDialog>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>


class MoreInfo : public QDialog
{
    Q_OBJECT

    QLabel m_logoLbl;
    QLabel m_qqLbl;
    QPlainTextEdit m_infoEdit;
    QPushButton m_closeBtn;
public:
    explicit MoreInfo(QWidget *parent = nullptr);

};

#endif // MOREINFO_H

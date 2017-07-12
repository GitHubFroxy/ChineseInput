﻿#ifndef XYMENU_H
#define XYMENU_H

#include "xybordershadowwidget.h"
#include <QIcon>
#include <QMap>
#include <QPixmap>
#include <QAction>

class XYMenuStyle;
class QEventLoop;
class QVBoxLayout;

class XYMenu : public XYBorderShadowWidget
{
    Q_OBJECT
public:
    explicit XYMenu(QWidget *parent = 0);
    XYMenu(const QString &title, QWidget *parent = 0);
    XYMenu(const QIcon &icon, const QString &title, QWidget *parent = 0);
    QString title();
    QIcon icon();
    QFont font();
    ~XYMenu();

public slots:
    int exec();
    void raise();
    void updateCheckedMenu();
    int exec(XYMenu *parent);
    bool close(bool closeParent = false);
    void setTitle(const QString &title);
    void setIcon(const QIcon &icon);
    void setFont(const QFont &font);
    void setBackImage(const QPixmap &image);
    void addMenu(XYMenu *menu);

protected:
    void paintEvent(QPaintEvent *event);
    void focusOutEvent(QFocusEvent *event);
    void leaveEvent(QEvent *event);
    void clicked(const QPoint &point);

private:
    void execMenu2(XYMenuStyle *style);
    void setupUI();

private:
    static XYMenu      *mopLastMenu;
    QMap<int, XYMenu *> mlistMenus;
    QList<QWidget *>    mlistWidgets;
    XYMenu        *mopParentMenu;
    QEventLoop    *mopEventLoop;
    QVBoxLayout   *mopMainLayout;
    XYMenuStyle   *mopCurrentChecked;

    QString        msTitle;
    QIcon          moIcon;
    QFont          moFont;
    QPixmap        moBackImage;
    int            miActionMaxWidth;

    friend class   XYMenuStyle;
};

#endif // XYMENU_H

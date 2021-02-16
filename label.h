#ifndef LABEL_H
#define LABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QString>

class Label : public QLabel
{
    QFont font;
public:
    Label(QString t, int x, int y, int f, QWidget * par);
    Label(QString t, int x, int y, int f, int w, QWidget * par);
    Label(QString t, int x, int y, int f, int w, int h, QWidget * par);
};

#endif // LABEL_H

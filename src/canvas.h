#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#include <memory>

#include "selforganizingmap.h"

class Canvas : public QWidget
{
    Q_OBJECT

private:
    int XPAD = 5;
    int YPAD = 20;

public:
    explicit Canvas(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);

    std::shared_ptr<SelfOrganizingMap> som;

    bool draw_cities = true;
    bool draw_nodes = true;
    bool draw_tour = true;

signals:

public slots:
};

#endif // CANVAS_H

#ifndef POINTPROCESSOR_H
#define POINTPROCESSOR_H

#include <QPointF>
#include <QList>

class PointProcessor
{
public:
    PointProcessor();
    static QPointF generateNew();
    static QPointF mean5_3(QList<QPointF> &points, QPointF &newPoint);
    static QPointF getExpect(QList<QPointF> &points, QPointF &newPoint, qreal modulus);
    static QPointF averge(QList<QPointF> &points, QPointF &newPoint);
};

#endif // POINTPROCESSOR_H

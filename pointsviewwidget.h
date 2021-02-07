#ifndef POINTSVIEWWIDGET_H
#define POINTSVIEWWIDGET_H

#include <QWidget>
#include <QPointF>

class PointsViewWidget : public QWidget
{

public:
    QList<QPointF> points;
    QList<QPointF> op_points;
    PointsViewWidget(QWidget* parent = nullptr) : QWidget(parent) {

    };
    void addPoint(QPointF point) {
        points.append(point);
    };
    void addPoint(qreal x, qreal y) {
        addPoint(QPointF(x, y));
    };
    void addOpPoint(QPointF point) {
        op_points.append(point);
    };
    void setTitle(QString text) {
        title = text;
    }
protected:
    QString title;
    void paintEvent(QPaintEvent *event);
};

#endif // POINTSVIEWWIDGET_H

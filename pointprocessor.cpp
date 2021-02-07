#include "pointprocessor.h"
#include <QTime>

PointProcessor::PointProcessor()
{

}

qreal rand_real() {
    QTime t = QTime::currentTime();
    qsrand(t.msec() + t.second() * 1000);
    int n = qrand() % 99;
    return (qreal) n / 98.0;
}

static qreal __x = 0.05;
static qreal __y = 0.5;
QPointF PointProcessor::generateNew() {
    __x += 0.003;
    return QPointF(__x, __y + 0.08 * (rand_real() * 2 - 1));
};

// 5点3次
QPointF PointProcessor::mean5_3(QList<QPointF> &points, QPointF &newPoint) {
    if (points.size() < 4) {
        return newPoint;
    }
    int n = points.size();

    return QPointF(
            (69 * newPoint.x() + 4 * (points[n - 1].x() + points[n - 3].x()) - 6 * points[n - 2].x() - points[n - 4].x()) / 70,
            (69 * newPoint.y() + 4 * (points[n - 1].y() + points[n - 3].y()) - 6 * points[n - 2].y() - points[n - 4].y()) / 70
            );
}

// 二次指数
QPointF PointProcessor::getExpect(QList<QPointF> &points, QPointF &newPoint, qreal modulus) {
    if (points.size() < 4) {
        return newPoint;
    }
    int n = points.size();
    qreal modulusLeft = 1 - modulus;
    qreal lastIndex = points[n - 4].y();
    qreal lastSecIndex = points[n - 4].y();
    for (int i = n - 4; i < n; i++) {
        qreal data = points[i].y();
        lastIndex = modulus * data + modulusLeft * lastIndex;
        lastSecIndex = modulus * lastIndex + modulusLeft * lastSecIndex;
    }
    qreal a = 2 * lastIndex - lastSecIndex;
    qreal b = (modulus / modulusLeft) * (lastIndex - lastSecIndex);
    return QPointF(newPoint.x(), a + b);
}

// 平均值
QPointF PointProcessor::averge(QList<QPointF> &points, QPointF &newPoint) {
    if (points.empty()) {
        return newPoint;
    }
    QPointF last_p = points.last();
    return QPointF((last_p.x() + newPoint.x()) / 2, (last_p.y() + newPoint.y()) / 2);
}


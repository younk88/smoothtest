#include "pointsviewwidget.h"
#include <QPainter>

void PointsViewWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect(0, 0, width(), height());
    painter.fillRect(rect, Qt::black);

    painter.setPen(Qt::white);
    painter.drawText(15, 15, title);

    if (!points.empty()) {
        QPointF p;
        QPainterPath path;
        painter.setPen(Qt::green);
        for (int i = 0, l = points.size(); i < l; i++) {
            qreal left = rect.width() * points[i].x();
            qreal top = rect.height() * points[i].y();
            if (i == 0) {
                path.moveTo(left, top);
            } else {
                path.lineTo(left, top);
            }
            painter.drawPoint(QPointF(left, top));
        }

        painter.setPen(Qt::red);
        painter.drawPath(path);
    }

    if (!op_points.empty()) {
        QPointF p;
        QPainterPath path;
        painter.setPen(Qt::blue);
        for (int i = 0, l = op_points.size(); i < l; i++) {
            qreal left = rect.width() * op_points[i].x();
            qreal top = rect.height() * op_points[i].y();
            if (i == 0) {
                path.moveTo(left, top);
            } else {
                path.lineTo(left, top);
            }
            painter.drawPoint(QPointF(left, top));
        }

        painter.setPen(Qt::yellow);
        painter.drawPath(path);
    }
}

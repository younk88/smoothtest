#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pointsviewwidget.h"
#include <QTimer>
#include <QPointF>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PointsViewWidget* meanByOriWidget;
    PointsViewWidget* expectByOriWidget;
    PointsViewWidget* meanByNewWidget;
    PointsViewWidget* expectByNewWidget;
    PointsViewWidget* avgByOriWidget;
    PointsViewWidget* avgByNewWidget;
    QTimer* timer;
    void init_point_widgets();

Q_SIGNALS:
    void new_point(QPointF& point);

private slots:
    void on_mean5_3_by_ori(QPointF& point);
    void on_mean5_3_by_new(QPointF& point);
    void on_expect_2_by_ori(QPointF& point);
    void on_expect_2_by_new(QPointF& point);
    void on_avg_by_ori(QPointF& point);
    void on_avg_by_new(QPointF& point);
};
#endif // MAINWINDOW_H

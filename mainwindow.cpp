#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pointprocessor.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_point_widgets();

    timer = new QTimer();
    connect(timer, &QTimer::timeout, [&]() {
        QPointF p = PointProcessor::generateNew();
        emit new_point(p);
    });
    timer->setInterval(500);
    timer->start();
}

void MainWindow::init_point_widgets() {
    meanByOriWidget = new PointsViewWidget(ui->centralwidget);
    meanByOriWidget->setObjectName("mean_ori_points_widget");
    meanByOriWidget->setTitle("mean5_3 by ori");
    ui->verticalContentLayout->addWidget(meanByOriWidget);
    connect(this, SIGNAL(new_point(QPointF&)), this, SLOT(on_mean5_3_by_ori(QPointF&)), Qt::DirectConnection);

    meanByNewWidget = new PointsViewWidget(ui->centralwidget);
    meanByNewWidget->setObjectName("mean_new_points_widget");
    meanByNewWidget->setTitle("mean5_3 by new");
    ui->verticalContentLayout->addWidget(meanByNewWidget);
    connect(this, SIGNAL(new_point(QPointF&)), this, SLOT(on_mean5_3_by_new(QPointF&)), Qt::DirectConnection);

    expectByOriWidget = new PointsViewWidget(ui->centralwidget);
    expectByOriWidget->setObjectName("expect_ori_points_widget");
    expectByOriWidget->setTitle("exprect by ori");
    ui->verticalContentLayout->addWidget(expectByOriWidget);
    connect(this, SIGNAL(new_point(QPointF&)), this, SLOT(on_expect_2_by_ori(QPointF&)), Qt::DirectConnection);

    expectByNewWidget = new PointsViewWidget(ui->centralwidget);
    expectByNewWidget->setObjectName("expect_new_points_widget");
    expectByNewWidget->setTitle("exprect by new");
    ui->verticalContentLayout->addWidget(expectByNewWidget);
    connect(this, SIGNAL(new_point(QPointF&)), this, SLOT(on_expect_2_by_new(QPointF&)), Qt::DirectConnection);

    avgByOriWidget = new PointsViewWidget(ui->centralwidget);
    avgByOriWidget->setObjectName("avg_ori_points_widget");
    avgByOriWidget->setTitle("avg by ori");
    ui->verticalContentLayout->addWidget(avgByOriWidget);
    connect(this, SIGNAL(new_point(QPointF&)), this, SLOT(on_avg_by_ori(QPointF&)), Qt::DirectConnection);

    avgByNewWidget = new PointsViewWidget(ui->centralwidget);
    avgByNewWidget->setObjectName("avg_new_points_widget");
    avgByNewWidget->setTitle("avg by new");
    ui->verticalContentLayout->addWidget(avgByNewWidget);
    connect(this, SIGNAL(new_point(QPointF&)), this, SLOT(on_avg_by_new(QPointF&)), Qt::DirectConnection);
}

MainWindow::~MainWindow()
{
    timer->stop();
    delete timer;
    delete meanByOriWidget;
    delete meanByNewWidget;
    delete expectByOriWidget;
    delete expectByNewWidget;
    delete avgByOriWidget;
    delete avgByNewWidget;
    delete ui;
}

void MainWindow::on_mean5_3_by_ori(QPointF& point) {
    QPointF po = PointProcessor::mean5_3(meanByOriWidget->points, point);
    meanByOriWidget->addPoint(point);
    meanByOriWidget->addOpPoint(po);
    meanByOriWidget->repaint();
}
void MainWindow::on_mean5_3_by_new(QPointF& point) {
    QPointF po = PointProcessor::mean5_3(meanByNewWidget->op_points, point);
    meanByNewWidget->addPoint(point);
    meanByNewWidget->addOpPoint(po);
    meanByNewWidget->repaint();
}
void MainWindow::on_expect_2_by_ori(QPointF& point) {
    QPointF po = PointProcessor::getExpect(expectByOriWidget->points, point, 0.4);
    expectByOriWidget->addPoint(point);
    expectByOriWidget->addOpPoint(po);
    expectByOriWidget->repaint();
}
void MainWindow::on_expect_2_by_new(QPointF& point) {
    QPointF po = PointProcessor::getExpect(expectByNewWidget->op_points, point, 0.4);
    expectByNewWidget->addPoint(point);
    expectByNewWidget->addOpPoint(po);
    expectByNewWidget->repaint();
}

void MainWindow::on_avg_by_ori(QPointF& point) {
    QPointF po = PointProcessor::averge(avgByOriWidget->points, point);
    avgByOriWidget->addPoint(point);
    avgByOriWidget->addOpPoint(po);
    avgByOriWidget->repaint();
}
void MainWindow::on_avg_by_new(QPointF& point) {
    QPointF po = PointProcessor::averge(avgByNewWidget->op_points, point);
    avgByNewWidget->addPoint(point);
    avgByNewWidget->addOpPoint(po);
    avgByNewWidget->repaint();
}


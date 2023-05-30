#ifndef CHARTAREA_H
#define CHARTAREA_H

#include <QChartView>
#include <QValueAxis>
#include <QVector>
#include <QWheelEvent>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>

class ChartArea : public QChartView {
  Q_OBJECT
 public:
  explicit ChartArea(QWidget *parent = nullptr);
  void SetValues(double, double, double, double,
                 std::vector<std::pair<double, double>> pairs_xy, QString);
  void SetDefaultAxis();
  void wheelEvent(QWheelEvent *event);
  void mouseMoveEvent(QMouseEvent *event);

 public:
  QLineSeries *series;
  QValueAxis *axisX, *axisY;
};

#endif  // CHARTAREA_H

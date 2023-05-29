#ifndef CHARTAREA_H
#define CHARTAREA_H

#include <QChartView>
#include <QValueAxis>
#include <QVector>
#include <QWheelEvent>
#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

class ChartArea : public QChartView {
  Q_OBJECT
 public:
  explicit ChartArea(QWidget *parent = nullptr);
  void SetValues(double, double, double, double, std::vector<double>,
                 std::vector<double>, QString);
  void wheelEvent(QWheelEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void SetDefaultAxis();

 public:
  QLineSeries *series;
  std::vector<double> x_axis_, y_axis_;
  double min_x_{}, max_x_{}, min_y_{}, max_y_{};
  QString function_name_;
  QValueAxis *axisX, *axisY;
  QPointF beginPoint;
};

#endif  // CHARTAREA_H

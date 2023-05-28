#include "chartarea.h"

#include <iostream>

ChartArea::ChartArea(QWidget *parent) : QChartView{parent} {
  chart()->createDefaultAxes();
  axisX = new QValueAxis();
  axisY = new QValueAxis();
  setRenderHint(QPainter::Antialiasing);

  chart()->zoomIn();
}

void ChartArea::SetValues(double min_x, double max_x, double min_y,
                          double max_y, std::vector<double> x_axis,
                          std::vector<double> y_axis, QString function_name) {
  min_x_ = min_x;
  max_x_ = max_x;
  min_y_ = min_y;
  max_y_ = max_y;
  x_axis_ = x_axis;
  y_axis_ = y_axis;
  function_name_ = function_name;
  chart()->removeAllSeries();
  series = new QLineSeries();
  for (int i = 0; i < x_axis.size(); ++i) {
    //    if (series == nullptr || (y_axis[i] > max_y || y_axis[i] < min_y)) {
    //      chart()->addSeries(series);
    //      QColor series_color;
    //      if (series != nullptr) {
    //        series_color = series->color();
    //      }
    //      series = new QLineSeries();
    //      series->setColor(series_color);
    //    }

    *series << QPointF(x_axis[i], y_axis[i]);
  }
  series->setMarkerSize(15.0);
  chart()->addSeries(series);
  chart()->setTitle("Graphic of function " + function_name);
  axisX->setRange(min_x_, max_x_);
  axisX->setTickCount((max_x_ - min_x_) + 1);
  axisX->setLinePenColor(series->pen().color());
  chart()->addAxis(axisX, Qt::AlignBottom);
  series->attachAxis(axisX);
  chart()->axes(Qt::Horizontal, series).back()->setTitleText("axe X");
  axisY->setRange(min_y_, max_y_);
  axisY->setTickCount((max_y_ - min_y_) + 1);
  axisY->setLinePenColor(series->pen().color());
  chart()->addAxis(axisY, Qt::AlignLeft);
  series->attachAxis(axisY);
  chart()->axes(Qt::Vertical, series).back()->setTitleText("axe Y");
}

void ChartArea::wheelEvent(QWheelEvent *event) {
  qreal zoom = event->angleDelta().y() > 0 ? 0.5 : 1.5;
  chart()->zoom(zoom);
  update();
}

void ChartArea::mouseMoveEvent(QMouseEvent *event) {
  bool leftClick = event->buttons() & Qt::LeftButton;
  beginPoint = event->pos();
  if (leftClick) {
    mousePoint = event->pos();
    chart()->scroll(beginPoint.x() - mousePoint.x(),
                    beginPoint.y() - mousePoint.y());
    update();
    beginPoint = mousePoint;
  }
}

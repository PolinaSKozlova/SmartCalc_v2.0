#include "chartarea.h"

#include <iostream>

ChartArea::ChartArea(QWidget *parent) : QChartView{parent} {
  chart()->createDefaultAxes();
  //  auto test = chart()->axes();
  //  chart()->axes(Qt::Horizontal).back()->setTitleText("axe X");
  //  chart()->axes(Qt::Vertical).back()->setTitleText("axe Y");
  setRenderHint(QPainter::Antialiasing);
  chart()->zoom(1);
}

void ChartArea::SetValues(double min_x, double max_x, double min_y,
                          double max_y, std::vector<double> x_axes,
                          std::vector<double> y_axes, QString function_name) {
  min_x_ = min_x;
  max_x_ = max_x;
  min_y_ = min_y;
  max_y_ = max_y;
  x_axes_ = x_axes;
  y_axes_ = y_axes;
  function_name_ = function_name;
  chart()->removeAllSeries();
  series = new QLineSeries();
  for (int i = 0; i < x_axes_.size(); ++i) {
    if (series == nullptr || fabs(y_axes_[i] - y_axes_[i + 1]) > 100) {
      QColor series_color;
      if (series != nullptr) {
        series_color = series->color();
      }
      series = new QLineSeries();
      series->setColor(series_color);
    }

    *series << QPointF(x_axes_[i], y_axes_[i]);
  }
  series->setMarkerSize(15.0);
  chart()->addSeries(series);
  chart()->setTitle("Graphic of function " + function_name_);
}

// void ChartArea::print_graph_from_charts() {
//   // QChart *ChartArea::print_graph_from_charts() {
//   //  std::cout << max_x_ << " " << min_x_ << std::endl;

//  series = new QLineSeries();
//  for (int i = 0; i < x_axes_.size(); ++i) {
//    if (series == nullptr || fabs(y_axes_[i] - y_axes_[i + 1]) > 100) {
//      QColor series_color;
//      if (series != nullptr) {
//        series_color = series->color();
//      }
//      series = new QLineSeries();
//      series->setColor(series_color);
//    }

//    *series << QPointF(x_axes_[i], y_axes_[i]);
//  }
//  series->setMarkerSize(15.0);
//  //  chart = new QChart();
//  //    chart->legend()->hide();
//  chart()->addSeries(series);
//  chart()->setTitle("Graphic of function " + function_name_);
//  //  QValueAxis *axisX = new QValueAxis();
//  //  axisX->setRange(min_x_, max_x_);
//  //  axisX->setTickCount((max_x_ - min_x_) + 1);
//  //  axisX->setLinePenColor(series->pen().color());
//  //  chart()->addAxis(axisX, Qt::AlignBottom);
//  //  series->attachAxis(axisX);

//  //  QValueAxis *axisY = new QValueAxis();
//  //  axisY->setRange(min_y_, max_y_);
//  //  axisY->setTickCount((max_y_ - min_y_) + 1);
//  //  axisY->setLinePenColor(series->pen().color());
//  //  chart->addAxis(axisY, Qt::AlignLeft);
//  //  series->attachAxis(axisY);

//  chart()->axes(Qt::Horizontal, series).back()->setTitleText("axe X");
//  chart()->axes(Qt::Vertical, series).back()->setTitleText("axe Y");
//  //  QChartView *chartView = new QChartView(chart());
//  setRenderHint(QPainter::Antialiasing);
//  //  chartView->setMinimumSize(640, 480);

//  //  return chart;
//}

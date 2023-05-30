#include "chartarea.h"

#include <iostream>

ChartArea::ChartArea(QWidget *parent) : QChartView{parent} {
  chart()->createDefaultAxes();
  axisX = new QValueAxis();
  axisY = new QValueAxis();
  SetDefaultAxis();
  setRenderHint(QPainter::Antialiasing);
}

void ChartArea::SetValues(double min_x, double max_x, double min_y,
                          double max_y,
                          std::vector<std::pair<double, double>> pairs_xy,
                          QString function_name) {
  chart()->removeAllSeries();
  //  QScatterSeries *series = new QScatterSeries();
  series = new QLineSeries();

  double previous_x = min_x;
  double previous_y = min_y;
  for (auto &current : pairs_xy) {
    //    QPointF p(current.first, current.second);
    //    series->append(p.x(), p.y());
    series->append(QPointF(current.first, current.second));

    if (fabs((current.second - previous_y) / (current.first - previous_x)) >
            (max_y + fabs(min_y)) &&
        ((current.second * previous_y) < 0)) {
      QColor series_color;
      if (series != nullptr) {
        series_color = series->color();
      }
      //      series->clear();
      for (auto it : series->points()) {
        std::cout << "function gap x " << it.x() << " y " << it.y()
                  << std::endl;
      }
      series = new QLineSeries();
      series->setColor(series_color);
      chart()->addSeries(series);
    }

    previous_x = current.first;
    previous_y = current.second;
  }
  for (auto it : series->points()) {
    std::cout << "x " << it.x() << " y " << it.y() << std::endl;
  }
  series->setMarkerSize(12.0);
  chart()->addSeries(series);
  chart()->setTitle("Graphic of function " + function_name);

  axisX->setRange(min_x, max_x);
  axisX->setTickCount((max_x - min_x) + 1);
  axisX->setLinePenColor(series->pen().color());
  chart()->addAxis(axisX, Qt::AlignBottom);
  series->attachAxis(axisX);
  chart()->axes(Qt::Horizontal, series).back()->setTitleText("axe X");
  axisY->setRange(min_y, max_y);
  axisY->setTickCount((max_y - min_y) + 1);
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
  static QPointF mouse_position;
  if (event->buttons() & Qt::LeftButton) {
    QPointF scale = QPointF(event->position() - mouse_position);
    chart()->scroll(-scale.x(), scale.y());
    update();
  }
  mouse_position = event->position();
}

void ChartArea::SetDefaultAxis() {
  axisX->setRange(0.0, 5.0);
  axisX->setTickCount(6);
  axisY->setRange(0.0, 5.0);
  axisY->setTickCount(6);
  chart()->setTitle("Graphic of function");
}

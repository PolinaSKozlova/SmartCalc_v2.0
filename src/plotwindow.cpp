#include "plotwindow.h"

#include "plot/qcustomplot.h"
#include "ui_plotwindow.h"

PlotWindow::PlotWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::PlotWindow) {
  ui->setupUi(this);
  setMinimumSize(870, 680);
}

PlotWindow::~PlotWindow() { delete ui; }

void PlotWindow::MakePlotArea(
    s21::MaxMinValues mmv,
    std::pair<std::vector<double>, std::vector<double>> vector_of_pairs) {
  QVector<double> x_axis(vector_of_pairs.first.begin(),
                         vector_of_pairs.first.end());
  QVector<double> y_axis(vector_of_pairs.second.begin(),
                         vector_of_pairs.second.end());
  ui->graph_widget->addGraph();
  //  ui->graph_widget->legend->setVisible(true);
  ui->graph_widget->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
  ui->graph_widget->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
  ui->graph_widget->setInteraction(QCP::iRangeZoom, true);
  ui->graph_widget->setInteraction(QCP::iRangeDrag, true);
  ui->graph_widget->xAxis->setSubTickPen(QPen(Qt::blue, 1));
  ui->graph_widget->yAxis->setSubTickPen(QPen(Qt::blue, 1));
  ui->graph_widget->graph(0)->setData(x_axis, y_axis);
  ui->graph_widget->graph(0)->setPen(QPen(Qt ::green, 2));
  ui->graph_widget->graph(0)->setLineStyle(QCPGraph::lsLine);
  SetValueForAxisX(mmv.min_x_, mmv.max_x_, "X");
  SetValueForAxisY(mmv.min_y_, mmv.max_y_, "Y");
  ui->graph_widget->replot();
}

void PlotWindow::ClearPlot() {
  ui->graph_widget->clearGraphs();
  SetValueForAxisX(0, 5, " ");
  SetValueForAxisY(0, 5, " ");
  ui->graph_widget->replot();
}

void PlotWindow::SetValueForAxisX(double min, double max, QString name) {
  ui->graph_widget->xAxis->setRange(min, max);
  ui->graph_widget->xAxis->setLabel(name);
}

void PlotWindow::SetValueForAxisY(double min, double max, QString name) {
  ui->graph_widget->yAxis->setRange(min, max);
  ui->graph_widget->yAxis->setLabel(name);
}

#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include "model/s21_model.h"
#include <QMainWindow>

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit PlotWindow(QWidget *parent = nullptr);
  ~PlotWindow();
  //  void MakePlotArea(
  //      double min_x, double max_x, double min_y, double max_y,
  //      std::pair<std::vector<double>, std::vector<double>> vector_of_pairs);
  void MakePlotArea(
      s21::MaxMinValues values,
      std::pair<std::vector<double>, std::vector<double>> vector_of_pairs);
  void ClearPlot();

 private:
  Ui::PlotWindow *ui;
  void SetValueForAxisX(double, double, QString);
  void SetValueForAxisY(double, double, QString);
};

#endif  // PLOTWINDOW_H

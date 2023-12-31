#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>

#include "../model/model.h"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit PlotWindow(QWidget *parent = nullptr);
  ~PlotWindow();
  void MakePlotArea(
      smartcalc::MaxMinValues values,
      std::pair<std::vector<double>, std::vector<double>> vector_of_pairs,
      QString name);
  void ClearPlot();

 private:
  Ui::PlotWindow *ui;
  void SetValueForAxisX(double, double, QString);
  void SetValueForAxisY(double, double, QString);
};

#endif  // PLOTWINDOW_H

#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit PlotWindow(QWidget *parent = nullptr);
  ~PlotWindow();
  void MakePlotArea(
      double min_x, double max_x, double min_y, double max_y,
      std::pair<std::vector<double>, std::vector<double>> vector_of_pairs);
  void ClearPlot();

 private:
  Ui::PlotWindow *ui;
};

#endif  // PLOTWINDOW_H

#pragma once

#include <QLineEdit>

class LineEdit : public QLineEdit
{
public:
  LineEdit();

  void displayGauge(int progressPercentage);
  void hideGauge();
  
protected:
  void paintEvent(QPaintEvent* paintEvent);

private:
  // The original palette of the QLabel
  QPalette origPalette_;
  // Color of the background
  const QColor backgroundColor_;
  // Color of the darkened background (left part of the gauge)
  const QColor darkBackgroundColor_;
};

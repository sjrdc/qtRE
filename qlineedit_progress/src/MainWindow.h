#pragma once

#include <QWidget>
#include <QTimer>

class QCheckBox;
class QComboBox;
class QLabel;
class LineEdit;

class MainWindow : public QWidget
{
public:
  Q_OBJECT

public:
  MainWindow(QWidget *parent = Q_NULLPTR,
	     Qt::WindowFlags flags = Qt::WindowFlags());

protected slots:
  void onTimerTimeout();

protected:
  void createConnections();
  void setupUI();

  int progress_;
  QTimer timer_;
  LineEdit *lineEdit_;
};

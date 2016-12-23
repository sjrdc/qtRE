#pragma once

#include <QWidget>

class QComboBox;

class MainWindow : public QWidget
{
public:
  Q_OBJECT

public:
  MainWindow(QWidget *parent = Q_NULLPTR,
	     Qt::WindowFlags flags = Qt::WindowFlags());

protected slots:
  void onComboChanged(const QString &t);

protected:
  void createConnections();
  void setupUI();

  QComboBox *combobox_;
};

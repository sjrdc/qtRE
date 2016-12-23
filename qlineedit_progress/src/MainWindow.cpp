#include "MainWindow.h"
#include "LineEdit.h"

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent, flags),
    lineEdit_(new LineEdit())
{
  setupUI();
  createConnections();
  progress_ = 0;
  lineEdit_->setEnabled(false);
  timer_.start(200);
}


void MainWindow::setupUI()
{
  QLabel *patternLabel = new QLabel(tr("&Piet:"));
  patternLabel->setBuddy(lineEdit_);

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(patternLabel,              0, 0, 1, 1);
  layout->addWidget(lineEdit_,                  0, 1, 1, 3);
  this->setLayout(layout);
}

void MainWindow::createConnections()
{
  connect(&timer_, &QTimer::timeout,
	  this, &MainWindow::onTimerTimeout);
}

void MainWindow::onTimerTimeout()
{
  progress_ ++;
  if (progress_ > 100) progress_ = 0;
  lineEdit_->displayGauge(progress_);
}

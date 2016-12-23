#include "MainWindow.h"

#include <QComboBox>
#include <QCompleter>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent, flags),
    combobox_(new QComboBox)
{
  setupUI();
  combobox_->setEditable(true);
  combobox_->completer()->setCompletionMode(QCompleter::InlineCompletion);
  createConnections();
}


void MainWindow::setupUI()
{
  QLabel *patternLabel = new QLabel(tr("&Piet:"));
  patternLabel->setBuddy(combobox_);

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(patternLabel,              0, 0, 1, 1);
  layout->addWidget(combobox_,                 0, 1, 1, 3);
  this->setLayout(layout);
}

void MainWindow::createConnections()
{
  typedef void (QComboBox::*QComboStringSignal)(const QString &);
  connect(combobox_, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
	this, &MainWindow::onComboChanged);
}

void MainWindow::onComboChanged(const QString &t)
{
  qDebug() << t;
}

#include "MainWindow.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QWidget(parent, flags),
    caseSensitivityCheckBox_(new QCheckBox(tr("Case sensitive"))),
    pattern_(new QLineEdit),
    testString_(new QLineEdit),
    syntaxComboBox_(new QComboBox)
{
  setupUI();
  createConnections();
}


void MainWindow::setupUI()
{
  caseSensitivityCheckBox_->setChecked(true);
  QLabel *patternLabel = new QLabel(tr("&Regular expression:"));
  patternLabel->setBuddy(pattern_);

  QLabel *testStringLabel = new QLabel(tr("&Test string:"));
  testStringLabel->setBuddy(testString_);

  QLabel *syntaxLabel = new QLabel(tr(" &syntax:"));
  syntaxLabel->setBuddy(syntaxComboBox_);

  populateSyntaxComboBox();

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(patternLabel,              0, 0, 1, 1);
  layout->addWidget(pattern_,                  0, 1, 1, 2);
  layout->addWidget(testStringLabel,           1, 0, 1, 1);
  layout->addWidget(testString_,               1, 1, 1, 2);
  layout->addWidget(syntaxLabel,               2, 0, 1, 1);
  layout->addWidget(caseSensitivityCheckBox_,  2, 1, 1, 1);
  layout->addWidget(syntaxComboBox_,           2, 2, 1, 1);
  this->setLayout(layout);
}

void MainWindow::createConnections()
{
  connect(pattern_, &QLineEdit::returnPressed,
	  this, &MainWindow::onRegExpChanged);

  typedef void (QComboBox::*QComboIntSignal)(int);
  connect(syntaxComboBox_, static_cast<QComboIntSignal>(&QComboBox::currentIndexChanged),
	  this, &MainWindow::onRegExpChanged);

  connect(caseSensitivityCheckBox_, &QAbstractButton::toggled,
	  this, &MainWindow::onRegExpChanged);
}

void MainWindow::populateSyntaxComboBox()
{
  syntaxComboBox_->addItem(tr("Regular expression"), QRegExp::RegExp);
  syntaxComboBox_->addItem(tr("Wildcard"), QRegExp::Wildcard);
  syntaxComboBox_->addItem(tr("Fixed string"), QRegExp::FixedString);
}

void MainWindow::onRegExpChanged()
{
  QRegularExpression regexp(pattern_->text());
  if (!caseSensitivityCheckBox_->isChecked())
    regexp.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

  QRegExp::PatternSyntax syntax =
    QRegExp::PatternSyntax(syntaxComboBox_->itemData(syntaxComboBox_->currentIndex()).toInt());

  if (regexp.match(testString_->text()).hasMatch())
    qDebug() <<  regexp.match(testString_->text()).captured(0);
}

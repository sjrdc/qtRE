#pragma once

#include <QWidget>

class QCheckBox;
class QComboBox;
class QLabel;
class QLineEdit;

class MainWindow : public QWidget
{
public:
  Q_OBJECT

public:
  MainWindow(QWidget *parent = Q_NULLPTR,
	     Qt::WindowFlags flags = Qt::WindowFlags());

protected slots:
  void onRegExpChanged();

protected:
  void createConnections();
  void populateSyntaxComboBox();
  void setupUI();

  QLineEdit *pattern_;
  QLineEdit *testString_;
  QCheckBox *caseSensitivityCheckBox_;
  QComboBox *syntaxComboBox_;

};

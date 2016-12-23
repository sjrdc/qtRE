#include "LineEdit.h"

#include <QPainter>

LineEdit::LineEdit() :
  QLineEdit(),
  origPalette_(palette()),
  backgroundColor_(origPalette_.color( QPalette::Button)),
  darkBackgroundColor_(origPalette_.color( QPalette::Dark))
{
  setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed );
}

void LineEdit::displayGauge( int completion )
{
  int changeoverX = width() * completion / 100;

  // Create a gradient for the progress bar
  QLinearGradient linearGrad( changeoverX - 1, 0, changeoverX + 1, 0 );
  linearGrad.setColorAt( 0, darkBackgroundColor_ );
  linearGrad.setColorAt( 1, backgroundColor_ );

  // Apply the gradient to the current palette (background)
  QPalette newPalette = origPalette_;
  newPalette.setBrush( backgroundRole(), QBrush( linearGrad ) );
  setPalette( newPalette );
}

void LineEdit::hideGauge()
{
  setPalette( origPalette_ );
}

// Custom painter: draw the background then call QLabel's painter
void LineEdit::paintEvent( QPaintEvent* paintEvent )
{
  // Fill the widget background
  {
    QPainter painter( this );
    painter.fillRect( 0, 0, this->width(), this->height(),
		      palette().brush( backgroundRole() ) );
  }

  // Call the parent's painter
  QLineEdit::paintEvent( paintEvent );
}

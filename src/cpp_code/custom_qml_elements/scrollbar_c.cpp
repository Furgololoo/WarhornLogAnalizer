#include "scrollbar_c.h"

#include <QPainter>
#include <QPen>

ScrollBar_C::ScrollBar_C(QQuickItem *parent) {}

QColor ScrollBar_C::getBackgroundColor() const { return backgroundColor; }

void ScrollBar_C::setBackgroundColor(const QColor new_color) {
  backgroundColor = new_color;
}

QColor ScrollBar_C::getHandleColor() const { return handleColor; }

void ScrollBar_C::setHandleColor(const QColor new_color) {
  handleColor = new_color;
}

QColor ScrollBar_C::getForegroundColor() const { return foregroundColor; }

void ScrollBar_C::setForegroundColor(const QColor new_color) {
  foregroundColor = new_color;
}

void ScrollBar_C::paint(QPainter *painter) {
  QPen pen(backgroundColor, 2);

  painter->setPen(pen);
  painter->setRenderHints(QPainter::Antialiasing, true);
  painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
}

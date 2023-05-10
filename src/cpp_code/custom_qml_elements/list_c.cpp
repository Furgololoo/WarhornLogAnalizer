#include "list_c.h"

#include <QPainter>
#include <QPen>
#include <QQuickView>

List_C::List_C(QQuickItem *parent) : QQuickPaintedItem(parent) {}

QQmlComponent *List_C::getObj() const { return obj; }

void List_C::setObj(QQmlComponent *new_obj) { obj = new_obj; }

void List_C::test() {
  obj2 = component->create();
  item = qobject_cast<QQuickItem *>(obj2);
  item->setParentItem(this);
  item->setHeight(50);
  item->setWidth(50);
}

void List_C::test2() {
  component = new QQmlComponent(
      qmlEngine(this), QUrl(u"qrc:/qml/custom_components/LogEntry.qml"_qs));
}

void List_C::paint(QPainter *painter) {
  QPen pen(QColor("#FF0000"), 2);
  painter->setPen(pen);
  painter->setRenderHints(QPainter::Antialiasing, true);
  painter->drawRect(boundingRect());
}

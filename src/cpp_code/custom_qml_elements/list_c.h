#ifndef LIST_C_H
#define LIST_C_H

#include <QList>
#include <QQuickPaintedItem>

class QColumnView;

class List_C : public QQuickPaintedItem {
  Q_OBJECT

  Q_PROPERTY(QQmlComponent *obj READ getObj WRITE setObj NOTIFY objChanged)

  QML_ELEMENT
public:
  List_C(QQuickItem *parent = nullptr);

  QQmlComponent *getObj() const;
  void setObj(QQmlComponent *new_obj);

public slots:
  void test();
  void test2();

signals:

  void objChanged();

protected:
  void paint(QPainter *painter) override;

private:
  QObject *obj2;
  QQuickItem *item;
  QQmlComponent *obj;
  QQmlComponent *component;
};

#endif // LIST_C_H

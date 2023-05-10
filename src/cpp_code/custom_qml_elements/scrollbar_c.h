#ifndef SCROLLBAR_C_H
#define SCROLLBAR_C_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QScrollBar>

class ScrollBar_C : public QQuickPaintedItem {
  Q_OBJECT

  Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE
                 setBackgroundColor NOTIFY backgroundColorChanged)
  Q_PROPERTY(QColor handleColor READ getHandleColor WRITE setHandleColor NOTIFY
                 handleColorChanged)
  Q_PROPERTY(QColor foregroundColor READ getForegroundColor WRITE
                 setForegroundColor NOTIFY foregroundColorChanged)

  QML_ELEMENT
public:
  ScrollBar_C(QQuickItem *parent = nullptr);

  QColor getBackgroundColor() const;
  void setBackgroundColor(const QColor new_color);

  QColor getHandleColor() const;
  void setHandleColor(const QColor new_color);

  QColor getForegroundColor() const;
  void setForegroundColor(const QColor new_color);

signals:
  void backgroundColorChanged();
  void handleColorChanged();
  void foregroundColorChanged();

protected:
  void paint(QPainter *painter) override;

private:
  QColor backgroundColor;
  QColor handleColor;
  QColor foregroundColor;
};

#endif // SCROLLBAR_C_H

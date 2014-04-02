#ifndef COLORWIDGET_HPP_
#define COLORWIDGET_HPP_

#include <QWidget>

class QPaintEvent;

class ColorWidget: public QWidget
{
    Q_OBJECT
public:
    ColorWidget(QWidget *parent = 0);

public slots:
    void changeBackgroundColor(const QColor &backgroundColor);

protected:
    void paintEvent(QPaintEvent*);

private:
    QColor m_backgroundColor;
};

#endif  // COLORWIDGET_HPP_

#include <QPainter>
#include <QPaintEvent>
#include "./colorwidget.hpp"

ColorWidget::ColorWidget(QWidget *parent):
    QWidget(parent)
{}

void ColorWidget::changeBackgroundColor(const QColor &backgroundColor)
{
    m_backgroundColor = backgroundColor;
    repaint();
}

void ColorWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), m_backgroundColor);
}

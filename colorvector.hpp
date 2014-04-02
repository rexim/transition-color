#ifndef COLORVECTOR_HPP_
#define COLORVECTOR_HPP_

#include <tuple>

#include <QColor>

class ColorVector
{
public:
    using Tuple = std::tuple<qreal, qreal, qreal>;

    ColorVector(qreal red = 0, qreal green = 0, qreal blue = 0);

    Tuple asTuple() const;
    qreal length() const;
    ColorVector normalized() const;

private:
    std::tuple<qreal, qreal, qreal> m_components;
};

ColorVector operator* (const ColorVector &vec, qreal factor);
ColorVector operator- (const QColor &dest, const QColor &src);
QColor &operator+= (QColor &color, const ColorVector &vec);

#endif  // COLORVECTOR_HPP_

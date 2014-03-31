#include <algorithm>
#include <utility>
#include "./mathutils.hpp"
#include "./colorvector.hpp"

ColorVector::ColorVector(qreal red, qreal green, qreal blue):
    m_components(red, green, blue)
{}

ColorVector::Tuple ColorVector::asTuple() const
{
    return m_components;
}

qreal ColorVector::length() const
{
    qreal red, green, blue;
    std::tie(red, green, blue) = m_components;

    return std::sqrt(red * red + green * green + blue * blue);
}

ColorVector ColorVector::normalized() const
{
    qreal red, green, blue;
    qreal l = length();
    std::tie(red, green, blue) = m_components;
    return ColorVector(red / l, green / l, blue / l);
}

ColorVector operator* (const ColorVector &vec, qreal factor)
{
    qreal red, green, blue;
    std::tie(red, green, blue) = vec.asTuple();

    return ColorVector(red * factor,
                       green * factor,
                       blue * factor);
}

ColorVector operator- (const QColor &dest, const QColor &src)
{
    qreal destRed, destGreen, destBlue;
    qreal srcRed, srcGreen, srcBlue;
    dest.getRgbF(&destRed, &destGreen, &destBlue);
    src.getRgbF(&srcRed, &srcGreen, &srcBlue);

    return ColorVector(destRed - srcRed,
                       destGreen - srcGreen,
                       destBlue - srcBlue);
}

QColor &operator+= (QColor &color, const ColorVector &vec)
{
    using MathUtils::between;

    qreal red, green, blue;
    qreal vred, vgreen, vblue;
    color.getRgbF(&red, &green, &blue);
    std::tie(vred, vgreen, vblue) = vec.asTuple();

    color.setRgbF(between(red + vred, 0.0, 1.0),
                  between(green + vgreen, 0.0, 1.0),
                  between(blue + vblue, 0.0, 1.0));

    return color;
}

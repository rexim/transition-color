#ifndef MATHUTILS_HPP_
#define MATHUTILS_HPP_

#include <algorithm>

namespace MathUtils {

    template <typename T>
    T between(const T &x, const T &low, const T &high)
    {
        return std::min(high, std::max(low, x));
    }

}  // namespace MathUtils

#endif  // MATHUTILS_HPP_

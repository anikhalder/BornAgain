#include "FootprintFactorSquare.h"
#include "MathConstants.h"
#include <algorithm>
#include <stdexcept>

FootprintFactorSquare::FootprintFactorSquare(double width_ratio) : IFootprintFactor(width_ratio)
{
    initialize();
}

FootprintFactorSquare* FootprintFactorSquare::clone() const
{
    return new FootprintFactorSquare(*this);
}

double FootprintFactorSquare::calculate(double alpha) const
{
    if (alpha < 0.0 || alpha > M_PI_2)
        return 0.0;
    if (widthRatio() == 0.0)
        return 1.0;
    const double arg = std::sin(alpha) / widthRatio();
    return std::min(arg, 1.0);
}

FootprintFactorSquare::FootprintFactorSquare(const FootprintFactorSquare& other)
    : IFootprintFactor(other)
{
    initialize();
}

void FootprintFactorSquare::initialize()
{
    setName(BornAgain::SquareFootprintFactorType);
}

static_assert(!std::is_copy_constructible<FootprintFactorSquare>::value,
              "FootprintFactorSquare should not be copy constructable");
static_assert(!std::is_copy_assignable<FootprintFactorSquare>::value,
              "FootprintFactorSquare should not be copy assignable");

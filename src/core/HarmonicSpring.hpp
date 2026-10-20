#pragma once

#include <algorithm>
#include <cmath>

struct HarmonicSpring
{
    double position = 0.0;
    double velocity = 0.0;
    double zeta = 0.82;
    double omega = 18.0;

    void reset(double value) noexcept
    {
        position = value;
        velocity = 0.0;
    }

    void step(double target, double deltaSeconds) noexcept
    {
        const double dt = std::clamp(deltaSeconds, 0.0, 1.0 / 20.0);
        const double acceleration = omega * omega * (target - position)
            - 2.0 * zeta * omega * velocity;
        velocity += acceleration * dt;
        position += velocity * dt;
    }
};

#pragma once

#include "utils/glm_utils.h"


namespace transform2D
{
    // Translate matrix
    inline glm::mat3 Translate(float translateX, float translateY)
    {
        // TODO(student): Implement the translation matrix
        return glm::mat3(1.f, 0.f, 0.f,
            0.f, 1.f, 0.f,
            translateX, translateY, 1.f);

    }

    // Scale matrix
    inline glm::mat3 Scale(float scaleX, float scaleY)
    {
        // TODO(student): Implement the scaling matrix
        return glm::mat3(scaleX, 0.f, 0.f,
            0.f, scaleY, 0.f,
            0.f, 0.f, 1.f);

    }

    // Rotate matrix
    inline glm::mat3 Rotate(float radians)
    {
        // TODO(student): Implement the rotation matrix
        float co = cos(radians), si = sin(radians);
        return glm::mat3(co, si, 0.f,
            -si, co, 0.f,
            0.f, 0.f, 1.f);

    }
}   // namespace transform2D

#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name,
        glm::vec3 leftBottomCorner,
        float length,
        glm::vec3 color,
        bool fill = false);

    Mesh* CreateRectangle(const std::string& name,
        glm::vec3 leftBottomCorner,
        float width,
        float height,
        glm::vec3 color,
        bool fill = false);

    Mesh* CreateRhombus(const std::string& name,
        glm::vec3 center,
        float diagonalLength1,
        float diagonalLength2,
        glm::vec3 color,
        bool fill);

    Mesh* CreateCustom(const std::string& name,
        glm::vec3 center,
        float diagonalLength1,
        float diagonalLength2,
        glm::vec3 color,
        bool fill);

    Mesh* CreateStar(
        const std::string& name,
        glm::vec3 center,
        float outerRadius,
        float innerRadius,
        glm::vec3 color,
        bool fill,
        float innerOffset);

    Mesh* CreateHexagons(
        const std::string& name,
        glm::vec3 center,
        float outerSideLength,
        glm::vec3 outerColor,
        float innerSideLength,
        glm::vec3 innerColor,
        bool fill);
}

#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateRhombus(
    const std::string& name,
    glm::vec3 center,
    float diagonalLength1,
    float diagonalLength2,
    glm::vec3 color,
    bool fill)
{
    float halfDiagonal1 = diagonalLength1 * 0.5f;
    float halfDiagonal2 = diagonalLength2 * 0.5f;

    glm::vec3 top = center + glm::vec3(0, halfDiagonal1, 0);
    glm::vec3 right = center + glm::vec3(halfDiagonal2, 0, 0);
    glm::vec3 bottom = center + glm::vec3(0, -halfDiagonal1, 0);
    glm::vec3 left = center + glm::vec3(-halfDiagonal2, 0, 0);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(top, color),
        VertexFormat(right, color),
        VertexFormat(bottom, color),
        VertexFormat(left, color)
    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rhombus->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);
    }

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}

Mesh* object2D::CreateCustom(
    const std::string& name,
    glm::vec3 center,
    float diagonalLength1,
    float diagonalLength2,
    glm::vec3 color,
    bool fill)
{
    float halfDiagonal1 = diagonalLength1 * 0.5f;
    float halfDiagonal2 = diagonalLength2 * 0.5f;

    glm::vec3 top = center + glm::vec3(0, halfDiagonal1, 1);
    glm::vec3 right = center + glm::vec3(halfDiagonal2, 0, 1);
    glm::vec3 bottom = center + glm::vec3(0, -halfDiagonal1, 1);
    glm::vec3 left = center + glm::vec3(-halfDiagonal2, 0, 1);
    glm::vec3 topRight = center + glm::vec3(halfDiagonal2 * 0.5f, halfDiagonal1 * 0.25f, 1);
    glm::vec3 bottomRight = center + glm::vec3(halfDiagonal2 * 0.5f, -halfDiagonal1 * 0.25f, 1);
    glm::vec3 toprectangle = center + glm::vec3(diagonalLength2, halfDiagonal1 * 0.25f, 1);
    glm::vec3 bottomrectangle = center + glm::vec3(diagonalLength2, -halfDiagonal1 * 0.25f, 1);

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(top, color),
        VertexFormat(topRight, color),
        VertexFormat(toprectangle, color),
        VertexFormat(bottomrectangle, color),
        VertexFormat(bottomRight, color),
        VertexFormat(right, color),
        VertexFormat(bottom, color),
        VertexFormat(left, color),

    };

    Mesh* custom = new Mesh(name);
    std::vector<unsigned int> indices = {
        0, 7, 5,
        7, 6, 5,
        1, 4, 2,
        4, 3, 2 };

    if (!fill) {
        custom->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);

    }

    custom->InitFromData(vertices, indices);
    return custom;
}

Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 center,
    float outerRadius,
    float innerRadius,
    glm::vec3 color,
    bool fill,
    float innerOffset)
{
    const float pi = 3.14159265358979323846f;
    const float angleIncrement = 2.0f * pi / 5.0f;


    glm::vec3 outer1 = center + glm::vec3(cos(0 * angleIncrement) * outerRadius, sin(0 * angleIncrement) * outerRadius, 1);
    glm::vec3 outer2 = center + glm::vec3(cos(1 * angleIncrement) * outerRadius, sin(1 * angleIncrement) * outerRadius, 1);
    glm::vec3 outer3 = center + glm::vec3(cos(2 * angleIncrement) * outerRadius, sin(2 * angleIncrement) * outerRadius, 1);
    glm::vec3 outer4 = center + glm::vec3(cos(3 * angleIncrement) * outerRadius, sin(3 * angleIncrement) * outerRadius, 1);
    glm::vec3 outer5 = center + glm::vec3(cos(4 * angleIncrement) * outerRadius, sin(4 * angleIncrement) * outerRadius, 1);

    glm::vec3 inner1 = center + glm::vec3(cos(0.5f * angleIncrement) * (innerRadius - innerOffset), sin(0.5f * angleIncrement) * (innerRadius - innerOffset), 1);
    glm::vec3 inner2 = center + glm::vec3(cos(1.5f * angleIncrement) * (innerRadius - innerOffset), sin(1.5f * angleIncrement) * (innerRadius - innerOffset), 1);
    glm::vec3 inner3 = center + glm::vec3(cos(2.5f * angleIncrement) * (innerRadius - innerOffset), sin(2.5f * angleIncrement) * (innerRadius - innerOffset), 1);
    glm::vec3 inner4 = center + glm::vec3(cos(3.5f * angleIncrement) * (innerRadius - innerOffset), sin(3.5f * angleIncrement) * (innerRadius - innerOffset), 1);
    glm::vec3 inner5 = center + glm::vec3(cos(4.5f * angleIncrement) * (innerRadius - innerOffset), sin(4.5f * angleIncrement) * (innerRadius - innerOffset), 1);

    std::vector<VertexFormat> vertices = {
        VertexFormat(outer1, color),
        VertexFormat(inner1, color),
        VertexFormat(outer2, color),
        VertexFormat(inner2, color),
        VertexFormat(outer3, color),
        VertexFormat(inner3, color),
        VertexFormat(outer4, color),
        VertexFormat(inner4, color),
        VertexFormat(outer5, color),
        VertexFormat(inner5, color),

    };


    Mesh* star = new Mesh(name);

    std::vector<unsigned int> indices = {
        0, 9, 1,
        1, 3, 2,
        4, 5, 3,
        6, 7, 5,
        8, 9, 7,
        1, 3, 5,
        1, 5, 7,
        1, 7, 9,
    };

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);

    }

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* object2D::CreateHexagons(
    const std::string& name,
    glm::vec3 center,
    float outerSideLength,
    glm::vec3 outerColor,
    float innerSideLength,
    glm::vec3 innerColor,
    bool fill)
{
    const float pi = 3.14159265358979323846f;
    const float angleIncrement = 2.0f * pi / 6.0f;

    glm::vec3 outer1 = center + glm::vec3(cos(0 * angleIncrement) * outerSideLength, sin(0 * angleIncrement) * outerSideLength, 1);
    glm::vec3 outer2 = center + glm::vec3(cos(1 * angleIncrement) * outerSideLength, sin(1 * angleIncrement) * outerSideLength, 1);
    glm::vec3 outer3 = center + glm::vec3(cos(2 * angleIncrement) * outerSideLength, sin(2 * angleIncrement) * outerSideLength, 1);
    glm::vec3 outer4 = center + glm::vec3(cos(3 * angleIncrement) * outerSideLength, sin(3 * angleIncrement) * outerSideLength, 1);
    glm::vec3 outer5 = center + glm::vec3(cos(4 * angleIncrement) * outerSideLength, sin(4 * angleIncrement) * outerSideLength, 1);
    glm::vec3 outer6 = center + glm::vec3(cos(5 * angleIncrement) * outerSideLength, sin(5 * angleIncrement) * outerSideLength, 1);

    glm::vec3 inner1 = center + glm::vec3(cos(0 * angleIncrement) * innerSideLength, sin(0 * angleIncrement) * innerSideLength, 2);
    glm::vec3 inner2 = center + glm::vec3(cos(1 * angleIncrement) * innerSideLength, sin(1 * angleIncrement) * innerSideLength, 2);
    glm::vec3 inner3 = center + glm::vec3(cos(2 * angleIncrement) * innerSideLength, sin(2 * angleIncrement) * innerSideLength, 2);
    glm::vec3 inner4 = center + glm::vec3(cos(3 * angleIncrement) * innerSideLength, sin(3 * angleIncrement) * innerSideLength, 2);
    glm::vec3 inner5 = center + glm::vec3(cos(4 * angleIncrement) * innerSideLength, sin(4 * angleIncrement) * innerSideLength, 2);
    glm::vec3 inner6 = center + glm::vec3(cos(5 * angleIncrement) * innerSideLength, sin(5 * angleIncrement) * innerSideLength, 2);


    std::vector<VertexFormat> vertices = {

     VertexFormat(outer1, outerColor),
     VertexFormat(inner1, innerColor),
     VertexFormat(outer2, outerColor),
     VertexFormat(inner2, innerColor),
     VertexFormat(outer3, outerColor),
     VertexFormat(inner3, innerColor),
     VertexFormat(outer4, outerColor),
     VertexFormat(inner4, innerColor),
     VertexFormat(outer5, outerColor),
     VertexFormat(inner5, innerColor),
     VertexFormat(outer6, outerColor),
     VertexFormat(inner6, innerColor),


    };


    Mesh* nestedHexagons = new Mesh(name);


    std::vector<unsigned int> indices = {
           0 , 2, 4,
           6 , 8, 10,
           10, 6, 0,
           4, 6, 0,
           1, 3, 5,
           7, 9, 11,
           11, 7, 1,
           5, 7, 1,
    };

    if (!fill) {
        nestedHexagons->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
        indices.push_back(2);

    }


    nestedHexagons->InitFromData(vertices, indices);
    return nestedHexagons;
}
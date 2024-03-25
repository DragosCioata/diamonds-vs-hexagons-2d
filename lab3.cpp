#include "lab_m1/lab3/lab3.h"

#include <vector>
#include <iostream>
#include <chrono>

#include "lab_m1/lab3/transform2D.h"
#include "lab_m1/lab3/object2D.h"

using namespace std;
using namespace m1;


Lab3::Lab3()
{
}


Lab3::~Lab3()
{
}


void Lab3::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    float cx = corner.x + squareSide / 2;
    float cy = corner.y + squareSide / 2;

    translateX = 0;
    translateY = 0;
    scaleX = 1;
    scaleY = 1;

    angularStep = 0;

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square1);

    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square2);

    Mesh* square3 = object2D::CreateSquare("square3", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square3);

    Mesh* square4 = object2D::CreateSquare("square4", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square4);

    Mesh* square5 = object2D::CreateSquare("square5", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square5);

    Mesh* square6 = object2D::CreateSquare("square6", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square6);

    Mesh* square7 = object2D::CreateSquare("square7", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square7);

    Mesh* square8 = object2D::CreateSquare("square8", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square8);

    Mesh* square9 = object2D::CreateSquare("square9", corner, squareSide, glm::vec3(0.23137f, 0.89020f, 0.41961f), true);
    AddMeshToList(square9);

    Mesh* turret1square = object2D::CreateSquare("turret1square", corner, squareSide, glm::vec3(0.04706f, 0.04706f, 0.04706f), false);
    AddMeshToList(turret1square);

    Mesh* turret2square = object2D::CreateSquare("turret2square", corner, squareSide, glm::vec3(0.04706f, 0.04706f, 0.04706f), false);
    AddMeshToList(turret2square);

    Mesh* turret3square = object2D::CreateSquare("turret3square", corner, squareSide, glm::vec3(0.04706f, 0.04706f, 0.04706f), false);
    AddMeshToList(turret3square);

    Mesh* turret4square = object2D::CreateSquare("turret4square", corner, squareSide, glm::vec3(0.04706f, 0.04706f, 0.04706f), false);
    AddMeshToList(turret4square);

    Mesh* life1 = object2D::CreateSquare("life1", corner, 0.65f * squareSide, glm::vec3(0.79608f, 0.01176f, 0.01176f), true);
    AddMeshToList(life1);

    Mesh* life2 = object2D::CreateSquare("life2", corner, 0.65f * squareSide, glm::vec3(0.79608f, 0.01176f, 0.01176f), true);
    AddMeshToList(life2);

    Mesh* life3 = object2D::CreateSquare("life3", corner, 0.65f * squareSide, glm::vec3(0.79608f, 0.01176f, 0.01176f), true);
    AddMeshToList(life3);

    Mesh* gameloss = object2D::CreateRectangle("gameloss", corner, rectangleX, rectangleY, glm::vec3(0.79608f, 0.01176f, 0.01176f), true);
    AddMeshToList(gameloss);

    Mesh* turret1 = object2D::CreateCustom("turret1", corner, 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
    AddMeshToList(turret1);

    Mesh* turret2 = object2D::CreateCustom("turret2", corner, 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
    AddMeshToList(turret2);

    Mesh* turret3 = object2D::CreateCustom("turret3", corner, 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
    AddMeshToList(turret3);

    Mesh* turret4 = object2D::CreateCustom("turret4", corner, 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
    AddMeshToList(turret4);

    Mesh* turret1place = object2D::CreateCustom("turret1place", corner, 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
    AddMeshToList(turret1place);

    Mesh* turret2place = object2D::CreateCustom("turret2place", corner, 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
    AddMeshToList(turret2place);

    Mesh* turret3place = object2D::CreateCustom("turret3place", corner, 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
    AddMeshToList(turret3place);

    Mesh* turret4place = object2D::CreateCustom("turret4place", corner, 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
    AddMeshToList(turret4place);

    Mesh* star1 = object2D::CreateStar("star1", corner, 40, 20, glm::vec3(0.99608f, 0.00000f, 0.91765f), true, 6.0f);
    AddMeshToList(star1);

    Mesh* star2 = object2D::CreateStar("star2", corner, 40, 20, glm::vec3(0.99608f, 0.00000f, 0.91765f), true, 6.0f);
    AddMeshToList(star2);

    Mesh* star3 = object2D::CreateStar("star3", corner, 40, 20, glm::vec3(0.99608f, 0.00000f, 0.91765f), true, 6.0f);
    AddMeshToList(star3);

    Mesh* projectile1 = object2D::CreateStar("projectile1", corner, 46, 23, glm::vec3(0.97255f, 0.37255f, 0.00784f), true, 6.0f);
    AddMeshToList(projectile1);

    Mesh* projectile2 = object2D::CreateStar("projectile2", corner, 46, 23, glm::vec3(0.01176F, 0.38431f, 0.98824f), true, 6.0f);
    AddMeshToList(projectile2);

    Mesh* projectile3 = object2D::CreateStar("projectile3", corner, 46, 23, glm::vec3(0.98824f, 0.83137f, 0.01176f), true, 6.0f);
    AddMeshToList(projectile3);

    Mesh* projectile4 = object2D::CreateStar("projectile4", corner, 46, 23, glm::vec3(0.66275f, 0.01176f, 0.98431f), true, 6.0f);
    AddMeshToList(projectile4);

    Mesh* enemy1 = object2D::CreateHexagons("enemy1", corner, 45, glm::vec3(0.97255f, 0.37255f, 0.00784f), 30, glm::vec3(0.19608f, 0.65882f, 0.64314f), true);
    AddMeshToList(enemy1);

    Mesh* enemy2 = object2D::CreateHexagons("enemy2", corner, 45, glm::vec3(0.01176F, 0.38431f, 0.98824f), 30, glm::vec3(0.19608f, 0.65882f, 0.64314f), true);
    AddMeshToList(enemy2);

    Mesh* enemy3 = object2D::CreateHexagons("enemy3", corner, 45, glm::vec3(0.98824f, 0.83137f, 0.01176f), 30, glm::vec3(0.19608f, 0.65882f, 0.64314f), true);
    AddMeshToList(enemy3);

    Mesh* enemy4 = object2D::CreateHexagons("enemy4", corner, 45, glm::vec3(0.66275f, 0.01176f, 0.98431f), 30, glm::vec3(0.19608f, 0.65882f, 0.64314f), true);
    AddMeshToList(enemy4);

    Mesh* smallstar = object2D::CreateStar("smallstar", corner, 22, 11, glm::vec3(0.60000f, 0.60000f, 0.60000f), true, 2.0f);
    AddMeshToList(smallstar);

    for (i = 0; i < 100; i++) {
        enemy1LifeDecreased[i] = false;
        enemy2LifeDecreased[i] = false;
        enemy3LifeDecreased[i] = false;
        enemy4LifeDecreased[i] = false;

    }
}


void Lab3::FrameStart()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}


void Lab3::Update(float deltaTimeSeconds)
{

    glm::ivec2 resolution = window->GetResolution();
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(110, 25);
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(110, 185);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(110, 345);
    RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(270, 25);
    RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(270, 185);
    RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(270, 345);
    RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(430, 25);
    RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(430, 185);
    RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(430, 345);
    RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(15, 25);
    RenderMesh2D(meshes["gameloss"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(turret1X, turret1Y);
    //modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
    RenderMesh2D(meshes["turret1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(turret2X, turret2Y);
    //modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
    RenderMesh2D(meshes["turret2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(turret3X, turret3Y);
    // modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
    RenderMesh2D(meshes["turret3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(turret4X, turret4Y);
    // modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
    RenderMesh2D(meshes["turret4"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(115.0f, 640.0f);
    RenderMesh2D(meshes["turret1place"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(315.0f, 640.0f);
    RenderMesh2D(meshes["turret2place"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(515.0f, 640.0f);
    RenderMesh2D(meshes["turret3place"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(715.0f, 640.0f);
    RenderMesh2D(meshes["turret4place"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1100.0f, 300.0f);
    modelMatrix *= transform2D::Rotate(-3.14f / 16);
    modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
    RenderMesh2D(meshes["enemy1"], shaders["VertexColor"], modelMatrix);



    static auto startTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    float elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

    if (elapsedTime >= 9.0f && kont + 3 <= starcount) {
        for (size_t i = kont; i < kont + 3; ++i) {
            starX[i] = std::rand() % 1231 + 25;
            starY[i] = std::rand() % 476 + 25;
            startTime = std::chrono::high_resolution_clock::now();
        }
        kont += 3;
        starcount += 3;
    }


    startvalue -= scaleSpeed * deltaTimeSeconds;
    startvalue = glm::max(startvalue, 0.0f);
    static auto startTimeenemy = std::chrono::high_resolution_clock::now();
    float elapsedTimeenemy = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTimeenemy).count();


    if (elapsedTimeenemy >= randomtime) {
        if (randomenemy == 1) {
            if (randomline == 1) {
                enemy1X[enemycount1] = 1350.0f;
                enemy1Y[enemycount1] = 80.0f;
                enemycount1++;
                enemyaddcount++;
            }
            else if (randomline == 2) {
                enemy1X[enemycount1] = 1350.0f;
                enemy1Y[enemycount1] = 245.0f;
                enemycount1++;
                enemyaddcount++;

            }
            else if (randomline == 3) {
                enemy1X[enemycount1] = 1350.0f;
                enemy1Y[enemycount1] = 405.0f;
                enemycount1++;
                enemyaddcount++;

            }

        }
        else if (randomenemy == 2) {
            if (randomline == 1) {
                enemy2X[enemycount2] = 1350.0f;
                enemy2Y[enemycount2] = 80.0f;
                enemycount2++;
                enemyaddcount++;

            }
            else if (randomline == 2) {
                enemy2X[enemycount2] = 1350.0f;
                enemy2Y[enemycount2] = 245.0f;;
                enemycount2++;
                enemyaddcount++;

            }
            else if (randomline == 3) {
                enemy2X[enemycount2] = 1350.0f;
                enemy2Y[enemycount2] = 405.0f;
                enemycount2++;
                enemyaddcount++;

            }

        }
        else if (randomenemy == 3) {
            if (randomline == 1) {
                enemy3X[enemycount3] = 1350.0f;
                enemy3Y[enemycount3] = 80.0f;
                enemycount3++;
                enemyaddcount++;

            }
            else if (randomline == 2) {
                enemy3X[enemycount3] = 1350.0f;
                enemy3Y[enemycount3] = 245.0f;
                enemycount3++;
                enemyaddcount++;

            }
            else if (randomline == 3) {
                enemy3X[enemycount3] = 1350.0f;
                enemy3Y[enemycount3] = 405.0f;
                enemycount3++;
                enemyaddcount++;

            }

        }
        else if (randomenemy == 4) {
            if (randomline == 1) {
                enemy4X[enemycount4] = 1350.0f;
                enemy4Y[enemycount4] = 80.0f;
                enemycount4++;
                enemyaddcount++;

            }
            else if (randomline == 2) {
                enemy4X[enemycount4] = 1350.0f;
                enemy4Y[enemycount4] = 245.0f;
                enemycount4++;
                enemyaddcount++;

            }
            else if (randomline == 3) {
                enemy4X[enemycount4] = 1350.0f;
                enemy4Y[enemycount4] = 405.0f;
                enemycount4++;
                enemyaddcount++;

            }

        }
        randomline = std::rand() % 3 + 1;
        randomenemy = std::rand() % 4 + 1;
        randomtime = (std::rand() % 201 + 400) / 100.0f;
        startTimeenemy = std::chrono::high_resolution_clock::now();
    }



    for (i = 0; i < enemycount1; ++i) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(enemy1X[i], enemy1Y[i]);
        modelMatrix *= transform2D::Rotate(-3.14f / 16);
        //modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
        RenderMesh2D(meshes["enemy1"], shaders["VertexColor"], modelMatrix);
        enemy1X[i] -= enemySpeed * deltaTimeSeconds;
        if (enemy1X[i] < 40.0f && !enemy1LifeDecreased[i]) {
            life -= 1;
            enemy1LifeDecreased[i] = true;
        }

    }

    for (i = 0; i < enemycount2; ++i) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(enemy2X[i], enemy2Y[i]);
        modelMatrix *= transform2D::Rotate(-3.14f / 16);
        //modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
        RenderMesh2D(meshes["enemy2"], shaders["VertexColor"], modelMatrix);
        enemy2X[i] -= enemySpeed * deltaTimeSeconds;


        if (enemy2X[i] < 40.0f && !enemy2LifeDecreased[i]) {
            life -= 1;
            enemy2LifeDecreased[i] = true;
        }
    }

    for (i = 0; i < enemycount3; ++i) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(enemy3X[i], enemy3Y[i]);
        modelMatrix *= transform2D::Rotate(-3.14f / 16);
        //modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
        RenderMesh2D(meshes["enemy3"], shaders["VertexColor"], modelMatrix);
        enemy3X[i] -= enemySpeed * deltaTimeSeconds;

        if (enemy3X[i] < 40.0f && !enemy3LifeDecreased[i]) {
            life -= 1;
            enemy3LifeDecreased[i] = true;
        }

    }

    for (i = 0; i < enemycount4; ++i) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(enemy4X[i], enemy4Y[i]);
        modelMatrix *= transform2D::Rotate(-3.14f / 16);
        //modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
        RenderMesh2D(meshes["enemy4"], shaders["VertexColor"], modelMatrix);
        enemy4X[i] -= enemySpeed * deltaTimeSeconds;

        if (enemy4X[i] < 40.0f && !enemy4LifeDecreased[i]) {
            life -= 1;
            enemy4LifeDecreased[i] = true;
        }

    }


    for (int i = 0; i < starcount - 3; ++i)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(starX[i], starY[i]);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);
    }

    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star1X, star1Y);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["star2"], shaders["VertexColor"], modelMatrix);
    }

    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star2X, star2Y);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);
    }

    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star3X, star3Y);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["star3"], shaders["VertexColor"], modelMatrix);
    }


    projectile1X += 4.0f * enemySpeed * deltaTimeSeconds;
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(projectile1X, 150);
    modelMatrix *= transform2D::Rotate(-projectile1X * 0.02f);
    RenderMesh2D(meshes["projectile1"], shaders["VertexColor"], modelMatrix);

    projectile2X += 4.0f * enemySpeed * deltaTimeSeconds;
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(projectile2X, 150);
    modelMatrix *= transform2D::Rotate(-projectile2X * 0.02f);
    RenderMesh2D(meshes["projectile2"], shaders["VertexColor"], modelMatrix);

    projectile3X += 4.0f * enemySpeed * deltaTimeSeconds;
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(projectile3X, 300);
    modelMatrix *= transform2D::Rotate(-projectile3X * 0.02f);
    RenderMesh2D(meshes["projectile3"], shaders["VertexColor"], modelMatrix);

    projectile4X += 4.0f * enemySpeed * deltaTimeSeconds;
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(projectile4X, 300);
    modelMatrix *= transform2D::Rotate(-projectile4X * 0.02f);
    RenderMesh2D(meshes["projectile4"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(60, 585);
    RenderMesh2D(meshes["turret1square"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(260, 585);
    RenderMesh2D(meshes["turret2square"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(460, 585);
    RenderMesh2D(meshes["turret3square"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(660, 585);
    RenderMesh2D(meshes["turret4square"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(life1X, lifeY);
    RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(life2X, lifeY);
    RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(life3X, lifeY);
    RenderMesh2D(meshes["life3"], shaders["VertexColor"], modelMatrix);

    if (life == 2) {
        life3X = 2000.0f;
    }

    if (life == 1) {
        life2X = 2000.0f;
    }

    if (life == 0) {
        std::exit(0);
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(70, 560);
    modelMatrix *= transform2D::Rotate(3.14f / 2);
    RenderMesh2D(meshes["smallstar"], shaders["VertexColor"], modelMatrix);

    for (i = 270; i < 330; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i, 560);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["smallstar"], shaders["VertexColor"], modelMatrix);
    }

    for (i = 470; i < 530; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i, 560);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["smallstar"], shaders["VertexColor"], modelMatrix);
    }

    for (i = 670; i < 780; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i, 560);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["smallstar"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 860; i < 870 + (starturret - 1) * 50; i = i + 50) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i, 580);
        modelMatrix *= transform2D::Rotate(3.14f / 2);
        RenderMesh2D(meshes["smallstar"], shaders["VertexColor"], modelMatrix);
    }

    for (j = 0; j <= turretcount; j++) {
        modelMatrix = glm::mat3(1);
        RenderMesh2D(meshes["turrettest" + to_string(j)], shaders["VertexColor"], modelMatrix);

    }
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1000, 400);
    modelMatrix *= transform2D::Scale(-startvalue, -startvalue);
    RenderMesh2D(meshes["turret1"], shaders["VertexColor"], modelMatrix);

}

void Lab3::FrameEnd()
{
}




void Lab3::OnInputUpdate(float deltaTime, int mods)
{
}


void Lab3::OnKeyPress(int key, int mods)
{

}


void Lab3::OnKeyRelease(int key, int mods)
{

}


void Lab3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    if (isTurret1Dragged) {
        turret1X += deltaX;
        turret1Y -= deltaY;
    }
    else if (isTurret2Dragged) {
        turret2X += deltaX;
        turret2Y -= deltaY;
    }
    else if (isTurret3Dragged) {
        turret3X += deltaX;
        turret3Y -= deltaY;
    }
    else if (isTurret4Dragged) {
        turret4X += deltaX;
        turret4Y -= deltaY;
    }
}


void Lab3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{

    if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {

        if (mouseX >= 60 && mouseX <= 175 && mouseY >= 20 && mouseY <= 135 && starturret >= 1) {
            isTurret1Dragged = true;
        }
        if (mouseX >= 260 && mouseX <= 375 && mouseY >= 20 && mouseY <= 135 && starturret >= 2) {
            isTurret2Dragged = true;
        }
        if (mouseX >= 460 && mouseX <= 575 && mouseY >= 20 && mouseY <= 135 && starturret >= 2) {
            isTurret3Dragged = true;
        }
        if (mouseX >= 660 && mouseX <= 775 && mouseY >= 20 && mouseY <= 135 && starturret >= 3) {
            isTurret4Dragged = true;
        }

        float clickRadius = 40.0f;

        for (size_t i = 0; i < starcount; ++i) {
            if (mouseX >= (starX[i] - clickRadius) && mouseX <= (starX[i] + clickRadius) &&
                mouseY >= (720 - starY[i] - clickRadius) && mouseY <= (720 - starY[i] + clickRadius)) {
                starX[i] = 1500.0f;
                starY[i] = 200.0f;
                starturret++;
            }

        }

        if (mouseX >= (star1X - clickRadius) && mouseX <= (star1X + clickRadius) &&
            mouseY >= (720 - star1Y - clickRadius) && mouseY <= (720 - star1Y + clickRadius)) {
            star1X = 1500.0f;
            star1Y = 200.0f;
            starturret++;
        }

        if (mouseX >= (star2X - clickRadius) && mouseX <= (star2X + clickRadius) &&
            mouseY >= (720 - star2Y - clickRadius) && mouseY <= (720 - star2Y + clickRadius)) {
            star2X = 1500.0f;
            star2Y = 200.0f;
            starturret++;
        }

        if (mouseX >= (star3X - clickRadius) && mouseX <= (star3X + clickRadius) &&
            mouseY >= (720 - star3Y - clickRadius) && mouseY <= (720 - star3Y + clickRadius)) {
            star3X = 1500.0f;
            star3Y = 200.0f;
            starturret++;
        }
    }

    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) {
        if (mouseX >= 110 && mouseX <= 225 && mouseY >= 580 && mouseY <= 695) {
            if (occupiedPositions[0][1] == 1)
                turretdel[0][1] = 1;
            else if (occupiedPositions[0][2] == 1)
                turretdel[0][2] = 1;
            else if (occupiedPositions[0][3] == 1)
                turretdel[0][3] = 1;
            else if (occupiedPositions[0][4] == 1)
                turretdel[0][4] = 1;
        }

        if (mouseX >= 270 && mouseX <= 385 && mouseY >= 580 && mouseY <= 695) {
            if (occupiedPositions[1][1] == 1)
                turretdel[1][1] = 1;
            else if (occupiedPositions[1][2] == 1)
                turretdel[1][2] = 1;
            else if (occupiedPositions[1][3] == 1)
                turretdel[1][3] = 1;
            else if (occupiedPositions[1][4] == 1)
                turretdel[1][4] = 1;
        }

        if (mouseX >= 430 && mouseX <= 545 && mouseY >= 580 && mouseY <= 695) {
            if (occupiedPositions[2][1] == 1)
                turretdel[2][1] = 1;
            else if (occupiedPositions[2][2] == 1)
                turretdel[2][2] = 1;
            else if (occupiedPositions[2][3] == 1)
                turretdel[2][3] = 1;
            else if (occupiedPositions[2][4] == 1)
                turretdel[2][4] = 1;
        }

        if (mouseX >= 110 && mouseX <= 225 && mouseY >= 420 && mouseY <= 535) {
            if (occupiedPositions[3][1] == 1)
                turretdel[3][1] = 1;
            else if (occupiedPositions[3][2] == 1)
                turretdel[3][2] = 1;
            else if (occupiedPositions[3][3] == 1)
                turretdel[3][3] = 1;
            else if (occupiedPositions[3][4] == 1)
                turretdel[3][4] = 1;
        }

        if (mouseX >= 270 && mouseX <= 385 && mouseY >= 420 && mouseY <= 535) {
            if (occupiedPositions[4][1] == 1)
                turretdel[4][1] = 1;
            else if (occupiedPositions[4][2] == 1)
                turretdel[4][2] = 1;
            else if (occupiedPositions[4][3] == 1)
                turretdel[4][3] = 1;
            else if (occupiedPositions[4][4] == 1)
                turretdel[4][4] = 1;
        }

        if (mouseX >= 430 && mouseX <= 545 && mouseY >= 420 && mouseY <= 535) {
            if (occupiedPositions[5][1] == 1)
                turretdel[5][1] = 1;
            else if (occupiedPositions[5][2] == 1)
                turretdel[5][2] = 1;
            else if (occupiedPositions[5][3] == 1)
                turretdel[5][3] = 1;
            else if (occupiedPositions[5][4] == 1)
                turretdel[5][4] = 1;
        }

        if (mouseX >= 110 && mouseX <= 225 && mouseY >= 260 && mouseY <= 375) {
            if (occupiedPositions[6][1] == 1)
                turretdel[6][1] = 1;
            else if (occupiedPositions[6][2] == 1)
                turretdel[6][2] = 1;
            else if (occupiedPositions[6][3] == 1)
                turretdel[6][3] = 1;
            else if (occupiedPositions[6][4] == 1)
                turretdel[6][4] = 1;
        }

        if (mouseX >= 270 && mouseX <= 385 && mouseY >= 260 && mouseY <= 375) {
            if (occupiedPositions[7][1] == 1)
                turretdel[7][1] = 1;
            else if (occupiedPositions[7][2] == 1)
                turretdel[7][2] = 1;
            else if (occupiedPositions[7][3] == 1)
                turretdel[7][3] = 1;
            else if (occupiedPositions[7][4] == 1)
                turretdel[7][4] = 1;
        }

        if (mouseX >= 430 && mouseX <= 545 && mouseY >= 260 && mouseY <= 375) {
            if (occupiedPositions[8][1] == 1)
                turretdel[8][1] = 1;
            else if (occupiedPositions[8][2] == 1)
                turretdel[8][2] = 1;
            else if (occupiedPositions[8][3] == 1)
                turretdel[8][3] = 1;
            else if (occupiedPositions[8][4] == 1)
                turretdel[8][4] = 1;
        }

    }
}



void Lab3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{

    if (mouseX >= 110 && mouseX <= 225 && mouseY >= 580 && mouseY <= 695 && (occupiedPositions[0][1] == 0 || occupiedPositions[0][2] == 0 ||
        occupiedPositions[0][3] == 0 || occupiedPositions[0][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 160.0f;
            turret1Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[0][1] = 1;
            starturret = starturret - 1;

        }

        if (isTurret2Dragged) {
            turret2X = 160.0f;
            turret2Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[0][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 160.0f;
            turret3Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[0][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 160.0f;
            turret4Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[0][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 270 && mouseX <= 385 && mouseY >= 580 && mouseY <= 695 && (occupiedPositions[1][1] == 0 || occupiedPositions[1][2] == 0 ||
        occupiedPositions[1][3] == 0 || occupiedPositions[1][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 320.0f;
            turret1Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[1][1] = 1;
            starturret = starturret - 1;


        }

        if (isTurret2Dragged) {
            turret2X = 320.0f;
            turret2Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[1][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 320.0f;
            turret3Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[1][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 320.0f;
            turret4Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[1][4] = 1;
            starturret = starturret - 3;
        }

    }

    else if (mouseX >= 430 && mouseX <= 545 && mouseY >= 580 && mouseY <= 695 && (occupiedPositions[2][1] == 0 || occupiedPositions[2][2] == 0 ||
        occupiedPositions[2][3] == 0 || occupiedPositions[2][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 480.0f;
            turret1Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[2][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 480.0f;
            turret2Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[2][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 480.0f;
            turret3Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[2][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 480.0f;
            turret4Y = 83.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[2][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 110 && mouseX <= 225 && mouseY >= 420 && mouseY <= 535 && (occupiedPositions[3][1] == 0 || occupiedPositions[3][2] == 0 ||
        occupiedPositions[3][3] == 0 || occupiedPositions[3][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 160.0f;
            turret1Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[3][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 160.0f;
            turret2Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[3][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 160.0f;
            turret3Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[3][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 160.0f;
            turret4Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[3][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 270 && mouseX <= 385 && mouseY >= 420 && mouseY <= 535 && (occupiedPositions[4][1] == 0 || occupiedPositions[4][2] == 0 ||
        occupiedPositions[4][3] == 0 || occupiedPositions[4][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 320.0f;
            turret1Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[4][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 320.0f;
            turret2Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[4][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 320.0f;
            turret3Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[4][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 320.0f;
            turret4Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[4][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 430 && mouseX <= 545 && mouseY >= 420 && mouseY <= 535 && (occupiedPositions[5][1] == 0 || occupiedPositions[5][2] == 0 ||
        occupiedPositions[5][3] == 0 || occupiedPositions[5][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 480.0f;
            turret1Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[5][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 480.0f;
            turret2Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[5][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 480.0f;
            turret3Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[5][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 480.0f;
            turret4Y = 243.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[5][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 110 && mouseX <= 225 && mouseY >= 260 && mouseY <= 375 && (occupiedPositions[6][1] == 0 || occupiedPositions[6][2] == 0 ||
        occupiedPositions[6][3] == 0 || occupiedPositions[6][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 160.0f;
            turret1Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[6][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 160.0f;
            turret2Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[6][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 160.0f;
            turret3Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[6][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 160.0f;
            turret4Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[6][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 270 && mouseX <= 385 && mouseY >= 260 && mouseY <= 375 && (occupiedPositions[7][1] == 0 || occupiedPositions[7][2] == 0 ||
        occupiedPositions[7][3] == 0 || occupiedPositions[7][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 320.0f;
            turret1Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[7][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 320.0f;
            turret2Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[7][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 320.0f;
            turret3Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[7][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 320.0f;
            turret4Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[7][4] = 1;
            starturret = starturret - 3;
        }
    }

    else if (mouseX >= 430 && mouseX <= 545 && mouseY >= 260 && mouseY <= 375 && (occupiedPositions[8][1] == 0 || occupiedPositions[8][2] == 0 ||
        occupiedPositions[8][3] == 0 || occupiedPositions[8][4] == 0)) {

        if (isTurret1Dragged) {
            turret1X = 480.0f;
            turret1Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret1X, turret1Y, 0), 100, 50, glm::vec3(0.97255f, 0.37255f, 0.00784f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
            occupiedPositions[8][1] = 1;
            starturret = starturret - 1;
        }

        if (isTurret2Dragged) {
            turret2X = 480.0f;
            turret2Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret2X, turret2Y, 0), 100, 50, glm::vec3(0.01176F, 0.38431f, 0.98824f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
            occupiedPositions[8][2] = 1;
            starturret = starturret - 2;
        }

        if (isTurret3Dragged) {
            turret3X = 480.0f;
            turret3Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret3X, turret3Y, 0), 100, 50, glm::vec3(0.98824f, 0.83137f, 0.01176f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
            occupiedPositions[8][3] = 1;
            starturret = starturret - 2;
        }

        if (isTurret4Dragged) {
            turret4X = 480.0f;
            turret4Y = 403.0f;
            string turretName = "turrettest" + to_string(turretcount);
            Mesh* turrettest = object2D::CreateCustom(turretName, glm::vec3(turret4X, turret4Y, 0), 100, 50, glm::vec3(0.66275f, 0.01176f, 0.98431f), true);
            AddMeshToList(turrettest);
            turretcount++;
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
            occupiedPositions[8][4] = 1;
            starturret = starturret - 3;
        }
    }
    else {

        if (isTurret1Dragged) {
            turret1X = 115.0f;
            turret1Y = 640.0f;
            isTurret1Dragged = false;
        }

        if (isTurret2Dragged) {
            turret2X = 315.0f;
            turret2Y = 640.0f;
            isTurret2Dragged = false;
        }

        if (isTurret3Dragged) {
            turret3X = 515.0f;
            turret3Y = 640.0f;
            isTurret3Dragged = false;
        }

        if (isTurret4Dragged) {
            turret4X = 715.0f;
            turret4Y = 640.0f;
            isTurret4Dragged = false;
        }
    }
}

void Lab3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab3::OnWindowResize(int width, int height)
{
}

#pragma once

#include "components/simple_scene.h"
#include <map>
#include <random>

namespace m1
{
    class Lab3 : public gfxc::SimpleScene
    {
    public:
        Lab3();
        ~Lab3();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;
        int   k;
        float MOVE_RATIO = 0.25f;
        float LIMIT = 0.5f;
        float SQUARE_SIDE = 100.f;
        float SQUARES_DISTANCE = 100.f;
        float SCALE_FACTOR_X = 1.5f;
        float SCALE_FACTOR_Y = 2.f;
        int i;
        float enemySpeed = 75.0f;
        float projectile1X = 60.0f;
        float projectile2X = 260.0f;
        float projectile3X = 60.0f;
        float projectile4X = 260.0f;
        float scaleSpeed = 0.25f;
        float startvalue = 1.0f;
        bool isTurret1Dragged = false;
        bool isTurret2Dragged = false;
        bool isTurret3Dragged = false;
        bool isTurret4Dragged = false;
        float turret1X = 115.0f;
        float turret2X = 315.0f;
        float turret3X = 515.0f;
        float turret4X = 715.0f;
        float turret1Y = 640.0f;
        float turret2Y = 640.0f;
        float turret3Y = 640.0f;
        float turret4Y = 640.0f;
        int occupiedPositions[9][4] = { 0 };
        int projectpos[9][4] = { 0 };
        int turretdel[9][4] = { 0 };
        glm::vec3 corner = glm::vec3(0, 0, 0);
        int turretcount = 1;
        int j;
        float star1X = std::rand() % 1231 + 25;
        float star1Y = std::rand() % 476 + 25;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        int k4 = 0;
        float star2X = std::rand() % 1231 + 25;
        float star2Y = std::rand() % 476 + 25;
        bool isprojectile1init = false;
        float star3X = std::rand() % 1231 + 25;
        float star3Y = std::rand() % 476 + 25;
        float projectile1Y, projectile2Y, projectile3Y, projectile4Y;
        float starX[100] = { 2000.0f, 2000.0f, 2000.0f };
        float starY[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy1X[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy2X[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy3X[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy4X[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy1Y[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy2Y[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy3Y[100] = { 2000.0f, 2000.0f, 2000.0f };
        float enemy4Y[100] = { 2000.0f, 2000.0f, 2000.0f };
        float squareSide = 115;
        float rectangleX = 65;
        float rectangleY = 435;
        float starcount = 3;
        int kont = 0;
        int starturret = 5;
        float randomtime = (std::rand() % 201 + 400) / 100.0f;
        float randomenemy = std::rand() % 4 + 1;
        float randomline = std::rand() % 3 + 1;
        int enemyaddcount = 0;
        int enemycount1 = 0;
        int enemycount2 = 0;
        int enemycount3 = 0;
        int enemycount4 = 0;
        int life = 3;
        bool enemy1LifeDecreased[100];
        bool enemy2LifeDecreased[100];
        bool enemy3LifeDecreased[100];
        bool enemy4LifeDecreased[100];
        float life1X = 840.0f;
        float life2X = 960.0f;
        float life3X = 1080.0f;
        float lifeY = 610.0f;
    };
}   // namespace m1

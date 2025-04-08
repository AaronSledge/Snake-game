#pragma once

#include "raylib.h"

typedef struct Snake{
    Vector2 position;
    Vector2 size;
    int length;
    bool isAlive;

    Snake();
    void movement();
} Snake;
#pragma once

#include "raylib.h"

typedef struct Snake{
    Vector2 position;
    Vector2 size;
    bool isAlive;

    Snake();
} Snake;
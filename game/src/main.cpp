#include "raylib.h"
#include "../header/snake.h"
#include <iostream>




int main() {
    const int screenWidth = 900;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "example - basic window");

    Snake snake;


    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}
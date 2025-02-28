#include "C:\raylib\raylib\src\raylib.h"
#include <iostream>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "example - basic window");

    while(!WindowShouldClose()) {
        BeginDrawing();
            DrawText("Hello", 190, 200, 20, GRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;

}
#include "raylib.h"
#include "../header/snake.h"
#include <iostream>


void updateGame(Snake &snake, bool gameOver, bool pause, int &xpos, int &ypos) {

    if(!gameOver) {
        if(!pause) {
            if(IsKeyPressed(KEY_RIGHT)) {
                xpos = 5;
                ypos = 0;
            }

            if(IsKeyPressed(KEY_LEFT)) {
                xpos = -5;
                ypos = 0;
            }

            if(IsKeyPressed(KEY_UP)) {
                ypos = -5;
                xpos = 0;
            }

            if(IsKeyPressed(KEY_DOWN)) {
                ypos = 5;
                xpos = 0;
            }

            for(int i = 0; i < snake.length; ++i) {
                snake.position.x += xpos;
                snake.position.y += ypos;
            }
        }
    }
}

void DrawBoard(Snake &snake, bool gameOver, bool pause) {
    if(!gameOver) {
        if(!pause) {
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GREEN);
            EndDrawing();
        }
    }
}


int main() {
    const int SCREENWIDTH = 900;
    const int SCREENHEIGHT = 900;

    InitWindow(SCREENWIDTH, SCREENHEIGHT, "example - basic window");

    Snake snake;
    bool gameOver = false;
    bool pause = false;
    int xpos = 0;
    int ypos = 0;

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        updateGame(snake, gameOver, pause, xpos, ypos);
        DrawBoard(snake, gameOver, pause);
    }
    CloseWindow();
    return 0;

}
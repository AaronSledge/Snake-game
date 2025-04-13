#include "raylib.h"
#include "../header/snake.h"
#include <iostream>


void updateGame(Snake &snake, bool gameOver, bool &pause, int &xpos, int &ypos) {

    if(!gameOver) {
        int key = GetCharPressed();
        if(key == 80 || key == 112) {
            pause  = true;
        }
        else if(pause == true && key == 101) {
            pause = false;
        }
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
        BeginDrawing();
            
            if(!pause) {
                ClearBackground(RAYWHITE);
                DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GREEN);
            }
            else {
                ClearBackground(RAYWHITE);
                DrawRectangle(snake.position.x, snake.position.y, snake.size.x, snake.size.y, GREEN);
                DrawText("PAUSED: Press e to continue", 80, 250, 50, RED);
            }
            
        EndDrawing();
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
#include "../header/snake.h"

Snake::Snake() {
    position = {300, 450};
    size = {20, 20};
    length = 1;
    isAlive = true;
}

void Snake::movement() {
    while(true) {
        if(IsKeyPressed(KEY_RIGHT)) {
            position.x += 5;
        }

        if(IsKeyPressed(KEY_LEFT)) {
            position.x -= 5;
        }

        if(IsKeyPressed(KEY_UP)) {
            position.y -= 5;
        }

        if(IsKeyPressed(KEY_DOWN)) {
            position.y += 5;
        }
    }
}

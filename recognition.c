#include "learning_dir/def.h"
#include <raylib.h>


int main()
{
    InitEverything();
    InitWindow(SCREEN_W, SCREEN_L,  "AI Digit Recognition");
    SetTargetFPS(120);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}
#include "learning_dir/def.h"



void deseneaza(chenare_t chenare, butt_t butoane)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(chenare[1].x, chenare[1].y, LATIME, INALTIME, BLACK);
    DrawRectangle(chenare[2].x, chenare[2].y, LATIME, INALTIME, BLACK);
    Rectangle chenar = {chenare[1].x, chenare[1].y, LATIME, INALTIME};
    DrawRectangleLinesEx(chenar, 4.0f, BLUE);
    chenar.x = chenare[2].x; chenar.y = chenare[2].y;
    chenar.height = INALTIME; chenar.width = LATIME;
    DrawRectangleLinesEx(chenar, 4.0f, BLUE);
    for(int i = 0; i < 2; ++i) {
        DrawRectangleRec(butoane[i].rec, RED);
    }
    for(int i = 2; i < 4; ++i) {
        DrawRectangleRec(butoane[i].rec, GREEN);
    }
    DrawRectangleRec(butoane[4].rec, BLUE);
    for(int i = 0; i < 5; ++i) {
        DrawText(butoane[i].s, butoane[i].rec.x, butoane[i].rec.y, 47, WHITE);
    }
    int latime_text = MeasureText(butoane[5].s, 65);
    DrawText(butoane[5].s, (SCREEN_W - latime_text) / 2, butoane[5].rec.y, 65, WHITE);
    //desenam si sageata:
    DrawRectangle(CHENAR_X + LATIME + 20, CHENAR_Y + INALTIME / 2 - 20, 180, 40, WHITE);
    Vector2 v1 = {CHENAR_X + LATIME + 20 + 180, CHENAR_Y + INALTIME / 2 - 40};
    Vector2 v2 = {CHENAR_X + LATIME + 200, CHENAR_Y + INALTIME / 2 + 40};
    Vector2 v3 = {CHENAR_X + LATIME + 220, CHENAR_Y + INALTIME / 2};
    DrawTriangle(v1, v2, v3, WHITE);
    EndDrawing();
}

int main()
{
    chenare_t square = (chenare_t) malloc(2 * sizeof(chenare_s));
    butt_t butoane = malloc(8 * sizeof(butt_s));
    InitEverything(square, butoane);
    InitWindow(SCREEN_W, SCREEN_L,  "AI Digit Recognition");
    SetTargetFPS(120);
    while(!WindowShouldClose()) {
        deseneaza(square, butoane);
        
    }
    CloseWindow();
    return 0;
}
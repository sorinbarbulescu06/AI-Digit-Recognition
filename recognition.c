#include "learning_dir/def.h"



void deseneaza(chenare_t chenare, butt_t butoane, Rectangle zona_desen, RenderTexture2D panza, int inteligent, int output, int gasit)
{
    
    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse, zona_desen) && inteligent == 1) {
        Vector2 poz_pensula = { mouse.x - zona_desen.x, mouse.y - zona_desen.y };

        BeginTextureMode(panza);
        DrawCircleV(poz_pensula, 12.0f, WHITE);
        EndTextureMode();
    }
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangle(chenare[1].x - 4, chenare[1].y - 4, LATIME + 8, INALTIME +8, BLUE);
    DrawRectangle(chenare[2].x - 4, chenare[2].y - 4, LATIME + 8, INALTIME +8, BLUE);
    DrawRectangle(chenare[1].x, chenare[1].y, LATIME, INALTIME, BLACK);
    DrawRectangle(chenare[2].x, chenare[2].y, LATIME, INALTIME, BLACK);
    Rectangle chenar = {chenare[1].x, chenare[1].y, LATIME, INALTIME};
    chenar.x = chenare[2].x; chenar.y = chenare[2].y;
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
    latime_text = MeasureText(butoane[6].s, 30);
    DrawText(butoane[6].s, (SCREEN_W - latime_text) / 2, butoane[6].rec.y, 30, WHITE);
    latime_text = MeasureText(butoane[7].s, 30);
    DrawText(butoane[7].s, (SCREEN_W - latime_text) / 2, butoane[7].rec.y, 30, WHITE);
    //desenam si sageata:
    DrawRectangle(CHENAR_X + LATIME + 20, CHENAR_Y + INALTIME / 2 - 20, 180, 40, WHITE);
    Vector2 v1 = {CHENAR_X + LATIME + 20 + 180, CHENAR_Y + INALTIME / 2 - 40};
    Vector2 v2 = {CHENAR_X + LATIME + 200, CHENAR_Y + INALTIME / 2 + 40};
    Vector2 v3 = {CHENAR_X + LATIME + 220, CHENAR_Y + INALTIME / 2};
    DrawTriangle(v1, v2, v3, WHITE);
    if(inteligent == 1) {
     Rectangle sursa = { 0, 0, (float)panza.texture.width, -(float)panza.texture.height };
        Vector2 poz_pe_ecran = { zona_desen.x, zona_desen.y };
        
        DrawTextureRec(panza.texture, sursa, poz_pe_ecran, WHITE);
    }
    if(gasit == 1) {
        char buff[30];
        sprintf(buff, "%d", output);
        DrawText(buff, SCREEN_W - 280, CHENAR_Y + 50, 200, WHITE);
    }
    EndDrawing();
}

int CheckAndDo(chenare_t square, butt_t butoane)
{
    Vector2 pozitie = GetMousePosition();
    bool over0 = CheckCollisionPointRec(pozitie, butoane[0].rec);
    bool over1 = CheckCollisionPointRec(pozitie, butoane[1].rec);
    bool over2 = CheckCollisionPointRec(pozitie, butoane[2].rec);
    bool over3 = CheckCollisionPointRec(pozitie, butoane[3].rec);
    bool over4 = CheckCollisionPointRec(pozitie, butoane[4].rec);
    if (over0 == true || over1 == true || over2 == true || over3 == true || over4 == true) {
        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        if (over0 == true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            butoane[5].val += -1000;
            if (butoane[5].val < 0) {
                butoane[5].val = 0;
            }
            char buff[30];
            sprintf(buff, "%d", butoane[5].val);
            strcpy(butoane[5].s, buff);
            return 0;
        } else if (over1 == true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            butoane[5].val += -500;
            if (butoane[5].val < 0) {
                butoane[5].val = 0;
            }
            char buff[30];
            sprintf(buff, "%d", butoane[5].val);
            strcpy(butoane[5].s, buff);
            return 0;
        } else if (over2 == true&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            butoane[5].val += 500;
            if (butoane[5].val > 60000) {
                butoane[5].val = 60000;
            }
            char buff[30];
            sprintf(buff, "%d", butoane[5].val);
            strcpy(butoane[5].s, buff);
            return 0;
        } else if (over3 == true && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            butoane[5].val += 1000;
            if (butoane[5].val > 60000) {
                butoane[5].val = 60000;
            }
            char buff[30];
            sprintf(buff, "%d", butoane[5].val);
            strcpy(butoane[5].s, buff);
            return 0;
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { //over4 == true
            return 1;
        }
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
    return 0;
}

void pictam(chenare_t square)
{
    Vector2 pozitie = GetMousePosition();
    Rectangle chenar = {square->x, square->y, 280, 280};
    //if(CheckCollisionPointRec(pozitie, chenar) && IsKeyPressed)

}  

int main()
{
    chenare_t square = (chenare_t) malloc(2 * sizeof(chenare_s));
    butt_t butoane = malloc(10 * sizeof(butt_s));
    InitEverything(square, butoane);
    InitWindow(SCREEN_W, SCREEN_L,  "AI Digit Recognition");
    SetTargetFPS(120);
    int inteligent = 0;
    RenderTexture2D panza = LoadRenderTexture(280, 280);
    BeginTextureMode(panza);
    ClearBackground(BLACK);
    EndTextureMode();
    Rectangle zona_desen = {100, 100, 280, 280};
    float ***p;
    int output = 0;
    int gasit = 0;
    while(!WindowShouldClose()) {
        deseneaza(square, butoane, zona_desen, panza, inteligent, output, gasit);
        if(CheckAndDo(square, butoane) == 1) {
            int limita_text = MeasureText("Learning...", 30);
            BeginDrawing();
            DrawText("Learning...", (SCREEN_W - limita_text) / 2, 100, 30, WHITE);
            EndDrawing();
            p = invatare(butoane[5].val);//p[0] = ponderi1[64][784], p[1] = ponderi2[32][64], p[2] = ponderi3[10][32]
            butoane[6].val = butoane[5].val;
            char buff[30];
            sprintf(buff, "%d", butoane[6].val);
            strcpy(butoane[6].s + 5, buff);
            butoane[7].percentage = try(p);
            char bufff[30];
            sprintf(bufff, "%.4f", butoane[7].percentage);
            strcpy(butoane[7].s + 6, bufff);
            inteligent = 1;
        }
        //trimitem solutia la rezolvare
        if(inteligent == 1 && IsKeyPressed(KEY_ENTER)) {
            Image poza_bruta = LoadImageFromTexture(panza.texture);
            ImageFlipVertical(&poza_bruta);
            ImageResize(&poza_bruta, 28, 28);
            Color *pixeli = LoadImageColors(poza_bruta);
            float input[784];
            for (int i = 0; i < 784; i++) {
                input[i] = (float)pixeli[i].r / 255.0f;
            }
            UnloadImageColors(pixeli);
            UnloadImage(poza_bruta);
            output = guess(input, p);
            gasit = 1;
            
        }
        if(IsKeyPressed(KEY_BACKSPACE)) {
            BeginTextureMode(panza);
            ClearBackground(BLACK);
            EndTextureMode();
            gasit = 0;
        }
    }
    CloseWindow();
    return 0;
}
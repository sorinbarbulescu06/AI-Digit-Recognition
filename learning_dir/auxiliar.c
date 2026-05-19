#include "def.h"

void initializeaza_ponderi(float *matrice, int intrari, int iesiri)
{
    float limita = sqrtf(6.0f / (float)intrari);
    for (int i = 0; i < intrari * iesiri; i++) {
        float rand_0_1 = (float)rand() / (float)RAND_MAX;
        float rand_prostit = rand_0_1 * 2.0f - 1.0f;
        matrice[i] = rand_prostit * limita;
    }
}

void InitEverything(chenare_t chenare, butt_t butoane)
{
    chenare[1].x = CHENAR_X;
    chenare[1].y = CHENAR_Y;
    chenare[2].x = SCREEN_W - CHENAR_X - LATIME;
    chenare[2].y = CHENAR_Y;
    butoane[0].rec.x = BUTT_OFFSET_X;
    butoane[1].rec.x  = butoane[0].rec.x  + BUTT_SPACING + BUTT_L;
    butoane[2].rec.x  = butoane[1].rec.x  + 2 * BUTT_SPACING + 2 * BUTT_L;
    butoane[3].rec.x  = butoane[2].rec.x  + BUTT_SPACING + BUTT_L;
    butoane[4].rec.x  = (SCREEN_W - BUTT_L ) / 2;
    butoane[0].rec.y = CHENAR_Y + INALTIME + BUTT_OFFSET_Y;
    butoane[1].rec.y = butoane[0].rec.y;
    butoane[2].rec.y = butoane[0].rec.y;
    butoane[3].rec.y = butoane[0].rec.y;
    butoane[4].rec.y = butoane[0].rec.y + SPACE + BUTT_W;
    butoane[0].rec.height = BUTT_W;
    butoane[1].rec.height = BUTT_W;
    butoane[2].rec.height = BUTT_W;
    butoane[3].rec.height = BUTT_W;
    butoane[4].rec.height = BUTT_W;
    butoane[0].rec.width = BUTT_L;
    butoane[1].rec.width = BUTT_L;
    butoane[2].rec.width = BUTT_L;
    butoane[3].rec.width = BUTT_L;
    butoane[4].rec.width = BUTT_L;
    butoane[5].rec.x = butoane[1].rec.x  + BUTT_SPACING + BUTT_L;
    butoane[5].rec.y = butoane[0].rec.y;
    strcpy(butoane[0].s, "-1000");
    strcpy(butoane[1].s, "-500");
    strcpy(butoane[2].s, "+500");
    strcpy(butoane[3].s, "+1000");
    strcpy(butoane[4].s, "Learn!");
    butoane[5].val = 10000;
    char buff[30];
    sprintf(buff, "%d", butoane[5].val);
    strcpy(butoane[5].s, buff);
}
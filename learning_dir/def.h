#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <raylib.h>
#include <string.h>

#define LATIME 280
#define INALTIME 280
#define SCREEN_L 750
#define SCREEN_W 1000
#define CHENAR_X 100
#define CHENAR_Y 100
#define BUTT_SPACING 50
#define BUTT_OFFSET_X 30
#define BUTT_OFFSET_Y 100
#define BUTT_L 148
#define BUTT_W 100
#define SPACE 20




typedef struct chenare{
    int x;
    int y;
}chenare_s,*chenare_t;

typedef struct butoane{
    Rectangle rec;
    char s[25];
    int val;
    float percentage;
} butt_s, *butt_t;

//aux.c
void initializeaza_ponderi(float **matrice, int intrari, int iesiri);
void InitEverything(chenare_t chenare, butt_t butoane);
void deseneaza(chenare_t chenare, butt_t butoane, Rectangle zona_desen, RenderTexture2D panza, int inteligent, int output, int gasit);

//invatare.c
float*** invatare(int itcount);

//try.c
float try(float ***p);

int guess(float input[], float ***p);
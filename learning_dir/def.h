#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define LATIME 128
#define INALTIME 128
#define ITCOUNT 3000
#define SCREEN_L 500
#define SCREEN_W 1000

typedef struct chenare{
    int x;
    int y;
}*chenare;

//aux.c
void initializeaza_ponderi(float *matrice, int intrari, int iesiri);

//recognition.c
void InitEverything();
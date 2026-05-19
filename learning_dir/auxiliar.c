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
#include "def.h"

int guess(float input[], float ***p)
{
    float val1[64] = {0};
    float val2[32] = {0};
    float output[10];
    for (int c = 0; c < 10; ++c) {
        output[c] = 0.0f;
    }
        //calculam mediile ponderate frumos
    for (int i = 0; i < 64; ++i) {
        float s = 0;
        for(int j = 0; j < 784; ++j) {
            s += p[0][i][j] * input[j];
        }
        val1[i] = s;
        if (s < 0) {
            val1[i] = 0;
        }
    }
    //am calculat semnalele transmise in cei 64 de neuroni
    for (int i = 0; i < 32; ++i) {
        float s = 0;
        for(int j = 0; j < 64; ++j) {    
            s += p[1][i][j] * val1[j];
        }
        val2[i] = s;
        if (s < 0) {
            val2[i] = 0;
        }
    }
    //am calculat semnalele transmise in cei 32 de neuroni
    for (int i = 0; i < 10; ++i) {
        float s = 0;
        for (int j = 0; j < 32; ++j) {
            s += p[2][i][j] * val2[j];
        }
        output[i] = s;
    }
    float max_output = output[0];
    float max_ind = 0;
    for (int i = 1; i < 10; ++i) {
        if (max_output < output[i]) {
            max_output = output[i];
            max_ind = i;
        }
    }
    return max_ind;
}
#include "def.h"

float try(float ***p)
{
    FILE *datasheet = fopen("learning_dir/train-images-idx3-ubyte", "rb");
    if (datasheet == NULL) {
        return 1;
    }
    FILE *response = fopen("learning_dir/train-labels-idx1-ubyte", "rb");
    if (response == NULL) {
        return 1;
    }
    fseek(response, 8, SEEK_SET); //response am indici
    fseek(datasheet, 16, SEEK_SET); //datasheet am pozele
    float val1[64] = {0};
    float val2[32] = {0};
    float input[784];
    float output[10];
    int gasit = 0;
    for(int it = 0; it < 20000; ++it) {
        //citim din datasheet poza cu numarul it
        unsigned char *poza = (unsigned char*) malloc(784 * sizeof(unsigned char));
        fread(poza, sizeof(unsigned char), 784, datasheet);
        unsigned char ans_char;
        fread(&ans_char, sizeof(unsigned char), 1, response);
        float ans = (float) ans_char;
        for (int p = 0; p < 784; ++p) {
            input[p] = (float)poza[p] / 255.0f;
        }
        for (int c = 0; c < 10; ++c) {
            output[c] = 0.0f;
        }
        free(poza);
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
        if (ans == max_ind) {
            gasit++;
        }
    }
    float results = (float)gasit / 20000;
    results *= 100;
    fclose(datasheet);
    fclose(response);
    return results;
}
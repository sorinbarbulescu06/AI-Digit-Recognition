#include "def.h"

float*** invatare(int itcount)
{
    float learning_constant = 0.01;
    float ***ponderi = (float ***) malloc(3 * sizeof(float **));
    ponderi[0] = (float **) malloc(64 * sizeof(float *));
    for(int i = 0; i < 64; ++i) {
        ponderi[0][i] = malloc(784 * sizeof(float));
    }
    ponderi[1] = (float **) malloc(32 * sizeof(float *));
    for(int i = 0; i < 32; ++i) {
        ponderi[1][i] = malloc(64 * sizeof(float));
    }
    ponderi[2] = (float **) malloc(10 * sizeof(float *));
    for(int i = 0; i < 10; ++i) {
        ponderi[2][i] = malloc(32 * sizeof(float));
    }
    float val1[64] = {0};
    float val2[32] = {0};

    float input[784];
    float output[10];
    srand(time(NULL));

    initializeaza_ponderi(ponderi[0], 784, 64);
    initializeaza_ponderi(ponderi[1], 64, 32);
    initializeaza_ponderi(ponderi[2], 32, 10);

    
    FILE *datasheet = fopen("learning_dir/train-images-idx3-ubyte", "rb");
    if (datasheet == NULL) {
        return NULL;
    }
    FILE *response = fopen("learning_dir/train-labels-idx1-ubyte", "rb");
    if (response == NULL) {
        return NULL;
    }
    fseek(response, 8, SEEK_SET); //response am indici
    fseek(datasheet, 16, SEEK_SET); //datasheet am pozele

    for (int it = 0; it < itcount; ++it) {
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
        //*input = poza
        //*output = 0 peste tot
        //ans = numarul din poza    
        //calculam mediile ponderate frumos
        for (int i = 0; i < 64; ++i) {
            float s = 0;
            for(int j = 0; j < 784; ++j) {
                s += ponderi[0][i][j] * input[j];
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
                s += ponderi[1][i][j] * val1[j];
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
                s += ponderi[2][i][j] * val2[j];
            }
            output[i] = s;
        }
        float probabilitati[10];
        float suma_prob = 0;
        float max_prob = output[0];
        for (int i = 1; i < 10; ++i) {
            if(max_prob < output[i]) {
                max_prob = output[i];
            }
        }
        for (int i = 0; i < 10; ++i) {
            probabilitati[i] = expf(output[i] - max_prob);
            suma_prob += probabilitati[i];
        }
        for (int i = 0; i < 10; ++i) {
            output[i] = probabilitati[i] / suma_prob;
        }
        float err[10];
        for (int i = 0; i < 10; ++i) {
            if (i != ans) {
                err[i] = output[i] - 0;
            } else {
                err[i] = output[i] - 1;
            }
        }
        float err_val2[32];
        for(int i = 0; i < 32; ++i) {
            float s = 0;
            for (int j = 0; j < 10; ++j) {
                s += err[j] * ponderi[2][j][i];
            }
            if (val2[i] > 0) {
                err_val2[i] = s;
            } else {
                err_val2[i] = 0;
            }
        }
        float err_val3[64];
        for(int i = 0; i < 64; ++i) {
            float s = 0;
            for (int j = 0; j < 32; ++j) {
                s += err_val2[j] * ponderi[1][j][i];
            }
            if (val1[i] > 0) {
                err_val3[i] = s;
            } else {
                err_val3[i] = 0;
            }
        }

        for (int i = 0; i < 10; ++i) {
            //care eroare este verificata
            for (int j = 0; j < 32; ++j) {
                ponderi[2][i][j] = ponderi[2][i][j] - (learning_constant * err[i] * val2[j]);
            }
        }

        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < 64; ++j) {
                ponderi[1][i][j] = ponderi[1][i][j] - (learning_constant * err_val2[i] * val1[j]);
            }
        }
        
        for (int i = 0; i < 64; ++i) {
            for (int j = 0; j < 784; ++j) {
                ponderi[0][i][j] = ponderi[0][i][j] - (learning_constant * err_val3[i] * input[j]);
            }
        }
    }

    fclose(response);
    fclose(datasheet);
    return ponderi;
}
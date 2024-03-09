#include "./utils.h"
#define cinci 5

void SolveTask1(void *info, int nr_avioane) {
    int i = 0;
    unsigned char *aux = (unsigned char*)info;  // auxiliar pt info tip char
    int j = 1;
    for (i = 0; i < nr_avioane; i++) {
        printf("(%hu, %hu)\n", *(aux + (j-1)), *(aux + (j + 1)));
        j = j + 3;
        printf("%c\n", *(aux + j));
        j++;
        for (int k = 0; k < 4; k++) {
            printf("%c", *(aux + j + k));
        }
        printf("\n");
        j = j + 4;
        printf("%u\n", *(aux + j));
        j = j + cinci;
        printf("\n");
    }
}

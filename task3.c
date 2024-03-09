#include "./utils.h"
#define MAX 1000
#define cinci 5
#define l_avion 13  //  numarul de biti pt informatiile unui avion

int swap(const void *a, const void *b) {
    a = a + 2*sizeof(short int) + sizeof(char);  // a la pozitia pt tip
    b = b + 2*sizeof(short int) + sizeof(char);  // b la pozitia pt tip
    unsigned char tip1 = *(unsigned char*)a;
    unsigned char tip2 = *(unsigned char*)b;
    if (tip1 < tip2) {
        return -1;
    }
    if (tip1 > tip2) {
        return 1;
    // ordoneaza crescator avioanele dupa tip
    }
        // daca avioanele sunt de acelasi tip
        a = a + sizeof(char);  // a la pozitia pt aeroport
        b = b + sizeof(char);  // b la pozitia pt aeroport
        char aeroport1[MAX], aeroport2[MAX];
        strncpy(aeroport1, a, 3*sizeof(char));  // se copiaza in aeroport1 numele aeroportului
        strncpy(aeroport2, b, 3*sizeof(char));  // se copiaza in aeroport2 numele aeroportului
        aeroport1[3] = '\0';
        aeroport2[3] = '\0';
        int x = strcmp(aeroport1, aeroport2);
        if (x > 0) {
            return -1;
        }
        if (x < 0) {
            return 1;
        }
        // ordoneaza avioanele descrescator lexicografic
    // daca avioanele pleaca din acelasi aeroport
    a = a + 3*sizeof(char);  // a la pozitia pt viteza
    b = b + 3*sizeof(char);  // b la pozitia pt viteza
    unsigned int viteza1 = *(unsigned int*)a;
    unsigned int viteza2 = *(unsigned int*)b;
    if (viteza1 < viteza2) {
        return -1;
    }
    if (viteza1 > viteza2) {
        return 1;
    }
    return 0;
    // se ordoneaza crescator avioanele dupa viteza
}

void SolveTask3(void *info, int nr_avioane) {
    qsort(info, nr_avioane, l_avion, swap);
    unsigned char *aux = (unsigned char*)info;
    int j = 1;
    for (int i = 0; i < nr_avioane; i++) {
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

#include "./utils.h"
#define l_avion 13  //  numarul de biti pt informatiile unui avion
#define cinci 5

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    unsigned char *aux = (unsigned char*)info;

    for ( int a = 0; a < nr_avioane; a++ ) {
        int indice_info = a * l_avion;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((i == *(aux + indice_info)) && (j == *(aux + indice_info + 2))) {
                    if (*(aux + indice_info + cinci) == '1') {
                        if (*(aux + indice_info + 4) == 'N') {
                            mat[i][j] = '*';
                            mat[i+2][j] = '*';
                            for (int n = -2; n <= 2; n++) {  // pentru aripi
                                mat[i+1][j+n] = '*';
                            }
                            for (int n = -1; n <= 1; n++) {  // pentru coada
                                mat[i+3][j+n] = '*';
                            }
                        }
                        if (*(aux + indice_info + 4) == 'S') {
                            mat[i][j] = '*';
                            mat[i-2][j] = '*';
                            for (int n = -1; n <= 1; n++) {  // pentru aripi
                                mat[i-3][j+n] = '*';
                            }
                            for (int n = -2; n <= 2; n++) {  // pentru coada
                                mat[i-1][j+n] = '*';
                            }
                        }
                        if (*(aux + indice_info + 4) == 'E') {
                            mat[i][j] = '*';
                            mat[i][j-2] = '*';
                            for (int n = -2; n <= 2; n++) {  // pentru aripi
                                mat[i+n][j-1] = '*';
                            }
                            for (int n = -1; n <= 1; n++) {  // pentru coada
                                mat[i+n][j-3] = '*';
                            }
                        }
                        if (*(aux + indice_info + 4) == 'W') {
                            mat[i][j] = '*';
                            mat[i][j+2] = '*';
                            for (int n = -2; n <= 2; n++) {  // pentru aripi
                                mat[i+n][j+1] = '*';
                            }
                            for (int n = -1; n <= 1; n++) {  // pentru coada
                                mat[i+n][j+3] = '*';
                            }
                        }
                    }
                    if (*(aux + indice_info + cinci) == '2') {
                        if (*(aux + indice_info + 4) == 'N') {
                            mat[i][j] = '*';
                            mat[i+3][j] = '*';
                            for (int n = -1; n <= 1; n++) {  // pentru poertiunea cea mica de dupa varf
                                mat[i+1][j+n] = '*';
                            }
                            for (int n = -3; n <= 3; n++) {  // pentru aripi
                                mat[i+2][j+n] = '*';
                            }
                            for (int n = -2; n <= 2; n++) {  // pentru coada
                                mat[i+4][j+n] = '*';
                            }
                        }
                        if (*(aux + indice_info + 4) == 'S') {
                            mat[i][j] = '*';
                            mat[i-3][j] = '*';
                            for (int n = -1; n <= 1; n++) {  // pentru poertiunea cea mica de dupa varf
                                mat[i-1][j+n] = '*';
                            }
                            for (int n = -3; n <= 3; n++) {  // pentru aripi
                                mat[i-2][j+n] = '*';
                            }
                            for (int n = -2; n <= 2; n++) {  // pentru coada
                                mat[i-4][j+n] = '*';
                            }
                        }
                        if (*(aux + indice_info + 4) == 'E') {
                            mat[i][j] = '*';
                            mat[i][j-3] = '*';
                            for (int n = -1; n <= 1; n++) {  // pentru poertiunea cea mica de dupa varf
                                mat[i+n][j-1] = '*';
                            }
                            for (int n = -3; n <= 3; n++) {  // pentru aripi
                                mat[i+n][j-2] = '*';
                            }
                            for (int n = -2; n <= 2; n++) {  // pentru coada
                                mat[i+n][j-4] = '*';
                            }
                        }
                        if (*(aux + indice_info + 4) == 'W') {
                            mat[i][j] = '*';
                            mat[i][j+3] = '*';
                            for (int n = -1; n <= 1; n++) {  // pentru poertiunea cea mica de dupa varf
                                mat[i+n][j+1] = '*';
                            }
                            for (int n = -3; n <= 3; n++) {  // pentru aripi
                                mat[i+n][j+2] = '*';
                            }
                            for (int n = -2; n <= 2; n++) {  // pentru coada
                                mat[i+n][j+4] = '*';
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

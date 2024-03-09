#include "./utils.h"
#define l_avion 13  //  numarul de biti pt informatiile unui avion
#define cinci 5

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    unsigned char *aux = (unsigned char*)info;
    int cont = 0;
    for (int a = 0; a < nr_avioane; a++) {
        int indice_info = a * l_avion;  // ne ajuta sa trecem la coordonate din 13 in 13.
        int ok = 1;  // avion nelovit
        if (*(aux + indice_info + cinci) == '1') {
            if (*(aux + indice_info + 4) == 'N') {
                for (int i = 0; i < nr_obstacole; i++) {
                    if (*(aux + indice_info) + 2 == x[i] &&
                        (*(aux + indice_info +2) - 1 == y[i] || *(aux + indice_info + 2) + 1 == y[i])) {
                            // verifica daca intre aripi e un obstacol
                        ok = 0;
                    }
                    if (x[i] == 0 && y[i] == *(aux + indice_info + 2)) {
                        // verifica daca la granita hartii se afla un obtacol pt vf avionului
                        ok = 0;
                    }
                    for (int i1 = 1; i1 <= *(aux + indice_info); i1++) {
                        for (int j1 = (*(aux + indice_info + 2) - 2); j1 <= (*(aux + indice_info + 2) + 2); j1++) {
                            if (i1 == x[i] && j1 == y[i]) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                    }
                }
            }
            if (*(aux + indice_info + 4) == 'S') {
                for (int i = 0; i < nr_obstacole; i++) {
                    if (*(aux + indice_info) - 2 == x[i] &&
                        (*(aux + indice_info + 2) - 1 == y[i] || *(aux + indice_info + 2) + 1 == y[i])) {
                            // verifica daca intre aripi e un obstacol
                        ok = 0;
                    }
                    if (x[i] == N-1 && y[i] == *(aux + indice_info + 2)) {
                        // verifica daca la granita hartii se afla un obtacol pt vf avionului
                                ok = 0;
                    }
                    for (int i1 = N-2; i1 >= *(aux + indice_info); i1--) {
                        for (int j1 = (*(aux + indice_info + 2) - 2); j1 <= (*(aux + indice_info + 2) + 2); j1++) {
                            if (i1 == x[i] && j1 == y[i]) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                    }
                }
            }
            if (*(aux + indice_info + 4) == 'E') {
                for (int i = 0; i < nr_obstacole; i++) {
                    if (((*(aux + indice_info) - 1 == x[i]) || (*(aux + indice_info) + 1 == x[i])) &&
                        (*(aux + indice_info + 2) - 2 == y[i])) {
                            // verifica daca intre aripi e un obstacol
                        ok = 0;
                    }
                    if (y[i] == N-1 && x[i] == *(aux + indice_info)) {
                        // verifica daca la granita hartii se afla un obtacol pt vf avionului
                        ok = 0;
                    }
                    for (int j1 = N - 2; j1 >= *(aux + indice_info + 2); j1--) {
                        for (int i1 = (*(aux + indice_info) - 2); i1 <= (*(aux + indice_info) + 2); i1++) {
                            if (y[i] == j1 && x[i] == i1) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                    }
                }
            }
            if (*(aux + indice_info + 4) == 'W') {
                for (int i = 0; i < nr_obstacole; i++) {
                    if (((*(aux + indice_info) - 1) == x[i] || (*(aux + indice_info) + 1) == x[i]) &&
                        ((*(aux + indice_info + 2) + 2) == y[i])) {
                            // verifica daca intre aripi e un obstacol
                        ok = 0;
                    }
                    if (y[i] == 0 && x[i] == *(aux + indice_info)) {
                        // verifica daca la granita hartii se afla un obtacol pt vf avionului
                        ok = 0;
                    }
                    for (int j1 = 1; j1 <= *(aux + indice_info + 2); j1++) {
                        for (int i1 = *(aux + indice_info) - 2; i1 <= *(aux + indice_info) + 2; i1++) {
                            if (y[i] == j1 && x[i] == i1) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                    }
                }
            }
        }
        if (*(aux + indice_info + cinci) == '2') {
            if (*(aux + indice_info + 4) == 'N') {
                for (int i = 0; i < nr_obstacole; i++) {
                    if (*(aux + indice_info) + 3 == x[i] &&
                        (*(aux + indice_info +2) - 1 == y[i] || *(aux + indice_info + 2) + 1 == y[i] ||
                         *(aux + indice_info + 2) - 2 == y[i] || *(aux + indice_info + 2) + 2 == y[i])) {
                            // verifica daca intre aripi e un obstacol
                                ok = 0;
                    }
                    if (x[i] == 0 && y[i] == *(aux + indice_info + 2)) {
                        // verifica daca la granita hartii se afla un obtacol pt vf avionului
                        ok = 0;
                    }
                    if (x[i] == 1 && (y[i] == *(aux + indice_info + 2) + 1 || y[i] == *(aux + indice_info + 2) - 1)
                        || y[i] == *(aux + indice_info + 2)) {
                            // verifica daca la granita se afla un obstacol pt portiunea mica de dupa vf avionului
                        ok = 0;
                            }
                    for (int i1 = 2; i1 <= *(aux + indice_info) + 1; i1++) {
                        for (int j1 = (*(aux + indice_info + 2) - 3); j1 <= (*(aux + indice_info + 2) + 3); j1++) {
                            if (i1 == x[i] && j1 == y[i]) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                    }
                }
        }
        if (*(aux + indice_info + 4) == 'S') {
            for (int i = 0; i < nr_obstacole; i++) {
                if (*(aux + indice_info) + 3 == x[i] &&
                (*(aux + indice_info +2) - 1 == y[i] || *(aux + indice_info + 2) + 1 == y[i] ||
                 *(aux + indice_info + 2) - 2 == y[i] || *(aux + indice_info + 2) + 2 == y[i])) {
                    // verifica daca intre aripi e un obstacol
                            ok = 0;
                }
                if (x[i] == N-1 && y[i] == *(aux + indice_info + 2)) {
                    // verifica daca la granita hartii se afla un obtacol pt vf avionului
                    ok = 0;
                }
                if (x[i] == N-2 &&
                    (y[i] == *(aux + indice_info + 2) + 1 || y[i] == *(aux + indice_info + 2) - 1)
                    || y[i] == *(aux + indice_info + 2)) {
                        // verifica daca la granita se afla un obstacol pt portiunea mica de dupa vf avionului
                    ok = 0;
                        }
                for (int i1 = N-3; i1 >= *(aux + indice_info) + 1; i1--) {
                    for (int j1 = *(aux + indice_info + 2) - 3; j1 <= *(aux + indice_info + 2) + 3; j1++) {
                        if (i1 == x[i] && j1 == y[i]) {
                            // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                            ok = 0;
                        }
                    }
                }
            }
        }
        if (*(aux + indice_info + 4) == 'E') {
            for (int i = 0; i < nr_obstacole; i++) {
               if (y[i] == *(aux + indice_info + 2) - 3 &&
                    (x[i] == *(aux + indice_info) + 1 || x[i] == *(aux + indice_info) - 1 ||
                    x[i] == *(aux + indice_info) - 2 || x[i] == *(aux + indice_info) + 2)) {
                        // verifica daca intre aripi e un obstacol
                            ok = 0;
                }
                if (y[i] == N-1 && x[i] == *(aux + indice_info)) {
                    // verifica daca la granita hartii se afla un obtacol pt vf avionului
                    ok = 0;
                }
                if (y[i] == N-2 && (x[i] == *(aux + indice_info) + 1 || x[i] == *(aux + indice_info) - 1 ||
                 x[i] == *(aux + indice_info))) {
                    // verifica daca la granita se afla un obstacol pt portiunea mica de dupa vf avionului
                    ok = 0;
                        }
                for (int i1 = N - 3; i1 >= *(aux + indice_info) - 1; i1--) {
                        for (int j1 = *(aux + indice_info) - 3; j1 <= *(aux + indice_info) + 3; j1++) {
                            if (y[i] == i1 && x[i] == j1) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                }
            }
        }
        if (*(aux + indice_info + 4) == 'W') {
            for (int i = 0; i < nr_obstacole; i++) {
                if (y[i] == *(aux + indice_info + 2) + 3 &&
                    (x[i] == *(aux + indice_info) + 1 || x[i] == *(aux + indice_info) - 1 ||
                      x[i] == *(aux + indice_info) - 2 || x[i] == *(aux + indice_info) + 2)) {
                        // verifica daca intre aripi e un obstacol
                            ok = 0;
                }
                if (y[i] == 0 && x[i] == *(aux + indice_info)) {
                    // verifica daca la granita hartii se afla un obtacol pt vf avionului
                    ok = 0;
                }
                if (y[i] == 1 && (x[i] == *(aux + indice_info) + 1 || x[i] == *(aux + indice_info) - 1 ||
                    x[i] == *(aux + indice_info))) {
                        // verifica daca la granita se afla un obstacol pt portiunea mica de dupa vf avionului
                    ok = 0;
                }
                for (int i1 = 2; i1 <= *(aux + indice_info) + 1; i1++) {
                        for (int j1 = *(aux + indice_info) - 3; j1 <= *(aux + indice_info) + 3; j1++) {
                            if (y[i] == i1 && x[i] == j1) {
                                // verifica daca de la aripi pana la iesirea de pe harta se afla un obstacol.
                                ok = 0;
                            }
                        }
                }
            }
        }
    }
    if (ok == 1) {
        cont++;
    }
    }
    printf("%d", cont);
}

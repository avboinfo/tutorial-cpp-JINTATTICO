#include <iostream>
#include <vector>
#include <algorithm>

int presta(int N, int C, vector<int> P) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (P[j] < P[j + 1]) {
                int temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    int somma = 0;
    int numeroAmici = 0;

    // Sommare finché la somma non è almeno C
    for (int i = 0; i < N; i++) {
        somma += P[i];
        numeroAmici++;
        if (somma >= C) {
            return numeroAmici;
        }
    }

    return numeroAmici; // Questo punto non dovrebbe mai essere raggiunto dato C ≤ somma di tutti gli importi
}
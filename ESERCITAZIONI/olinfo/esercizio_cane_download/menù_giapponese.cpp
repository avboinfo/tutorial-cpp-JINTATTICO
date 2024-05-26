#include <iostream>
#include <algorithm> // Per la funzione sort
#include <fstream>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N, budget;
    cin >> N >> budget;
    int v[N];
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (v[i] < v[i + 1]) { 
            int k = v[i + 1];
            v[i + 1] = v[i];
            v[i] = k;
        }
    }

    int selezionati[100]; // Array per memorizzare i piatti selezionati
    int cont = 0;
    int somma = 0;

    // Sommare i costi finché non si supera il budget
    for (int i = 0; i < N; i++) {
        if (somma + v[i] <= budget) {
            somma += v[i];
            selezionati[cont] = v[i];
            cont++;
        } else {
            break;
        }
    }

    // Stampare i piatti selezionati
    for (int i = 0; i < cont; i++) {
        cout << selezionati[i] << " " << endl;
    }

}

#include <iostream>

using namespace std;

int sommaNumeri(int n1, int n2) {
    if (n1 > n2) {
        return 0;
    }
    return n1 + sommaNumeri(n1 + 1, n2);
}

int main() {
    int n, m;
    cout << "Inserire il primo numero: ";
    cin >> n;
    cout << "Inserire il secondo numero: ";
    cin >> m;
    if (n <= m) {
        int risultato = sommaNumeri(n, m);
        cout << "La somma di tutti gli interi tra " << n << " e " << m << " è: " << risultato << endl;
    } else {
        cout << "ERRORE!!!!!!!" << endl;
        cout << "Il primo numero deve essere minore o uguale al secondo numero" << endl;
    }
    
    return 0;
}

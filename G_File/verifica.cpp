
/*BUTT ABDUL MOHID  3 CIN  VERIFICA QUESITO 1   16/03/2024*/


#include <iostream>

using namespace std;
const int DIM = 10;

void riempiMatrice(int matrice[DIM][DIM]){
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            matrice[i][j]=rand()%100;
        }
        cout << endl;
    }
}
void stampaMatrice(int matrice[DIM][DIM]){
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            cout << matrice[i][j] << "   "; 
        }
        cout << endl;
    }
}
int cercaNumero(int matrice[DIM][DIM], int numero){
    int cont = 0;
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            if(matrice[i][j] == numero){
                cont++;
            }
        }
    }
    return cont;
}
int contaPrincipale(int matrice[DIM][DIM], int numero) {
    int cont2 = 0;
    for (int i = 0; i < DIM; i++) {
        if (matrice[i][i] == numero) {
            cont2++;
        }
    }
    return cont2;
}

int main() {
    srand(time(NULL));
    int mat[DIM][DIM];
    int risposta;
    riempiMatrice(mat);
    stampaMatrice(mat);
    cout << endl;
    cout << "Inserire un numero a piacere:" << endl;
    cin >> risposta;
    int cont = cercaNumero(mat, risposta);
    int cont2 = contaPrincipale(mat, risposta);
    cout << endl << "Il numero " << risposta << " trovato " << cont << " volta/e" << endl;
    cout << "Il numero " << risposta << " trovato " << cont2 << " volta/e";
    return 0;
}

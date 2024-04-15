/*
** Matrice.cpp una classe definata da noi che spupazza le matrice come nessuno mai
** Butt Abdul Mohid - 13/04/2024 
*/

#include <iostream>

using namespace std;

const int DIM = 6;

class Matrice {

private:
    int m[DIM][DIM];

public:
    Matrice(){
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++){
                m[i][j] = 97 + rand() % 26; // 97 equivale al codice ascii per la "a" minuscola
            }
        }
    }
    Matrice( char c ){
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++){
                m[i][j] = c;
            }
        }
    }

    char get( int x, int y ){
        return m[x][y];
    }

    void put( int x, int y, char c ){
        m[x][y] = c;
    }

    void stampa(){
        cout << "-----------------------------------------------------------------------------" << endl;
        for(int i = 0; i< DIM; i++){
            for(int j = 0; j < DIM; j++){
                printf("%c ", m[i][j]);
                //cout << m[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }

    void bomb(){
        int x = rand() % DIM;
        int y = rand() % DIM;
        m[x][y] = '*';
    }

    void placeHorizzontalShip( int len ) {
        if(len <= 0 || len >= DIM) return;
        int x = rand() % (DIM);
        int y = rand() % (DIM - len);
        for(int i=0;i<len;i++){
            m[x][y + i] = 'O';
        }
    }

    void placeVerticalShip( int len ) {
        if(len == 0 || len >= DIM) return;
        int x = rand() % (DIM - len);
        int y = rand() % (DIM);
        for(int i=0;i<len;i++){
            m[x + i ][y] = 'O';
        }
    }

};

int main(){
    srand(time(NULL));
    Matrice mappa = Matrice('-');
    Matrice campo = Matrice('.');

    campo.placeHorizzontalShip(3);
    campo.placeVerticalShip(4);
    campo.placeHorizzontalShip(1);
    campo.placeVerticalShip(2);

    //lancia 20 bombe a caso

    for(int i = 0; i < 20; i++){
        int x = rand() % DIM;
        int y = rand() % DIM;
        if (campo.get(x, y) == '0'){
            mappa.put(x, y, '*');
        }
    }

    mappa.stampa();
    campo.stampa();
    return 0;
}
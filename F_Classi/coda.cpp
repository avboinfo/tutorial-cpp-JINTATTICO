/*BUTT ABDUL MOHID
3 CIN 06/04/2024
CLASSE CODA DI INTERI*/
#include <iostream>

using namespace std;

// push inserisce valore nello stack
// pop rimuove dall'ultimo elemento dallo stack un valore alla volta
// la tecnica di salvataggio e rimozione usata è detta LIFO (Last-In-First-Out)

class Coda {

    private:
        int size, start, stop;
        int * v;

    public:
        Coda(int size) {
            this -> size = size;
            v=new int[size];
            start = stop = 0;
        }

        void enter(int val){
            if(stop>=size){cout<<"Coda piena"; return; }
            v[stop]=val;
            stop++;
        }

        int exit(){
            if(start>=stop){cout<<"Coda vuota"; return 0; } 
            int val = v[start];
            start = start +1;
            return v[start++]; 
        }
        void stampa(){
            cout << "Elementi in coda: " << endl;
            for(int i=start;i<stop;i++) cout <<  v[i] << endl;
            cout << "------------------------------------" << endl;
        }
};

int main() {

    Coda prova(1000);
    prova.stampa();
    prova.enter(100);
    prova.enter(120);
    prova.enter(85);
    prova.exit();
    prova.enter(345);
    prova.stampa();

    return 0;
}
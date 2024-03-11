/*BUTT ABDUL MOHID
3 CIN 04/03/2024
CLASSE VETTORE DI INTERI*/



#include <iostream>

using namespace std;

class Vettore{

    protected:

    int size, len, delta;
    int * v;

    public:

    Vettore( int size, int delta ){
        this->size = size;
        this->delta = delta;
        len = 0;
        v = new int[size];
    }

    void add( int  n ){
        if (len == size){
            cout <<"Estendo da " << size << " a " << size+delta << endl;
            int *nuovov = new int[size + delta];
            for(int i = 0; i<size;i++) nuovov[i] = v[i];
            size += delta;
            delete[] v;
            v = nuovov;
        }
        v[size] = n;
        len++;
    }

    int getElement(int index){
        return v[index];
    }

    void setElement(int index, int newvalue){
        v[index] = newvalue;
    }

    void print () {
        cout << "Contenuto del vettore: ";
        for(int i = 0;i < len;i++) cout << v[i] << " ";
        cout << endl;
    }
};

int main(int argc, char *argv[]){
    Vettore vett(10, 10);
    for(int i=0;i<100;i++) vett.add(i);
    cout << vett.getElement(10) << endl;
    vett.setElement(10, 333);

    vett.print();
}
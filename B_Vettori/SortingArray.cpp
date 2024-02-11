/*
* Legge da un file di input un vettore di stringhe
* e produce un file di output con il vettore ordinato
* Sandro Gallo - 5/2/2024
*/

#include <iostream>
#include <fstream>

using namespace std;


int p = 0;
/*const string FILENAME = "SortingArray.txt";

void stampaVettore( string v[], int l ) {
    cout << endl;
    for (int i=0; i<l; i++) cout << v[i] << "\n";
    cout << endl;
}*/

int bubbleSort( string v[], int l ) {
    int numOp = 0;
    string tmp;
    for (int i=0; i<l; i++ ) {
        bool alreadySorted = true;
        for (int j=0; j<l-1; j++ ) {
            if ( v[j] > v[j+1] ) {
                alreadySorted = false;
                tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
            numOp++;
        }
        if (alreadySorted) break;
    }
    return numOp;
}

/*int main()
{
    ifstream f;
    f.open(FILENAME);
    if ( f.fail() ) { cout << "Il file di input non esiste"; return -1; }
    
    // legge tutto il file per misurarne il numero di righe
    int n;
    string s;
    for (n=0; getline(f,s); n++);
    f.close();
    cout << "il file di input contiene " << n << " righe" << endl;
    
    // rilegge il file per caricarne le righe in un vettore
    string vs[n];
    f.open(FILENAME);
    for (int i=0; i<n; i++) getline( f, vs[i] );

    stampaVettore(vs, n);
    int x = bubbleSort(vs, n);
    cout << "Eseguiti " << x << " confronti." << endl;
    stampaVettore(vs, n);

    return 0;
}
*/

void printArray(string array[], int N){
    for (int i = 0; i<N; i++){
        cout<<array[i]<<endl;
    }
}

void swap(string array[] , int pos1, int pos2){
    string temp;
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
    p++;
}

int partition(string array[], int low, int high, string pivot){
    int i = low;
    int j = low;
    while( i <= high){
        if(array[i] > pivot){
            i++;
        }
        else{
            swap(array,i,j);
            i++;
            j++;
        }
    }
    return j-1;
}

void quickSort(string array[], int low, int high){
    if(low < high){
    string pivot = array[high];
    int pos = partition(array, low, high, pivot);
    
    quickSort(array, low, pos-1);
    quickSort(array, pos+1, high);
    }
}

int main (){

    ifstream input ("SortingArray.txt");

    int N = 0;
    string l;
    int giusto = 0;
    string scelta;

    while (getline(input, l)){
        N++;
    }

    string array[N];

    ifstream file ("SortingArray.txt");


    for (int i=0; i<N; i++) getline( file, array[i] );

    printArray(array, N);


    while (giusto == 0){
        cout<<"Con quale algoritmo di ordinamento vuoi ordinare il vettore di stringhe? Puoi scegliere tra BubbleSort (digita Bubble) e Quick Sort (digita Quick)"<<endl;
        cin>>scelta;
        if (scelta == "Bubble" || scelta =="bubble"){
            p = bubbleSort (array, N);
            giusto = 1;
        }
        else if (scelta == "Quick" || scelta == "quick"){
            quickSort(array, 0 , N-1);
            giusto = 1;
        }
        else {
            cout<<"Non hai inserito nulla di valido"<<endl;
        }
    }

    cout<<endl;
    printArray(array, N);

    cout<<"eseguiti "<<p<< " scambi";

    return 0;
}

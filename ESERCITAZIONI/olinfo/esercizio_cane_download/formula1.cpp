// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> H, V;

int main() {
    //  uncomment the following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];

    int sommaH = 0 ,sommaV = 0;

    for(int i=0;i<N;i++){
        sommaH += H[i];
    }
    for(int i=0;i<N;i++){
        sommaV += V[i];
    }
    if(sommaH < sommaV){
        cout << "Hamilton" << endl;
    }else{
        cout << "Verstappen" << endl;
    }

    int minV = V[0];
    int minH = H[0];

    for(int i=0;i<N;i++){
        if(H[i] < minH){
            minH = H[i];
        }
    }
    for(int i=0;i<N;i++){
        if(V[i] < minV){
            minV = V[i];
        }
    }
    if(minH < minV){
        cout << "Hamilton";
    }else{
        cout << " Verstappen";
    }
    return 0;
}

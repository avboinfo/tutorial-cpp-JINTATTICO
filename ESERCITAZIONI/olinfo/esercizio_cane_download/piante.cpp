#include <vector>


using namespace std;

int pollice_verde(int N, vector<int> H) {
    int numero_uguali = 0;
    for(int i = 0;i <N;i++){
        if(H[i] == H[i + 1]){
            numero_uguali ++;
        }
    }
    return numero_uguali;
}

#include <stdio.h>
#include <assert.h>


#define MAXN 100000

int N, i;
int V[MAXN];

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i = 0; i < N; i++) {
        assert(1 == scanf("%d", &V[i]));
    }

    int ultimo_valore = 0; 
    for (i = 0; i < N; i++) {
        if (V[i] == -1) {
            V[i] = ultimo_valore;  
        }
        if (V[i] < ultimo_valore) {
            V[i] = ultimo_valore;  
        }
        ultimo_valore = V[i]; 
    }

    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += V[i];  
    }

    printf("%d\n", sum); 
    return 0;
}

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// input data
int N;
string S;

int main() {
    // Uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    cin >> S;

    for(int i = 0; i < N; i++) {
        if(S[i] == 'q'){
            S[i] = 'w';
        }
        else if(S[i] == 'w'){
            S[i] = 'e';
        }
        else if(S[i] == 'e'){
            S[i] = 'r';
        }
        else if(S[i] == 'r'){
            S[i] = 't';
        }
        else if(S[i] == 't'){
            S[i] = 'y';
        }
        else if(S[i] == 'y'){
            S[i] = 'u';
        }
        else if(S[i] == 'u'){
            S[i] = 'i';
        }
        else if(S[i] == 'i'){
            S[i] = 'o';
        }
        else if(S[i] == 'o'){
            S[i] = 'p';
        }
        else if(S[i] == 'p'){
            S[i] = 'p'; // No change as 'p' is the last character in the row
        }
        else if(S[i] == 'a'){
            S[i] = 's';
        }
        else if(S[i] == 's'){
            S[i] = 'd';
        }
        else if(S[i] == 'd'){
            S[i] = 'f';
        }
        else if(S[i] == 'f'){
            S[i] = 'g';
        }
        else if(S[i] == 'g'){
            S[i] = 'h';
        }
        else if(S[i] == 'h'){
            S[i] = 'j';
        }
        else if(S[i] == 'j'){
            S[i] = 'k';
        }
        else if(S[i] == 'k'){
            S[i] = 'l';
        }
        else if(S[i] == 'l'){
            S[i] = 'l'; // No change as 'l' is the last character in the row
        }
        else if(S[i] == 'z'){
            S[i] = 'x';
        }
        else if(S[i] == 'x'){
            S[i] = 'c';
        }
        else if(S[i] == 'c'){
            S[i] = 'v';
        }
        else if(S[i] == 'v'){
            S[i] = 'b';
        }
        else if(S[i] == 'b'){
            S[i] = 'n';
        }
        else if(S[i] == 'n'){
            S[i] = 'm';
        }
        else if(S[i] == 'm'){
            S[i] = 'm'; // No change as 'm' is the last character in the row
        }
    }

    cout << S << endl; 
    return 0;
}

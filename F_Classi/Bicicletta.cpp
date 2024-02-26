/*
** Bicicletta.cpp
*/

#include <iostream>
using namespace std;

class Bicicletta {
  public:
    int raggio;
    string colore;
    Bicicletta() {
        raggio=10;
        colore="Bianco";
    }
    void presentati() {
        cout << "Buongiorno, sono una bici di colore " << colore << " e con le ruote " << raggio << "!" << endl;
    }
};

int main()
{
    Bicicletta x;
    x.presentati();
    return 0;
}

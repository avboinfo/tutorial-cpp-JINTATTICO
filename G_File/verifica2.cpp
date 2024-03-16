/*BUTT ABDUL MOHID  3 CIN  VERIFICA QUESITO 2  16/03/2024*/

#include <iostream>

class Orario {
private:
    int ore;
    int minuti;
    int secondi;

public:
    Orario(int h, int m, int s) {
        mettoOrario(h, m, s);
    }
    void mettoOrario(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            ore = h;
            minuti = m;
            secondi = s;
        }
        else{
            std::cout << "Orari non valido" << std::endl;
            exit(-1);
        }
    }

    void printOrario() {
        std::cout << ore << ":" << minuti << ":" << secondi;
    }

    int secondiMezzanotte() {
        int numero = ore * 3600 + minuti * 60 + secondi;
        return numero;
    }

    static int calcolaDifferenza(int tempo1, int tempo2) {
        return tempo1 - tempo2;
    }
};

int main() {
    Orario ora(12, 15, 43);
    Orario ora2(10, 12, 52);

    std::cout << "Orario: ";
    ora.printOrario();
    std::cout << std::endl;

    int sec = ora.secondiMezzanotte();
    std::cout << "Secondi passati dalla mezzanotte: " << sec << std::endl;

    int sec2 = ora2.secondiMezzanotte();

    int differenza = Orario::calcolaDifferenza(sec, sec2);
    
    std::cout << "Differenza in secondi tra i due orari: " << differenza << std::endl;

    return 0;
}

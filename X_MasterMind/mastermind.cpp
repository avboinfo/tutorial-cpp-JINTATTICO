#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class mastermind {
private:
    int numero_mosse;
    std::string ultima_mossa;
    static const int DIM_GIOCATA_VALIDA = 4;
    int mossa_valida[DIM_GIOCATA_VALIDA];
    int codice_segreto[DIM_GIOCATA_VALIDA];

    bool sanifica_input() {
        if (DIM_GIOCATA_VALIDA != ultima_mossa.size())
            return false;
        for(int i = 0; i < ultima_mossa.size(); i++) {
            char c = ultima_mossa[i];

            if(c >='0' && c <= '9')
                mossa_valida[i] = c - '0';
            else if(c == '-')  // il trattino verra convertito in -1  
                mossa_valida[i]= -1;
            else
                return false;
        }
        return true;
    }

    void genera_codice_segreto() {
        srand(time(NULL));
        for(int i = 0; i < DIM_GIOCATA_VALIDA; i++) {
            codice_segreto[i] = rand () % 10;
        }
        for(int i = 0; i < DIM_GIOCATA_VALIDA; i++) {
            std::cout << codice_segreto[i] << " ";
        }
        std::cout << std::endl;
    }


public:
    mastermind() {
        genera_codice_segreto();
        numero_mosse = 0;
        ultima_mossa = "";
    };

    void nuova_giocata() {
        do {
            std::cout << "Inserisci " << DIM_GIOCATA_VALIDA << " numeri: ";
            std::cin >> ultima_mossa;  
        } while (!sanifica_input());
        
        confronta_codice(mossa_valida);
    }

    void confronta_codice(int mossa[]) {
        int strike = 0;
        int ball = 0;
        int copia_vett[DIM_GIOCATA_VALIDA];
        for(int i = 0; i < DIM_GIOCATA_VALIDA; i++){
            copia_vett[i] = codice_segreto[i];
        }
        for (int i = 0; i < DIM_GIOCATA_VALIDA; i++) {
            for (int j = 0; j < DIM_GIOCATA_VALIDA; j++) {
                if (mossa[i] == copia_vett[i]) {
                    strike++;
                    copia_vett[i] = -2;
                }
                if(mossa[i] == copia_vett[j]){
                    ball++;
                    copia_vett[j] = -2;
                }
            }
        }
        std::cout << "Strike: " << strike << ", Ball: " << ball << std::endl;
    }
};
#include <iostream>
#include <cstdlib>
#include <ctime>
class mastermind
{
private:
    int numero_mosse;
    std::string ultima_mossa;

    static const int DIM_GIOCATA_VALIDA = 4;
    int mossa_valida[DIM_GIOCATA_VALIDA];
    int codice_segreto[DIM_GIOCATA_VALIDA];

    bool sanifica_input(){
        if (DIM_GIOCATA_VALIDA != ultima_mossa.size())
            return false;
        for(int i = 0; i < ultima_mossa.size(); i++){
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

    void genera_codice_segreto(){
        srand(time(NULL));
        for(int i = 0; i < DIM_GIOCATA_VALIDA; i++){
            codice_segreto[i] = rand () & 10;
        }
    }

public:

    mastermind(/* args */){
        numero_mosse = 0;
        ultima_mossa = "";
        genera_codice_segreto();
    };

    void nuova_giocata(){
        do{
            std::cout << numero_mosse + 1 << ": ";
            std::getline(std::cin, ultima_mossa);  
        }while(!sanifica_input());

        numero_mosse++;
    }

    void risultato_mossa(){
        int numeri_indovinati = 0;
        int posizioni_corrette = 0;

    // Calcola numeri indovinati e posizioni corrette
    for(int i = 0; i < DIM_GIOCATA_VALIDA; i++){
        if(mossa_valida[i] == codice_segreto[i]){
            posizioni_corrette++;
        }
        else{
            for(int j = 0; j < DIM_GIOCATA_VALIDA; j++){
                if(mossa_valida[i] == codice_segreto[j]){
                    numeri_indovinati++;
                    break;
                }
            }
        }
    }

    // Stampa risultato
    std::cout << "Numeri indovinati: " << numeri_indovinati << std::endl;
    std::cout << "Posizioni corrette: " << posizioni_corrette << std::endl;
    }

};

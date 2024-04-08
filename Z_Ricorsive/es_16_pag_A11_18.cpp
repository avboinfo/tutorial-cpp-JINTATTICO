#include <iostream>

class Poste {
private:
    char serv;
    char nuovoCliente;
public:
    int numeroClienteTotali = 0;
    int numeroClienteSpedizione = 0;
    int numeroClienteRicezione = 0;
    int numeroClienteFinanziario = 0;

    void motivoPoste() {
        std::cout << "Benvenuto alle poste di San Donato e San Vitale" << std::endl;
        std::cout << "Servizi disponibili: " << std::endl;
        std::cout << "[]SPEDIZIONE" << std::endl;
        std::cout << "[]RICEZIONE" << std::endl;
        std::cout << "[]FINANZIARIO" << std::endl;
    }

    void servizio() {
        std::cout << std::endl;
        std::cout << "Per prenotare SPEDIZIONE scrivere s" << std::endl;
        std::cout << "Per prenotare RICEZIONE scrivere r" << std::endl;
        std::cout << "Per prenotare FINANZIARIO scrivere f" << std::endl;
        std::cout << "PRENOTA: ";
        std::cin >> serv;
    }

    void numeroCliente(){
        generaNumeroCliente();        
    }

    void arrivoNuovoCliente(){
        for(int i=0; i<11; i++){
            std::cout <<"Arrivo nuovo cliente: S o N --> ";
            std::cin >> nuovoCliente; 
            if(nuovoCliente ==  'S'){
                servizio();
                generaNumeroCliente();
            }
            else{
                clientiAttesa();
                chiamataCliente();
                exit(-1);
            }
        }
    }

    void generaNumeroCliente() {
        if (serv == 's') {
            numeroClienteSpedizione++;
            std::cout << "Cliente, il tuo numero per SPEDIZIONE è S" << numeroClienteSpedizione << std::endl;
        }
        else if (serv == 'r') {
            numeroClienteRicezione++;
            std::cout << "Cliente, il tuo numero per RICEZIONE è R" << numeroClienteRicezione << std::endl;
        }
        else if (serv == 'f') {
            numeroClienteFinanziario++;
            std::cout << "Cliente, il tuo numero per FINANZIARIO è F" << numeroClienteFinanziario << std::endl;
        }
        else {
            std::cout << "SERVIZIO INVALIDO" << std::endl;
        }
    }

    void clientiAttesa(){
        std::cout << std::endl;
        std::cout << "CLIENTI IN ATTESA: " << std::endl;
        std::cout << "SPEDIZIONE--> " <<  numeroClienteSpedizione << std::endl;
        std::cout << "RICEZIONE--> " << numeroClienteRicezione  << std::endl;
        std::cout << "FINANZIARIO--> " <<  numeroClienteFinanziario << std::endl;  
    }

    void chiamataCliente() {
        char servizioChiamata;
        std::cout << "Servizio da chiamare (s/r/f): ";
        std::cin >> servizioChiamata;

        if (servizioChiamata == 's') {
            if (numeroClienteSpedizione > 0) {
                std::cout << "Chiamata cliente per SPEDIZIONE" << std::endl;
                numeroClienteSpedizione--;

            } else {
                std::cout << "Nessun cliente in attesa per SPEDIZIONE" << std::endl;
            }
        } else if (servizioChiamata == 'r') {
            if (numeroClienteRicezione > 0) {
                std::cout << "Chiamata cliente per RICEZIONE" << std::endl;
                numeroClienteRicezione--;
            } else {
                std::cout << "Nessun cliente in attesa per RICEZIONE" << std::endl;
            }
        } else if (servizioChiamata == 'f') {
            if (numeroClienteFinanziario > 0) {
                std::cout << "Chiamata cliente per FINANZIARIO" << std::endl;
                numeroClienteFinanziario--;
            } else {
                std::cout << "Nessun cliente in attesa per FINANZIARIO" << std::endl;
            }
        } else {
            std::cout << "Servizio invalido" << std::endl;
        }
    }
};

int main() {
    Poste prova;
    prova.motivoPoste();
    prova.arrivoNuovoCliente();
    prova.servizio();
    prova.generaNumeroCliente();
    prova.clientiAttesa();
    prova.chiamataCliente();

    return 0;
}

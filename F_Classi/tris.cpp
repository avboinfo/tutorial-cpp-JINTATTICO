/* 
se in griglia c'e' ZERO cella vuota
se in griglia c'e' UNO stiamo parlando di una X o (giocatore 1)
se in griglia c'e' DUE stiamo parlando di un CERCHIO (giocatore 2)
*/

#include <iostream>

using namespace std;


const int L = 3;

class Tris_classe{
    public: 
        string griglia [L][L];
    
        void nuovaGriglia (){
            for (int i = 0; i<L; i++){
                for (int j = 0; j<L; j++){
                    griglia[i][j] = "0"; 
                }
            }

        }


        void stampaGioco(){
                for (int i = 0; i<L; i++){
                    for (int j = 0; j<L; j++){
                        if (griglia[i][j] == "1"){
                            griglia[i][j] = "X";
                        }
                        if (griglia[i][j] == "2"){
                            griglia[i][j] = "O";
                        }
                        cout<<griglia[i][j]<<"\t";
                    }
                    cout<<endl;
                }
            }

        bool piazzaX(int x, int y){
            if (x > 2 || x < 0){
                return false;
            }
            if (y > 2 || y < 0){ 
                return false;
            }
            if (griglia[x][y] != "0"){ 
                return false;
            }
            griglia[x][y] = "1";
            return true;
        }

        bool piazzaO(int x, int y){
        if (x > 2 || x < 0){ 
                return false;
            }
            if (y > 2 || y < 0){ 
                return false;
            }
            if (griglia[x][y] != "0"){ 
                return false;
            }
            griglia[x][y] = "2";
            return true;
        }

        int vincenteGioco(){
            int risultato;
            for (int i = 0; i<L; i++){
                risultato = controlla_colonna(i);
                if (risultato != 0){
                    return risultato;
                }
                risultato = controlla_riga(i);
                if (risultato != 0){
                    return risultato;
                }
            }
        }
    private:
        int controlla_colonna(int colonna){
            int uno = 0;
            int due = 0;
            for (int i = 0; i<L; i++){
                string casella = griglia[i][colonna];
                if (casella == "X"){
                    uno++;
                }
                else if (casella == "O"){
                    due++;
                }
            }
            if (uno == 3){
                return 1;
            }
            else if (due == 3){
                return 2;
            }
            else{
                return 0;
            }

        }

        int controlla_riga(int riga){
            int uno = 0;
            int due = 0;
            for (int i = 0; i<L; i++){
                string casella = griglia[riga][i];
                if (casella == "X"){
                    uno++;
                }
                else if (casella == "O"){
                    due++;
                }
            }
            if (uno == 3){
                return 1;
            }
            else if (due == 3){
                return 2;
            }
            else{
                return 0;
            }

        }  
        int controlla_diagonale(){
            return 0;
        }


}; 

int main(){
    cout<<"Tris:"<<endl;

    Tris_classe Tris;

    Tris.nuovaGriglia ();

    Tris.stampaGioco();


    int x, y;
    bool valido;
    int end = 0;


    while (end == 0){
        do{ 
        cout<<"Giocatore 1 : valori da (da 0 a 2): "<<endl;
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        valido = Tris.piazzaX(x, y);
        } while (!valido);

        Tris.stampaGioco();

        end = Tris.vincenteGioco();
        if (end!=0){
            break;
        }

        do{ 
        cout<<"Giocatore 2 : valori da (da 0 a 2): "<<endl;
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        valido = Tris.piazzaO(x, y);
        } while (!valido);

        Tris.stampaGioco();

        end = Tris.vincenteGioco();
        if (end != 0){
            break;
        }
        int mosse_totali = 0;
        mosse_totali = mosse_totali + 2;
    }
    if(end ==1)
        cout << "Vince giocatore 1" << endl;
    else if (end == 2)
        cout << "Vince giocatore 2" << endl;
    else
        cout << "Pareggio" << endl;
    

    return 0;
}
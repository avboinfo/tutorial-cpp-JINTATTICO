#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    long long A, B, T;
    cin >> A >> B >> T;

    int ore_operative_al_giorno = B - A;
    int downtime = 0;

    if (ore_operative_al_giorno == 24) {
        // I server sono operativi tutto il giorno
        downtime = T;
    } else {
        int remaining_hours = T;
        int start_maintenance = 19;

        // Calcola downtime per il primo giorno
        if (start_maintenance < B) {
            if (start_maintenance < A) {
                start_maintenance = A;
            }
            if (start_maintenance < B) {
                int first_day_downtime = B - start_maintenance;
                downtime += first_day_downtime;
                remaining_hours -= first_day_downtime;
            }
        }

        // Calcola downtime per i giorni successivi
        while (remaining_hours > 0) {
            if (remaining_hours >= ore_operative_al_giorno) {
                downtime += ore_operative_al_giorno;
                remaining_hours -= ore_operative_al_giorno;
            } else {
                downtime += remaining_hours;
                remaining_hours = 0;
            }
        }
    }

    cout << downtime << endl;

    return 0;
}

// long long g_interi = T/24
// long long tempo_online = B -A
// long long left_over = tempo_online * g_interi
// T = T - G_INTERI*24
// T = T - (24 - TEMPO_ONLINE)
// IF (T <0) --> T =0
// COUT << T + LEFT_OVER << ENDL
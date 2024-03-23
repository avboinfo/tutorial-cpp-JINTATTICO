#include "mastermind.cpp"

using namespace std;

int main() {
  mastermind prova = mastermind();
  prova.nuova_giocata();
  static const int DIM_GIOCATA_VALIDA = 4;
  int mossa[DIM_GIOCATA_VALIDA];
  prova.confronta_codice(mossa);
  return 0;
}

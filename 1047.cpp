#include <iostream>
using namespace std;

int main() {
    int hi, mi, hf, mf; // hora inicio, minuto inicio, hora fim, minuto fim
    cin >> hi >> mi >> hf >> mf;
    int inicio, fim, tempo_min, horas, minutos;

    inicio = hi * 60 + mi;
    fim = hf * 60 + mf;
    if (fim <= inicio) fim += 24 * 60;

    tempo_min = fim - inicio;

    horas = tempo_min / 60;
    minutos = tempo_min % 60;

    cout << "O JOGO DUROU " << horas << " HORA(S) E " << minutos << " MINUTO(S)" << endl;
    return 0;
}

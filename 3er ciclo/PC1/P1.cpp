#include <iostream>
using namespace std;

void hanoi(int nDiscos, char origen, char destino, char pivote) {
    if (nDiscos == 1) {
        cout << "Mueve el disco de " << origen << " a " << destino << "\n";
        return;
    }
    hanoi(nDiscos - 1, origen, pivote, destino);
    cout << "Mueve el disco de " << origen << " a " << destino << "\n";
    hanoi(nDiscos - 1, pivote, destino, origen);

}

int main() {
    int t;
    cin >> t;

    int n;
    char src, dst, pvt;

    while (t--) {
        cin >> n >> src >> dst;
        pvt = 'A' + 'B' + 'C' - src - dst;
        hanoi(n, src, dst, pvt);
        cout << "Listo!\n" << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <random>
using namespace std;

using ContainerRange = int;

static std::random_device rd;
static std::mt19937 gen(rd());

template <typename T>
void intercambiar (T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
ContainerRange particionar (T arr[], ContainerRange first, ContainerRange last) {
    //usando la sugerencia
    uniform_int_distribution<int> distr(first, last);
    int random_index = distr(gen);

    intercambiar(arr[random_index], arr[last]);
    
    auto pivote = arr[last];
    auto i = (first - 1);

    for (auto j = first; j <= last - 1; ++j) {
        if (arr[j] < pivote) {
            ++i;
            intercambiar (arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[last]);
    return (i + 1);
}

template <typename T>
void QuickSort (T arr[], ContainerRange first, ContainerRange last) {
   if (first < last) {
        auto pivot = particionar(arr, first, last);
        QuickSort(arr, first, pivot - 1);
        QuickSort(arr, pivot + 1, last);
    }
}

ContainerRange obtenerCapitan (ContainerRange *equipo, ContainerRange *pos) {
    ContainerRange capitan = equipo [0];
    ContainerRange mejorPos = pos[equipo[0]];

    if (pos[equipo[1]] < mejorPos) {
        mejorPos = pos[equipo[1]];
        capitan = equipo[1];
    }

    if (pos[equipo[2]] < mejorPos) {
        mejorPos = pos[equipo[2]];
        capitan = equipo[2];
    }
    return capitan;
}

void KNoCapitan (int k, int totalEstudiantes) {
    bool primero = true;
    for (auto i = 1; i <= totalEstudiantes; ++i) {
        if (i == k) continue;

        if (!primero) cout << " ";
        cout << i;
        primero = false;
    }
    cout << "\n";
}

void KEsCapitan(int k, ContainerRange equipoDeK, ContainerRange** equipos, int n, int totalEstudiantes) {
    ContainerRange* grupo1 = new ContainerRange[totalEstudiantes];
    int tam1 = 0;

    ContainerRange* grupo2 = new ContainerRange[totalEstudiantes];
    int tam2 = 0;

    for (auto i = 0; i < equipoDeK; ++i) {
        grupo1[tam1++] = equipos[i][0];
        grupo1[tam1++] = equipos[i][1];
        grupo1[tam1++] = equipos[i][2];
    }

    for (auto j = 0; j < 3; ++j) {
        if (equipos[equipoDeK][j] != k) {
            grupo1[tam1++] = equipos[equipoDeK][j];
        }
    }

    for (auto i = equipoDeK + 1; i < n; ++i) {
        grupo2[tam2++] = equipos[i][0];
        grupo2[tam2++] = equipos[i][1];
        grupo2[tam2++] = equipos[i][2];
    }

    if (tam1 > 1) QuickSort(grupo1, 0, tam1 - 1);
    if (tam2 > 1) QuickSort(grupo2, 0, tam2 - 1);

    bool primero = true;
    
    for (auto i = 0; i < tam1; ++i) {
        if (!primero) cout << " ";
        cout << grupo1[i];
        primero = false;
    }
    
    for (auto i = 0; i < tam2; ++i) {
        if (!primero) cout << " ";
        cout << grupo2[i];
        primero = false;
    }
    cout << "\n";

    delete[] grupo1;
    delete[] grupo2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int totalEstudiantes = 3 * n;
    
    ContainerRange* pos = new ContainerRange[totalEstudiantes + 1];
    for (auto i = 1; i <= totalEstudiantes; ++i) {
        int id;
        cin >> id;
        pos[id] = i; 
    }

    ContainerRange** equipos = new ContainerRange*[n];
    ContainerRange* capitanes = new ContainerRange[n];
    
    ContainerRange equipoDeK = -1;

    for (int i = 0; i < n; ++i) {
        equipos[i] = new ContainerRange[3];
        cin >> equipos[i][0] >> equipos[i][1] >> equipos[i][2];
        
        capitanes[i] = obtenerCapitan(equipos[i], pos);
    }

    int k;
    cin >> k;

    for (auto i = 0; i < n; ++i) {
        if (equipos[i][0] == k || equipos[i][1] == k || equipos[i][2] == k) {
            equipoDeK = i;
            break;
        }
    }

    if (capitanes[equipoDeK] != k) {
        KNoCapitan(k, totalEstudiantes);
    } else {
        KEsCapitan(k, equipoDeK, equipos, n, totalEstudiantes);
    }

    delete[] pos;
    delete[] capitanes;
    for (auto i = 0; i < n; ++i) {
        delete[] equipos[i];
    }
    delete[] equipos;

    return 0;
}

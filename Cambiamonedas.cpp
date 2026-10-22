
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int C(vector<int> V, int M) {
    int n = V.size();
    int INF = numeric_limits<int>::max();

    vector<vector<int>> T(n, vector<int>(M + 1, INF));

    T[0][0] = 0;

    for (int j = 1; j < M + 1; j++) {
        if (j >= V[0] && T[0][j - V[0]] != INF) {
            T[0][j] = 1 + T[0][j - V[0]];
        }
    }

    for (int i = 1; i < n; i++) {
        T[i][0] = 0;

        for (int j = 1; j < M + 1; j++) {
            if (j < V[i] || T[i][j - V[i]] == INF) {
                T[i][j] = T[i - 1][j];
            }
            else if (T[i - 1][j] != INF) {
                T[i][j] = min(T[i - 1][j],
                              1 + T[i][j - V[i]]);
            }
            else {
                T[i][j] = 1 + T[i][j - V[i]];
            }
        }
    }

    return T[n - 1][M];
}

int main() {
    vector<int> monedas = {1, 4, 6};
    int M = 8;

    int resultado = C(monedas, M);

    if (resultado == numeric_limits<int>::max()) {
        cout << "No se puede devolver esa cantidad" << endl;
    }
    else {
        cout << "Minimo de monedas: " << resultado << endl;
    }

    return 0;
}

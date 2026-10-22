int mochila(vector<int> p, vector<int> b, int m, vector<int>& s) {
    int n = p.size();
    vector<vector<int>> F(n + 1, vector<int>(m + 1, 0));

    // Calcular el beneficio maximo
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < p[i - 1]) {
                F[i][j] = F[i - 1][j];
            } else {
                int sinObjeto = F[i - 1][j];
                int conObjeto = b[i - 1] + F[i - 1][j - p[i - 1]];

                F[i][j] = max(sinObjeto, conObjeto);
            }
        }
    }

    // Reconstruir los objetos elegidos
    s = vector<int>(n, 0);
    int j = m;

    for (int i = n; i > 0; i--) {
        if (F[i][j] != F[i - 1][j]) {
            s[i - 1] = 1;
            j = j - p[i - 1];
        }
    }

    return F[n][m];
}
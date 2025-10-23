#include <iostream>
using namespace ;
int main() {
    
    int n, p, d, x, i, j, t, k, z, inizio, fine, c, indice, medio;
    cout << "Insersci i nueri random" << endl;
    cin >> n;
    int vp[n];
    int vd[n];
    p = 0;
    d = 0;
    x = 0;
    i = 0;
    while (i < n) {
        x = rand() % 101;
        if (x % 2 == 0) {
            vp[p] = x;
            p = p + 1;
        } else {
            vd[d] = x;
            d = d + 1;
        }
        i = i + 1;
    }
    cout << "Numeri pari" << endl;
    i = 0;
    while (i < p) {
        cout << vp[p] << endl;
        i = i + 1;
    }
    cout << "Numeri dispari" << endl;
    i = 0;
    while (i < d) {
        cout << vd[d] << endl;
        i = i + 1;
    }
    cout << "Numeri pari ordinati: " << endl;
    i = 0;
    while (i < p) {
        j = 0;
        while (j <= p - 2 - i) {
            if (vp[j] > vp[j + 1]) {
                t = vp[j];
                vp[j] = vp[j + 1];
                vp[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < p) {
        cout << vp[i] << endl;
        i = i + 1;
    }
    cout << "Numeri dispari ordinati: " << endl;
    i = 0;
    while (i < d) {
        j = 0;
        while (j <= d - 2 - i) {
            if (vd[j] > vd[j + 1]) {
                t = vd[j];
                vd[j] = vd[j + 1];
                vd[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    while (i < d) {
        cout << vd[i] << endl;
        i = i + 1;
    }
    cout << " MERGE " << endl;
    int v3[p + d];

    i = 0;
    j = 0;
    k = 0;
    while (i < p && j < d) {
        if (vp[i] <= vd[j]) {
            v3[k] = vp[i];
            i = i + 1;
        } else {
            v3[k] = vd[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < p) {
        v3[k] = vp[i];
        i = i + 1;
        k = k + 1;
    }
    k = 0;
    while (j < d) {
        v3[k] = vd[i];
        j = j + 1;
        k = k + 1;
    }
    k = 0;
    while (k < p + d) {
        cout << v3[k] << endl;
    }
    cout << "Ricerca binaria" << endl;
    cout << "Inserisci il numero da cercare" << endl;
    cin >> z;
    inizio = 0;
    fine = p + d - 1;
    c = 0;
    indice = (int) (-1);
    while (inizio <= fine && indice <= -1) {
        medio = (int) (inizio + (double) (fine - inizio) / 2);
        c = c + 1;
        if (v3(medio) == z) {
            indice = medio;
        } else {
            if (v3(medio) > z) {
                fine = medio - 1;
            } else {
                inizio = medio + 1;
            }
        }
    }
    if (indice == -1) {
        cout << "Indice non trovato" << endl;
    } else {
        cout << "Ho trovato il valore " << z << " nella cella " << indice << endl;
    }
    return 0;
}
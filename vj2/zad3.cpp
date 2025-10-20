#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double** alociraj(int m, int n) {
    double** a = new double*[m];
    for (int i = 0; i < m; i++)
        a[i] = new double[n];
    return a;
}

void dealociraj(double** a, int m) {
    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete[] a;
}

void unesi(double** a, int m, int n) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
}

void generiraj(double** a, int m, int n, double min, double max) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = min + (max - min) * rand() / RAND_MAX;
}

void ispisi(double** a, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(10) << fixed << setprecision(4) << a[i][j];
        cout << endl;
    }
}

double** zbroji(double** A, double** B, int m, int n) {
    double** C = alociraj(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** oduzmi(double** A, double** B, int m, int n) {
    double** C = alociraj(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** transponiraj(double** A, int m, int n) {
    double** T = alociraj(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}

int main() {
    srand(time(0));

    int m = 2, n = 3;
    double** A = alociraj(m, n);
    double** B = alociraj(m, n);

    cout << "Unesi elemente matrice A (" << m << "x" << n << "):\n";
    unesi(A, m, n);

    cout << "Generiram matricu B u rasponu [0,5]\n";
    generiraj(B, m, n, 0, 5);

    cout << "A:\n"; ispisi(A, m, n);
    cout << "B:\n"; ispisi(B, m, n);

    double** C = zbroji(A, B, m, n);
    cout << "A + B:\n"; ispisi(C, m, n);

    double** T = transponiraj(A, m, n);
    cout << "Transponirana A:\n"; ispisi(T, n, m);

    dealociraj(A, m);
    dealociraj(B, m);
    dealociraj(C, m);
    dealociraj(T, n);

    return 0;
}

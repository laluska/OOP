#include <iostream>
#include <algorithm>
#include <cstddef>
using namespace std;

template <typename T>
inline bool ascending(T a, T b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
inline bool descending(T a, T b) {
    if (a > b) {
        return false;
    } else {
        return true;
    }
}

template <typename T>
void sort(T niz[], size_t n, bool (*cmp)(T, T)) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(niz[i], niz[j])) {
                swap(niz[i], niz[j]);
            }
        }
    }
}

int main() {
    int niz[] = {2, 1, 3, 9, 5, 4, 7};
    size_t n = 7;

    sort(niz, n, ascending);
    cout << "Uzlazno:" << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << endl;
    }

    sort(niz, n, descending);
    cout << "silazno:" << endl;
    for (int i = 0; i < n; i++) {
        cout << niz[i] << endl;
    }

    return 0;
}

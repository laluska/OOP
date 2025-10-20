#include <iostream>

int& at(int niz[], int i) {
    return niz[i];
}

int main() {
    int niz[5] = {1, 2, 3, 4, 5};
    int i;
    std::cin >> i;
    at(niz, i)++;
    for (int x : niz)
        std::cout << x << " ";
    return 0;
}

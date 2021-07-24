#include <iostream>
#include "kmp.hpp"

using std::cout;

int main() {
    const char *T = "sababadoababao";
    const char *P = "ababa";
    int *A = new int[5]; //A = {-1, -1, 0, 1, 2}
    int *O = new int[6];
    kmp(P, T, O);
    for (int i = 0; i < 5; ++i) {cout << O[i] << ' '; if (O[i]==-1) break;}
    cout << '\n';
    return 0;
}
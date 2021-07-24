#ifndef kmp_hpp
#define kmp_hpp

bool makeAuxTable(const char *P, int *A) {
    if (!A) return false;
    A[0] = -1;
    int i = 0;
    while (P[i+1] != '\0') {
        int j = A[i];
        while (true) {
            if (P[i+1] == P[j+1]) {
                A[i+1] = j + 1;
                break;
            }
            else {
                if (j == -1) {
                    A[i+1] = -1;
                    break;
                }
                j = A[j];
            }
        }
        ++i;
    }
    return true;
}

bool kmp(const char *P, const char *T, int *O) {
    if (!O) return false;
    int *A = new int[sizeof(P)/sizeof(*P)];
    if (!makeAuxTable(P, A)) return false;
    int i = 0, j = 0, k = 0;
    while (T[i] != '\0') {
        if (T[i] == P[j]) {
            if (P[j+1] == '\0') {
                O[k] = i-j;
                ++k;
                j = A[j];
            }
            ++i; ++j;
        }
        else {
            if (j == 0) ++i;
            else j = A[j-1] + 1;
        }
    }
    O[k] = -1;
    return true;
}

#endif
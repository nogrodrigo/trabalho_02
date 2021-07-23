#ifndef kmp_hpp
#define kmp_hpp

void makeAuxTable(char *P, int *A, int n) {
    A[0] = -1;
    for (int i = 0; i < n - 1; ++i) {
        int j = A[i];
        if (P[i+1] == P[j+1]) {
            A[i+1] = j+1;
        }
        else {
            j = A[j];
            while (j != -1) {
                if (P[i+1] == P[j+1]) {
                    A[i+1] = j + 1;
                    break;
                }
                j = A[j];
            }
        }
    }
}

#endif
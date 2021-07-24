#ifndef bruteForce_hpp
#define bruteForce_hpp

bool bruteForce(const char* T, const char* P, int* O) {
    if (!O) return false;
    int *l = O;

    for (const char *i = T; *i != '\0'; ++i) {
        const char *j = i, *k = P;
        while (*k != '\0') {
            ++j;
            ++k;
            if (*k == '\0' and *j == *k) {
                *l = i - T;
                ++l;
            }
        }
    }
    *l = -1;
}

#endif bruteForce_hpp
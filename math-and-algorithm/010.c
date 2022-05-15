#include <stdio.h>

long fact(long n) {
    if (n == 1) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}

int main() {
    long N;
    scanf("%d", &N);
    printf("%d\n", fact(N));
    return 0
}

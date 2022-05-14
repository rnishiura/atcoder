#include <stdio.h>

int main() {
    long N;
    scanf("%ld", &N);
    printf("%d\n", 1);

    if(N==1) return 0;

    for(long i=2; i<=N/2; i++) {
        if(N%i == 0) {
            printf("%ld\n", i);
        }
    }

    printf("%ld\n", N);

    return 0;
}

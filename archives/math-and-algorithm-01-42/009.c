#include <stdio.h>

int sum(int k) {
    return (k+1) * k/2;
}

int eval(int n, int s) {
    if (s >= 2*n){
        return n*n;
    } else if (s >= n) {
        return n*n - sum(2*n-s);
    } else {
        return sum(s-1);
    }
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    printf("%d", eval(n, s));

    return 0;
}
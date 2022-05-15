#include <stdio.h>
#define SUM(k) ((k+1)*(k)/2) 
#define EVAL(n, s) ((s >= n) ? n*n - SUM(2*n-s) : SUM(s-1))
#define EVAL2(n, s) (s >= 2*n ? n*n : EVAL(n, s))

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    printf("%d", EVAL2(n, s));
    return 0;
}
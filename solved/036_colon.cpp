#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll A, B, H, M;
  cin >> A >> B >> H >> M;
  double C = cos(2*M_PI*(H / 12.0 + 1 / 12.0 * M / 60.0 - M / 60.0));
  printf("%.9lf\n", sqrt(POW(A)+POW(B)-2*A*B*C));
}


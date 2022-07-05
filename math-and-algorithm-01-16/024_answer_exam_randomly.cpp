#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  int N;
  cin >> N;

  double E = 0;
  int P, Q;
  for(int i=0; i<N; i++) {
    cin >> P >> Q;
    E += (double) Q/P;
  }
  printf("%lf\n", E);
}

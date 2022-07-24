#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll x[N], y[N];
  double m = DBL_MAX;
  for(ll i=0; i<N; i++) {
    cin >> x[i] >> y[i];
    for(ll j=0; j<i; j++) {
      m = min(m, (double)POW(x[i]-x[j])+POW(y[i]-y[j]));
    }
  }
  printf("%.9lf\n", sqrt(m));
}


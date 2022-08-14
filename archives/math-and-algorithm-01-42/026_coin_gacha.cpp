#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  double p = 0;
  for(ll i=0; i<N; i++) {
    p += (double)N / (N-i);
  } 
  printf("%.6lf\n", p);
}

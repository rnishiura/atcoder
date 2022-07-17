#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N, a, b;
  cin >> N >> a >> b;

  ll A[N];
  ll _sum = 0;
  ll _min = 1000000000;
  for(ll i = 0; i<N; i++) {
    cin >> A[i];
    _sum += A[i];
    _min = min(_min, A[i]);
  }

  ll LL = _min;
  ll UL = _sum / N;

  while(true) {
    ll C = (UL-LL) / 2 + LL;
    ll LC=0, UC=0;
    for(ll i=0; i<N; i++) {
      ll e = A[i];
      if (e>C) UC += (e-C) / b;
      if (e<C) LC += (ll)ceil((C-e) / (double)a);
    }
    if (UC >= LC) {
      if (LL==C) {
        break;
      }
      LL = C;
    }
    else {
      if (UL==C) {
        break;
      }
      UL = C;
    }
  }
  
  ll C = UL;
  ll LC=0, UC=0;
  for(ll i=0; i<N; i++) {
    ll e = A[i];
    if (e>C) UC += (e-C) / b;
    if (e<C) LC += (ll)ceil((C-e) / (double)a);
  }
  if (UC >= LC) {
    cout << UL << endl;
  }
  else {
    cout << LL << endl;
  }
}
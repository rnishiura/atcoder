#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll h0, h1, h2, DP0=0, DP1=0, DP2=0;

  cin >> h1 >> h0;
  DP0 = abs(h1-h0);
  for(ll i=2; i<N; i++) {
    DP2 = DP1;
    DP1 = DP0;
    h2 = h1;
    h1 = h0;
    cin >> h0;
    DP0 = min(DP1+abs(h1-h0), DP2+abs(h2-h0));
  }

  cout << DP0 << endl;
}


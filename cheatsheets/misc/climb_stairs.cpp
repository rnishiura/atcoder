#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll DP0=1, DP1=1, DP2;

  for(ll i=1; i<N; i++) {
    DP2 = DP1;
    DP1 = DP0;
    DP0 = DP1 + DP2;
  }

  cout << DP0 << endl;

}


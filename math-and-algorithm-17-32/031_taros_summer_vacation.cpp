#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll A, DP0, DP1=0, DP2=0;
  for(ll i=0; i<N; i++) {
    cin >> A;
    DP0 = max(DP1, DP2+A);
    DP2 = DP1;
    DP1 = DP0;
  }
  cout << DP0 << endl;
}


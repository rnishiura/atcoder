#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N, W;
  cin >> N >> W;

  ll w[N+1], v[N+1];
  for(ll i=1; i<=N; i++) cin >> w[i] >> v[i];

  ll D[N+1][W+1];
  for(ll j=0; j<=W; j++) D[0][j] = 0;
  for(ll i=1; i<=N; i++) {
    for(ll j=0; j<=W; j++) {
      if (j < w[i]) D[i][j] = D[i-1][j];
      else  D[i][j] = max(D[i-1][j], D[i-1][j-w[i]]+v[i]);
    }
  }
  
  // for(ll i=0; i<=N; i++) {
  //   for(ll j=0; j<=W; j++) {
  //     cout << D[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << D[N][W] << endl;
  return 0;
}


#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;
#define MAX 5001
int main(void) {
  ll N, M;
  cin >> N >> M;

  ll X[N+1];
  for(ll i=1; i<=N; i++) {
    cin >> X[i];
  }

  ll Y[MAX];
  for(ll i=0; i<MAX; i++) Y[i] = 0;
  for(ll i=0; i<M; i++) {
    ll C;
    cin >> C;
    cin >> Y[C];
  }

  ll DP[N+1][N+1];
  for(ll i=0; i<=N; i++) {
    for(ll j=0; j<=N; j++) {
      DP[i][j] = 0;
    }
  }

  // DP[0][1] = X[0] + Y[1];
  for(ll i=1; i<=N; i++) {
    ll mx = DP[i-1][0];
    // cout << i << " ";
    for(ll j=1; j<=i; j++) {
      mx = max(mx, DP[i-1][j]);
      DP[i][j] = DP[i-1][j-1] + X[i] + Y[j];
      // cout << DP[i][j] << " ";
    }
    // cout << endl;
    DP[i][0] = mx;
  }
  
  ll mx = DP[N][0];
  for(ll i=0; i<=N; i++) {
    mx = max(mx, DP[N][i]);
    // cout << mx << endl;
  }
  cout << mx << endl;

}


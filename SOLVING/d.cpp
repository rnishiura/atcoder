#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll pow2(ll a) { return pow(a, 2); }

ll pow2(ll a) { return (ll)(pow(a, 2)+0.5); }

ll pow2(ll a) { return a * a; }

int main(void) {
  ll N, i, j;
  cin >> N;

  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  ll X[N], Y[N], R[N], dist2;
  for(ll i=0; i<N; i++) {
    cin >> X[i] >> Y[i] >> R[i];
  }

  // create memo
  set<ll> memo[N];
  for(ll i=0; i<N; i++) {
    for(ll j=i+1; j<N; j++) {
      dist2 = pow2(X[i]-X[j]) + pow2(Y[i]-Y[j]);
      if(dist2 <= pow2(R[i]+R[j]) && dist2 >= pow2(R[i]-R[j]) ) {
        memo[i].insert(j);
        memo[j].insert(i);
      }
    }
  }

  // find first circle
  for(i=0; i<N; i++) {
    if(pow2(R[i]) == pow2(X[i]-sx) + pow2(Y[i]-sy)) break;
  }
  for(j=0; j<N; j++) {
    if(pow2(R[j]) == pow2(X[j]-tx) + pow2(Y[j]-ty)) break;
  }
  if(i==j) {
    cout << "Yes" << endl;
    return 0;
  }

  int DP[N];
  for(ll k=0; k<N; k++) DP[k] = 0;
  DP[i] = 1;
  
  while(true) {
    bool flg = false;
    for(ll i=0; i<N; i++) {
      if(DP[i] == 1) {
        DP[i] = 2;
        flg = true;
        for(auto mitr = memo[i].begin(); mitr != memo[i].end(); mitr++) {
          if(*mitr == j) {
            cout << "Yes" << endl;
            return 0;
          }
          if(DP[*mitr] == 0) {
            DP[*mitr] = 1;
          }
        } 
      }
    }
    if (!flg) break;
  }
  
  cout << "No" << endl;
}


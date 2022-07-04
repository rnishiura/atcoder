#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  int N, W;
  cin >> N >> W;

  ll DP[W+1]; for(ll i=0; i<=W; i++) DP[i] = 0; 
  ll v, w;

  for(ll i=0; i<N; i++) {
    cin >> v >> w;
    for(ll j=W; j>0; j--) if(j >= w) DP[j] = max(DP[j], v+DP[j-w]);
  }

  cout << DP[W] << endl;
}


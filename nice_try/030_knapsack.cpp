// TOO SLOW
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll rf(ll W, ll V, ll *w, ll *v, ll N) {
  if (W <= 0 || N == 0) return V;
  if (W < w[0]) return rf(W, V, w+1, v+1, N-1);
  return max(rf(W, V, w+1, v+1, N-1), rf(W-w[0], V+v[0], w+1, v+1, N-1));
}

int main(void) {
  ll N, W;
  cin >> N >> W;

  ll w[N], v[N];
  for(ll i=0; i<N; i++) cin >> w[i] >> v[i];

  cout << rf(W, 0, w, v, N) << endl;

  return 0;
}


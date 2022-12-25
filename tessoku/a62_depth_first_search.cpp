#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define print(z) cout << (z) << endl
#define print2(x, y) cout << (x) << " " << (y) << endl
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define uset unordered_set
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void bfs(ll pt, vv &nl, uset<ll> &pl) {
  for(auto nb: nl[pt]) {
    if(!contains(nb, pl)) {
      pl.insert(nb);
      bfs(nb, nl, pl);
    }
  }
}

int main(void) {
  ll n, m;
  cin >> n >> m;

  vv nl(n+1);
  v u(2);
  rep(i, m) {
    cin >> u[0] >> u[1];
    rep(j, 2) nl[u[j]].pb(u[1-j]);
  }

  uset<ll> pl{1};
  bfs(1, nl, pl);

  // for(auto a: pl) print(a);
  repi(i, 1, n+1) {
    if(!contains(i, pl)) {
      print("The graph is not connected.");
      return 0;
    }
  }
  print("The graph is connected.");
}

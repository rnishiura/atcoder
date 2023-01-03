#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 1000000007
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll n, m;
  cin >> n >> m;

  vv g(n+1); v u(2);
  rep(i, m) {
    cin >> u[0] >> u[1];
    rep(j, 2) g[u[j]].pb(u[1-j]);
  }

  v d(n+1, 0); d[1] = 1;
  v s(n+1, -1); s[1] = 0;
  set<ll> fr = {1};
  while(fr.size()) {
    set<ll> to;
    for(auto f: fr) {
      for(auto t: g[f]) {
        if(s[t] == -1) s[t] = s[f]+1;
        if(s[t] == s[f]+1) {
          d[t] = (d[t]+d[f])%MOD;
          to.insert(t);
        }
      }
    }
    fr = to;
  }

  print(d[n]);
}

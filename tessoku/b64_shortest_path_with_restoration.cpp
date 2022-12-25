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
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll n, m;
  cin >> n >> m;

  v u(2); ll c;
  vvp g(n+1);
  rep(i, m) {
    cin >> u[0] >> u[1] >> c;
    rep(j, 2) g[u[j]].pb(mp(u[1-j], c));
  }

  vp hist(n+1, mp(-1, -1)); hist[1] = mp(-1, 0);
  vp fr = {mp(1, 0)};
  while(fr.size()) {
    vp to;
    for(auto f: fr) {
      for(auto t: g[f.fi]) {
        if(hist[t.fi].se == -1 || f.se+t.se < hist[t.fi].se) {
          hist[t.fi] = mp(f.fi, t.se+f.se);
          to.pb(mp(t.fi, t.se+f.se));
        }
      }
    }
    fr.swap(to);
  }
  
  v restore;
  ll prev = n;
  while(prev != -1) {
    restore.pb(prev);
    prev = hist[prev].fi;
  }

  rrep(i, restore.size()) cout << restore[i] << " ";
  cout << endl;
}

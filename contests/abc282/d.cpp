#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
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

  vv g(n+1);
  v u(2);
  rep(i, m) {
    cin >> u[0] >> u[1];
    rep(j, 2) g[u[j]].pb(u[1-j]);
  }

  ll r=0;
  v d(n+1, -1); 
  repi(i, 1, n+1) {
    if(d[i] != -1) continue;
    d[i] = 0;
    bool l = true;
    v fr = {i};
    ll c0 = 1, c1 = 0;
    while(fr.size()) {
      v to;
      for(auto f: fr) {
        for(auto t: g[f]) {
          if(d[t] == -1) {
            if(l) {
              d[t] = 1;
              c1++;
            } 
            else {
              d[t] = 0;
              c0++;
            }
            to.pb(t);
          }
          if(d[t]==1 && !l) {
            print(0);
            return 0;
          }
          if(d[t]==0 && l) {
            print(0);
            return 0;
          }
        }
      }
      fr.swap(to);
      l = !l;
    }
    r += c0*(n-c0);
    r += c1*(n-c1);
  }

  print(r/2-m);
}

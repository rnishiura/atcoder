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
// #define fi first
// #define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi(f) f[pla]
#define se(f) f[swi]
#define th(f) f[len]
// #define 
#define pla 0
#define swi 1
#define len 2
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll N, M, K;
  cin >> N >> M >> K;
  
  // let's input'em
  v u(2);
  ll a;
  vector<vector<set<ll>>> vs(2, vector<set<ll>>(N+1));
  rep(i, M) {
    cin >> u[0] >> u[1] >> a;
    for(ll j=0; j<2; j++) vs[a][u[j]].insert(u[1-j]);
  }
  
  unordered_set<ll> sw; rep(i, K) { cin >> a; sw.insert(a); }

  vv fr;
  set<pair<ll, ll>> pool;
  vv shortest(2, v(N+1, LL_MAX_S));
  fr.pb({1, 1, 0});
  pool.insert(mp(1, 1));

  while(fr.size()) {
    vv to;
    for(auto f: fr) {
      vv cand;
      for(auto t: vs[f[swi]][f[pla]]) cand.pb({t, f[swi], f[len]+1});
      if(contains(f[pla], sw)) for(auto t: vs[1-f[swi]][f[pla]]) cand.pb({t, 1-f[swi], f[len]+1});
      for(auto p: cand) {
        if(!(contains(mp(p[pla], p[swi]), pool) && shortest[p[swi]][p[pla]] <= p[len])) {
          shortest[p[swi]][p[pla]] = p[len];
          pool.insert(mp(p[pla], p[swi]));
          to.pb(p);
        }
      }
    }
    fr.swap(to);
  }


  ll min_val = LL_MAX_S;
  if(contains(mp(N, 0), pool)) min_val = min(min_val, shortest[0][N]);
  if(contains(mp(N, 1), pool)) min_val = min(min_val, shortest[1][N]);

  if(min_val == LL_MAX_S) {
    print(-1);
  } else {
    print(min_val);
  }
}

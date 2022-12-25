#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define key first
#define val second
#define endl '\n'
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;

  vvp g(n+1); v u(2); ll c;
  rep(i, n-1) {
    cin >> u[0] >> u[1] >> c;
    rep(j, 2) g[u[j]].pb(mp(u[1-j], c));
  }

  v visit(n+1, 0); visit[a] = 1;
  vp fr = {mp(a, 0)};
  set<ll> memo; memo.insert(0);

  while(fr.size()) {
    vp to;
    for(auto f: fr) {
      for(auto t: g[f.key]) {
        if(t.key != b && !visit[t.key]) {
          visit[t.key] = 1;
          memo.insert(f.val^t.val);
          to.pb(mp(t.key, f.val^t.val));
        }
      }
    }
    fr = to;
  }

  visit = v(n+1, 0); visit[b] = 1;
  fr = {mp(b, 0)};

  while(fr.size()) {
    vp to;
    for(auto f: fr) {
      for(auto t: g[f.key]) {
        if(!visit[t.key]) {
          visit[t.key] = 1;
          if(contains(f.val^t.val, memo)) {
            print("YES");
            return;
          }
          to.pb(mp(t.key, f.val^t.val));
        }
      }
    }
    fr = to;
  }


  print("NO");
}

int main(void) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  ll t; cin >> t;
  rep(i, t) { solve(); }

  return 0;
}
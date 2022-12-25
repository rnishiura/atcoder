#include <bits/stdc++.h>
#define MOD 998244353
#define LL_MAX_S  (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define unordered_multiset multiset
#define unordered_set set
#define unordered_map map
#define mnl(N, i)  ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns(N, i)  ((N-1)/i) 
#define endl '\n'
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

bool range_contains(ll l, ll r, set<ll> &g) {
  if(contains(l, g) || contains(r, g)) {
    return true;
  } 
  if(g.lower_bound(l) != g.lower_bound(r)) {
    return true;
  } else {
    return false;
  }
}

void solve() {
  ll n, m; cin >> n >> m;
  vector<set<ll>> g(n+1);
  ll s, t;
  rep(i, m) {
    cin >> s >> t;
    g[s].insert(t);
    g[t].insert(s);
  }

  ll cnt = 0, r = 2;
  repi(l, 1, n+1) {
    while(r < n+1 && !range_contains(l, r, g[r])) { r++; }
    // print2(l, r);
    cnt += r-l;
  }
  print(cnt);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}

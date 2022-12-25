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

ll ford_fulkerson(ll pos, ll stop, ll min_cost, v &hist, vv& g, vv& cost) {
  hist[pos] = true;

  if(pos == stop) { hist[pos] = false; return min_cost; }

  for(ll ngb: g[pos]) {
    if(!hist[ngb] && cost[pos][ngb] > 0) {
      ll f = ford_fulkerson(ngb, stop, min(min_cost, cost[pos][ngb]), hist, g, cost);
      if(f > 0) {
        cost[pos][ngb] -= f;
        cost[ngb][pos] += f;
        return f;
      }
    }
  }

  return 0;
}

ll solve_ford_fulkerson(ll start, ll end, ll size, vv &g, vv &cost) {
  ll ret = 0, f;
  while(true) {
    v hist(size+1, false);
    f = ford_fulkerson(start, end, LL_MAX_S, hist, g, cost);
    if(f == 0) break;
    ret += f;
  }
  return ret;
}

void solve() {
  ll n, m; cin >> n >> m;

  vv g(n+1);
  vv cost(n+1, v(n+1, 0));
  ll _u, _v, _c;
  rep(i, m) {
    cin >> _u >> _v >> _c;
    g[_u].pb(_v); g[_v].pb(_u); cost[_u][_v] = _c;
  }

  print(solve_ford_fulkerson(1, n, n, g, cost));
}


int main(void) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t = 1; 
  // cin >> t;
  rep(i, t) solve();
}

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
  for(ll to: g[pos]) {
    if(!hist[to] && cost[pos][to] > 0) {
      ll f = ford_fulkerson(to, stop, min(min_cost, cost[pos][to]), hist, g, cost);
      if(f > 0) {
        cost[pos][to] -= f;
        cost[to][pos] += f;
        return f;
      }
    }
  }
  return 0;
}

ll solve_ford_fulkerson(ll start, ll stop, ll size, vv &g, vv &cost) {
  ll f, ret = 0;
  while(true) {
    v hist(size+1, false);
    f = ford_fulkerson(start, stop, LL_MAX_S, hist, g, cost); if(f == 0) break;
    ret += f;
  }
  return ret;
}

void solve() {
  ll n, m; cin >> n >> m;

  // 0 - 23: hour
  // 26 - n+26: worker
  // 24: start
  // 25: stop 
  vv g(n+27);
  vv cost(n+27, v(n+27, 0));
  string s;

  rep(i, 24) { g[24].pb(i); g[i].pb(24); cost[24][i] = m; }

  repi(i, 26, n+27) { g[i].pb(25); g[25].pb(i); cost[i][25] = 10; }

  rep(i, n) {
    cin >> s;
    rep(j, 24) {
      if(s[j] == '1') {
        g[j].pb(26+i); g[26+i].pb(j);
        cost[j][26+i] = 1;
      }
    }
  }

  if(solve_ford_fulkerson(24, 25, n+27, g, cost) == 24*m) {
    print("Yes");
  } else {
    print("No");
  }
}


int main(void) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t = 1; 
  // cin >> t;
  rep(i, t) solve();
}

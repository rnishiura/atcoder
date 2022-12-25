#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
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

void solve() {
  ll n, m; 
  cin >> n >> m;
  vv a(n, v(m)); 
  ll cnt = 0;
  v b(n, 0);
  rep(i, n) {
    rep(j, m) {
      cin >> a[i][j];
      cnt += a[i][j];
      b[i] += a[i][j];
    }
  }

  if(cnt % n) {
    print(-1);
    return;
  }
  vector<set<ll>> c(m);
  rep(i, n) {
    if(b[i] >= cnt/n) {
      continue;
    }
    rep(j, m) {
      if(a[i][j] == 0) {
        c[j].insert(i);
      }
    }
  }

  vv r;
  rep(i, n) {
    if(b[i] <= cnt/n) {
      continue;
    }
    rep(j, m) {
      if(c[j].size() == 0) continue;
      if(a[i][j] == 1) {
        while(true) {
          auto it = c[j].begin();
          while(c[j].begin() != c[j].end() && b[*c[j].begin()] == cnt/n) {
            c[j].erase(*c[j].begin());
          }
          if(c[j].begin() == c[j].end()) break;
          ll val = *c[j].begin();
          a[i][j] = 0;
          b[i]--;
          a[val][j] = 1;
          b[val]++;
          c[j].erase(val);
          r.pb({i+1, val+1, j+1});
          break;
        }
      }
      if(b[i] == cnt/n) break;
    }
  }
  print(r.size());
  rep(i, r.size()) {
    print3(r[i][0], r[i][1], r[i][2]);
  }
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}

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

ll n, k;
vv T;

ll fact(ll f, ll t, ll vn, vector<bool> vis) {
  if(vn == n) {
    if(t+T[f][0] == k) {
      // print2(t+T[f][0], k);
      return 1;
    } else {
      // print2(t+T[f][0], k);
      return 0;
    }
  }
  ll r = 0;
  rep(i, n) {
    if(!vis[i]) {
      vector<bool> nvis(vis.begin(), vis.end());
      nvis[i] = true;
      r += fact(i, t+T[f][i], vn+1, nvis);
    }
  }
  return r;
}

void solve() {
  cin >> n >> k;
  T = vv(n, v(n, 0));

  rep(i, n) {
    rep(j, n) {
      cin >> T[i][j];
    }
  }
  vector<bool> vis(n, false);
  vis[0] = true;
  print(fact(0, 0, 1, vis));
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

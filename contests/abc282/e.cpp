#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
// #define MOD 998244353
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

ll MOD;

ll power(ll n, ll m) {
  ll s=1;
  while(m) {
    s = (s * (m % 2 ? n : 1)) % MOD;
    n = (n*n) % MOD;
    m >>= 1;
  }
  return s;
}

void solve() {
  ll n; cin >> n >> MOD;
  v a(n); rep(i, n) cin >> a[i];
  vv m(n, v(n));
  v s;
  rep(i, n) {
    repi(j, i+1, n) {
      m[i][j] = (power(a[i], a[j]) + power(a[j], a[i])) % MOD;
      s.pb(m[i][j]);
      cout << m[i][j] << " ";
    }
    cout << endl;
  }

  sort(s.rbegin(), s.rend());

  ll r=0;
  rep(i, n-1) r+=s[i];
  print(r);
}
/*
環構造
23
34
42
yes -> r = r - s[n-1] + s[n]
no -> r
部分的に環構造
しっぽをs[n]につぎかえ
*/

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

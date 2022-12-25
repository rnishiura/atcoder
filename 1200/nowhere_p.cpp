#include <bits/stdc++.h>
#define MOD 1000000007
#define LL_MAX_S  (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
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
#define print2(y, z)    cout << (y) << ' '; print(z);
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

ll modpow(ll p, ll n) {
  ll b = 1, ret = 1;
  v a = {1, p};
  while(b <= n) {
    a.pb(square(*a.rbegin()) % MOD);
    b <<= 1;
  }
  ll i = a.size()-1;
  while(n) {
    if(n / b) {
      ret *= a[i];
      ret %= MOD;
      n -= b;
    }
    --i;
    b >>= 1;
  }
  return ret;
}

void solve() {
  ll n, p; cin >> n >> p;

  ll ret = p-1;
  ret *= modpow(p-2, n-1);
  ret %= MOD;

  print(ret);
}

int main(void) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t = 1; 
  // cin >> t;
  rep(i, t) solve();
}

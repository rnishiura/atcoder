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

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a%b==0) return b;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  ll g = gcd(a, b);
  return g * (a/g) * (b/g);
}

vp factorize(ll m) {
  vp r; ll c;
  for(ll i=2; i*i<=m; i++) {
    c = 0;
    while(m % i == 0) { m /= i; c++; }
    if(c) r.pb(mp(i, c));
  }
  if(m > 1) r.pb(mp(m, 1));
  return r;
}

void solve() {
  ll n, m; cin >> n >> m;
  vp a = factorize(gcd(n, m));
  print(a.size()+1);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

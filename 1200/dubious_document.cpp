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

void solve() {
  ll n; cin >> n;
  map<char, ll> mem;
  for(char c = 'a'; c <= 'z'; c++) mem[c] = LL_MAX_S;

  string s;
  rep(i, n) {
    cin >> s;
    map<char, ll> tmp;
    rep(j, s.length()) {
      tmp[s[j]]++;
    }
    for(char c = 'a'; c <= 'z'; c++) {
      mem[c] = min(mem[c], tmp[c]);
    }
  }
  vector<char> r;
  for(char c = 'a'; c <= 'z'; c++) {
    rep(i, mem[c]) {
      r.pb(c);
    }
  }
  s = string(r.begin(), r.end());
  print(s);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

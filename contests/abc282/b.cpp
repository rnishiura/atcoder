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
  ll n, m; cin >> n >> m;
  v a(n); 
  string s;
  ll c, k;
  rep(i, n) {
    cin >> s;
    c = 0;
    k = 1;
    rep(j, m) {
      if(s[j]=='o') {
        c += k;
      }
      k <<= 1;
    }
    a[i] = c;
  }
  // rep(i, n) {
  //   cin >> a[i];
  // }
  // ll c = 0;
  // rep(i, n) {
  //   repi(j, i+1, n) {
  //     ll k = 0;
  //     rep(k, m) {
  //       if(a[i][k] == 'o' || a[j][k] == 'o') k++;
  //     }
  //     if(k==m) {
  //       c++;
  //     }
  //   }
  // }

  // print(c);
  k = (1LL << m) - 1;
  c = 0;
  rep(i, n) {
    // print(a[i]);
    repi(j, i+1, n) {
      // print2(a[i] | a[j], k);
      if((a[i] | a[j]) == k) {
        c++;
      }
    }
  }
  print(c);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

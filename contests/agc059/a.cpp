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
  ll n, q; 
  string s;
  cin >> n >> q >> s;
  map<string, v> c;
  vector<string> names = {"A", "B", "C"};
  vector<string> bnames = {"BA", "BC", "CA", "CB", "AB", "AC"};

  for(string name: names) c[name] = v(n+1, 0);
  for(string name: bnames) c[name] = v(n+1, 0);
  s = "X" + s;

  repi(i, 1, n+1) {
    for(string name: names) {
      if(s[i-1] != name[0] && s[i] == name[0]) {
        c[name][i] = c[name][i-1] + 1;
      } else {
        c[name][i] = c[name][i-1];
      }
    }
    for(string name: bnames) {
      if(s[i-1] != name[0] && s[i-1] != name[1] && (s[i] == name[0] || s[i] == name[1] )) {
        c[name][i] = c[name][i-1] + 1;
      } else {
        c[name][i] = c[name][i-1];
      }
    }
  }

  // print(c["AB"][3]);

  ll l, r, ret;
  rep(i, q) {
    ret = LL_MAX_S;
    cin >> l >> r;
    for(string ff: names) {
      for(string ss: names) {
        if(ff == ss) continue;
        // print3(ff+ss, l, r);
        ll tmp = c[ff][r]-c[ff][l]+c[ff+ss][r]-c[ff+ss][l];
        if(s[l] == ff[0]) tmp++;
        if(s[l] == ff[0] || s[l] == ss[0]) tmp++;
        ret = min(ret, tmp);
      }
    }
    print(ret);
  }
  // print("END");
}

int main(void) {
  // cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll te;
  cin >> te;

  string s, t;
  ll n, xor_flg_1, xor_flg_0;
  rep(i, te) {
    cin >> n >> s >> t;
    xor_flg_0=true;
    xor_flg_1=true;
    vp op;
    rep(j, n) {
      if(s[j]==t[j]) xor_flg_1=false;
      if(s[j]!=t[j]) xor_flg_0=false;
    }
    if(!(xor_flg_0 || xor_flg_1)) {
      print("NO");
      continue;
    }
    if(xor_flg_0) {
      op.pb(mp(1, n));
    } 
    ll cnt=0;
    rep(j, n) {
      if(s[j] == (xor_flg_0 ? '0' : '1')) {
        op.pb(mp(j+1, j+1));
        cnt++;
      }
    }
    if(cnt%2 == 0) {
      op.pb(mp(1, n));
      op.pb(mp(1, 1));
      op.pb(mp(2, n));
    }

    print("YES");
    print(op.size());
    for(auto v: op) {
      print2(v.fi, v.se);
    }
  }
}

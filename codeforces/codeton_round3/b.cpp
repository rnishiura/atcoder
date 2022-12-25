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
  ll t;
  cin >> t;

  string s;
  ll n, cx, cy, cnt, mcx, mcy;
  rep(i, t) {
    cin >> n;
    cin >> s;
    cx = 0;
    cy = 0;
    mcx=0; mcy=0;
    cnt = 1;
    rep(j, n) {
      if(s[j] == '0') mcx++;
      else mcy++;
    }
    repi(j, 1, n) {
      if(s[j] != s[j-1]) {
        if(s[j-1] == '0') cx = max(cx, cnt);
        else cy = max(cy, cnt);
        cnt = 0;
      }
      cnt++;
    }
    if(s[n-1] == '0') cx = max(cx, cnt);
    else cy = max(cy, cnt);
    print(max(max(cx*cx, cy*cy), mcx*mcy));
  }
}

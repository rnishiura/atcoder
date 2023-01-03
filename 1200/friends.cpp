/*
Problem: https://atcoder.jp/contests/abc177/tasks/abc177_d
Author: rnishiura
Date: 221231
Description:

*/

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
  ll n, m;
  cin >> n >> m;

  vv g(n+1);
  v u(2);
  rep(i, m) {
    cin >> u[0] >> u[1];
    rep(j, 2) g[u[j]].pb(u[1-j]);
  }

  v d(n+1, -1); d[1] = 0;
  ll max_cnt = 0;
  repi(i, 1, n+1) {
    if(d[i] != -1) continue;
    v fr = {i};
    ll cnt = 1;
    while(fr.size()) {
      v to;
      for(auto f: fr) {
        for(auto t: g[f]) {
          if(d[t] == -1) {
            d[t] = cnt;
            to.pb(t);
            cnt++;
          }
        }
      }
      // cnt++;
      fr.swap(to);
    }
    max_cnt = max(max_cnt, cnt);
  }

  print(max_cnt);
}

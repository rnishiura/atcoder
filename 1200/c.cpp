#include <bits/stdc++.h>
#define Rep(x, a, b) for(ll x=a; x<b; x++)
#define square(z) ((z)*(z))
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
#define MOD 998244353
#define fi first
#define se second
#define pb push_back 
#define mp make_pair 
using namespace std;
using  ll = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll H, W; cin >> H >> W;
  vector<vector<bool>> A(H+2, vector<bool>(W+2, false));
  ll wcnt = 0;
  string in;
  Rep(i, 0, H) {
    cin >> in;
    Rep(j, 0, W) {
      if(in[j] == '.') {
        A[i+1][j+1] = true;
        wcnt++;
      }
    }
  }
  set<pair<ll, ll>> pool{mp(1,1)};
  vp from = {mp(1,1)};
  ll cnt=1;
  while(from.begin() != from.end()) {
    // for(auto f: from) {
    //   cout << "(" << f.fi << "," << f.se << "),";
    // }
    // cout << endl;
    if(pool.find(mp(H, W)) != pool.end()) {
      print(wcnt-cnt);
      return 0;
    }
    vp to;
    for(auto f: from) {
      vp n = {mp(f.fi+1, f.se), mp(f.fi-1, f.se), mp(f.fi, f.se+1), mp(f.fi, f.se-1)};
      for(auto t: n) {
        if(A[t.fi][t.se] and pool.find(t) == pool.end()) {
          pool.insert(t);
          to.pb(t);
        }
      }
    }
    from.swap(to);
    cnt++;
  }
  // print(cnt);
  print(-1);
}
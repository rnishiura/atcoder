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
#define SPACE '.'
#define WALL '#'
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll h, w, sy, sx, gy, gx;
  cin >> h >> w >> sy >> sx >> gy >> gx;
  --sy; --sx; --gy; --gx;

  vector<string> g(h);
  rep(i, h) cin >> g[i];

  vv hist(h, v(w, -1)); hist[sy][sx] = 0;
  vp fr = {mp(sy, sx)};
  vp dir = {mp(1, 0),mp(0, 1),mp(-1, 0),mp(0, -1)};
  ll y, x;
  while(fr.size()) {
    vp to;
    for(auto f: fr) {
      for(auto d: dir) {
        y = f.fi+d.fi;
        x = f.se+d.se;
        if(g[y][x] == SPACE && hist[y][x] == -1) {
          hist[y][x] = hist[f.fi][f.se] + 1;
          to.pb(mp(y, x));
        }
      }
    }
    fr.swap(to);
  }
  print(hist[gy][gx]);
}

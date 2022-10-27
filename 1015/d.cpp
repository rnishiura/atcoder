#include <bits/stdc++.h>
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

ll lb_val(ll n, ll lim, set<ll> s) {
  set<ll>::iterator it = s.lower_bound(n);
  return it == s.begin() ? lim : *prev(it); 
}
ll ub_val(ll n, ll lim, set<ll> s) {
  set<ll>::iterator it = s.upper_bound(n);
  return it == s.end() ? lim : *it; 
}
int main(void) {
  ll H, W, y, x; cin >> H >> W >> y >> x;
  ll N; cin >> N;

  map<ll, set<ll>> UD;
  map<ll, set<ll>> LR;

  for(ll i=0; i<N; i++) {
    ll r, c; cin >> r >> c;
    UD[c].insert(r);
    LR[r].insert(c);
  }

  ll Q; cin >> Q;

  for(ll i=0; i<Q; i++) {
    char d; ll l; cin >> d >> l;

    switch(d) {
      case 'U': 
        y = max(y-l, lb_val(y,   0, UD[x])+1); 
        break;
      case 'D': 
        y = min(y+l, ub_val(y, H+1, UD[x])-1); 
        break;
      case 'L': 
        x = max(x-l, lb_val(x,   0, LR[y])+1);
        break;
      case 'R': 
        x = min(x+l, ub_val(x, W+1, LR[y])-1); 
        break;
    }
    cout << y << " " << x << endl;
  }

}

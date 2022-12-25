#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define print(z) cout << (z) << endl
#define print2(x, y) cout << (x) << " " << (y) << endl
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 3.141592653589793
#define mnl (N, i) ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns (N, i) ((N-1)/i) 
#define r(t) fmod(t+720, 360)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll n; cin >> n;

  vp pts(n); ll x, y;
  rep(i, n) {
    cin >> x >> y;
    pts[i] = mp(x, y);
  }

  double max_val = 0;
  rep(i, n) {
    vector<double> args;
    rep(j, n) {
      if(i == j) continue;
      args.pb(r(atan2(pts[j].se-pts[i].se, pts[j].fi-pts[i].fi)/pi*180));
    }
    // rep(i, n-1) cout << args[i] << " ";
    // cout << endl;

    sort(args.begin(), args.end());
    ll a = *args.begin();
    ll b = *prev(args.end());
    args.pb(a+360);
    args.pb(b-360);
    sort(args.begin(), args.end());

    // for(auto a1: args) cout << a1 << " ";
    // cout << endl;
    // print(i);
    // bs here
    for(auto a1: args) {
      if(r(a1) != a1) continue;
      // print2("r(a1+pi):", r(a1+pi));
      auto it1 = lower_bound(args.begin(), args.end(), r(a1+180));
      auto it2 = prev(it1);
      max_val = max(max_val, min(360-abs(*it1-a1), abs(*it1-a1)));
      max_val = max(max_val, min(360-abs(a1-*it2), abs(a1-*it2)));
      // cout << *it2 << " " << *it1 << endl;
      // print2(min(360-abs(*it1-a1), abs(*it1-a1)), min(360-abs(a1-*it2), abs(a1-*it2)));
    }

    // print("**");
  }

  printf("%.12lf\n", max_val);
}

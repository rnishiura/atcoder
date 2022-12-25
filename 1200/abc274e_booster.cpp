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

void bitwise_print(ll n, ll b) {
  rep(i, b) { cout << (int)(bool)(n&(1LL<<i)); }
  cout << endl;
}

ll gen_combination(ll n) { return (1LL<<n) - 1; }

bool next_combination(ll &n, ll b) {
  bool flg=false;
  ll cnt=0;
  rep(i, b) {
    if(n&(1LL<<i)) {flg = true; cnt++;} 
    if(flg && !(n&(1LL<<i))) {
      // n = n & ~((1LL<<i) - 1);
      n = n ^ (n & ((1LL<<i)-1));
      n = n | (1LL<<i);
      n = n | ((1LL<<(cnt-1))-1);
      return true;
    }
  }
  return false;
}

int main(void) {
  ll n, m; cin >> n >> m;

  v X(n+m), Y(n+m); rep(i, n+m) cin >> X[i] >> Y[i];

  ll new_n;

  vector<vector<double>> dp(n+m, vector<double>(1LL<<(n+m), DOUBLE_MAX_S));

  // initial vals
  rep(i, n+m) dp[i][1LL<<i] = sqrt(square(X[i])+square(Y[i]));

  // the journey
  repi(i, 2, n+m+1) {
    new_n = gen_combination(i);
    do {
      rep(j, n+m) {
        if(new_n&(1LL<<j)) {
          ll old_n = new_n^(1LL<<j);
          ll speed = 1;
          repi(k, n, n+m) if((old_n)&(1LL<<k)) speed <<= 1;
          rep(k, n+m) {
            if(old_n&(1LL<<k)) {
              double dist = sqrt(square(X[j]-X[k])+square(Y[j]-Y[k]));
              dp[j][new_n] = min(dp[j][new_n], dp[k][old_n] + dist / speed);
            }
          }
        }
      }
    } while(next_combination(new_n, n+m));
  }

  // return to zero
  double ret = DOUBLE_MAX_S;
  repi(i, 0, m+1) {
    ll treasure = gen_combination(i);
    ll cities = (1LL<<n) - 1;
    do {
      rep(j, n+m) {
        ret = min(ret, dp[j][cities|(treasure<<n)] + dp[j][1LL<<j] / (1LL<<i)); 
      }
    } while(next_combination(treasure, m));
  }

  printf("%.10lf\n", ret);
}

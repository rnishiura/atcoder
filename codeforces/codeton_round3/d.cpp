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

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a%b==0) return b;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  ll g = gcd(a, b);
  return g * (a/g) * (b/g);
}

int main(void) {
  ll te;
  cin >> te;

  ll n, m;
  ll a, pa;
  ll r;
  rep(i, te) {
    r = 1;
    cin >> n >> m;
    cin >> pa;

    rep(j, n-1) {
      cin >> a;
      r *= m/a-m/(a*pa/gcd(a, pa));
      r %= MOD;
      pa = a;
    }
    print(r);
  }
}

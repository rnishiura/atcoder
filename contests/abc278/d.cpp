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
#define mnl (N, i) ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns (N, i) ((N-1)/i) 
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll n, q;
  cin >> n;

  unordered_map<ll, ll> a;
  ll p;
  repi(i, 1, n+1) {
    cin >> p;
    a[i] = p;
  }

  cin >> q;
  ll xb = -1, t, xq, iq;
  rep(i, q) {
    cin >> t;
    unordered_map<ll, ll> b;
    switch(t) {
      case 1:
      cin >> xb;
      a.swap(b);
      break;
      case 2:
      cin >> iq >> xq;
      if(contains(iq, a)) {
        a[iq] += xq;
      } else {
        a[iq] = xb+xq;
      }
      break;
      case 3:
      cin >> iq;
      if(contains(iq, a)) {
        print(a[iq]);
      } else {
        print(xb);
      }
    }
  }
}

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
#define endl '\n'
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll t; cin >> t;
  ll n;
  rep(i, t) {
    cin >> n;
    v a(n);
    rep(j, n) cin >> a[j];
    ll v0=0, v1=0;
    for(auto v: a) {
      if(v > v0) {
        v1 = v0;
        v0 = v;
      } else if(v > v1) {
        v1 = v;
      }
    }
    for(auto v: a) {
      if(v == v0) {
        cout << v-v1 << " ";
      } else {
        cout << v-v0 << " ";
      }
    }
    cout << endl;
  }

  
}

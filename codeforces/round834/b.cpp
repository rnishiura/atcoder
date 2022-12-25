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
  ll te;
  cin >> te;

  ll m, s;
  rep(i, te) {
    cin >> m >> s;
    m++;
    v a(m); a[0] = 0;
    repi(j, 1, m) cin >> a[j];
    sort(a.begin(), a.end());
    rep(j, m-1) {
      repi(k, a[j]+1, a[j+1]) {
        s -= k;
      }
    }
    ll p=1;
    while(s > 0) {
      s -= a[m-1]+p;
      p++;
    }
    if(s == 0) {
      print("YES");
    } else {
      print("NO");
    }
  }
}

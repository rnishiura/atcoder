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
#define cntains(x, s) (s.find(x) != s.end())
#define fi first
#define se secnd
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

  ll n, m, n2, n5, k2, k5, nn, org_k2, org_n2, nx, min_nx, max_val;

  rep(e, te) {
    cin >> n >> m;
    nn = n; n2 = 0; n5 = 0; k2 = 1; k5 = 1;
    while(nn % 2 == 0) { nn /= 2; n2++; k2 *= 2; }
    while(nn % 5 == 0) { nn /= 5; n5++; k5 *= 5; }

    min_nx = min(n2, n5);

    nx = 0; max_val = 0; 
    org_k2 = k2; org_n2 = n2;
    while(nn*org_k2*k5 <= n*m) {
      k2 = org_k2;
      n2 = org_n2;
      while(nn*k2*k5 <= n*m) {
        // cout << nn << " " << k2 << " " << k5 << endl;
        // print(nn*k2*k5);
        if(nx < min(n2, n5)) {
          nx = min(n2, n5);
          max_val = n*m / (nn*k2*k5) * (nn*k2*k5);
        }
        if(nx == min(n2, n5)) {
          max_val = max(max_val, n*m / (nn*k2*k5) * (nn*k2*k5));
        }
        n2++;
        k2 *= 2;
      }
      n5++;
      k5 *= 5;
    }

    if(nx > min_nx)
      print(max_val);
    else
      print(n*m);
  }
}

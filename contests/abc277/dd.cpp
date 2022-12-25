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

int main(void) {
  ll n, m;
  cin >> n >> m;

  v a(n);
  rep(i, n) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  ll max_val = a[0];
  ll c_max_val = a[0];
  ll chain = 1;
  rep(i, 2*n+1) {
    if(chain == n) break;
    if((a[(i+1)%n]-a[i%n]+m)%m <= 1) {
    //   print();
      chain++;
      c_max_val += a[(i+1)%n];
    } else {
      chain = 1;
      c_max_val = a[(i+1)%n];
    }
    // print2(a[(i+1)%n], c_max_val);
    // print((a[(i+1)%n]-a[i%n]+m)%m);
    max_val = max(max_val, c_max_val);
  }

  ll sum = 0;
  for(auto val: a) sum += val;
  print(sum - max_val);
}

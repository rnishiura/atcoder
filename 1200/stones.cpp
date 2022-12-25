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
  ll n, k; cin >> n >> k;
  v a(k); rep(i, k) cin >> a[i];

  ll takahashi_score = 0;
  ll max101 = 0;
  ll max110 = 0;
  ll max100 = 0;
  ll takahashi, aoki, takahashi2;
  v::iterator it;

  bool takahashi_turn = true;

  while(n) {
    max101 = 0;
    rrep(i, k) {
      takahashi = a[i];
      if(n-takahashi < 0) continue;
      if(n-takahashi == 0) {
        max100 = takahashi;
        max110 = takahashi;
        break;
      }

      it=upper_bound(a.begin(), a.end(), n-takahashi);
      aoki = *(it-1);

      if(n-takahashi-aoki == 0) {
        takahashi2 = 0;
      } else {
        it = upper_bound(a.begin(), a.end(), n-takahashi-aoki);
        takahashi2 = *(it-1);
      }

      if(takahashi + takahashi2 > max101) {
        max101 = takahashi + takahashi2;
        max110 = takahashi + aoki;
        max100 = takahashi;
      }
    }
    if(takahashi_turn) takahashi_score += max100;
    n -= max100;
    takahashi_turn = !takahashi_turn;
  }

  print(takahashi_score);
}

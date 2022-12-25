#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define MOD 998244353
#define LL_MAX_S  (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define unordered_multiset multiset
#define unordered_set set
#define unordered_map map
#define mnl(N, i)  ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns(N, i)  ((N-1)/i) 
#define endl '\n'
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void solve() {
  ll n; cin >> n;

  ll odd_cnt = 0;
  ll min_e2o = LL_MAX_S;
  ll min_o2e = LL_MAX_S;
  ll tmp_cnt;
  ll a;
  rep(i, n) {
    cin >> a;
    tmp_cnt = 0;
    if(a % 2) {
      odd_cnt++;
      while(a % 2) {
        a /= 2;
        tmp_cnt++;
      }
      min_o2e = min(min_o2e, tmp_cnt);
    }
    else if(a % 2 == 0) {
      while(a && a % 2 == 0) {
        a /= 2;
        tmp_cnt++;
      }
      if(a % 2) min_e2o = min(min_e2o, tmp_cnt);
    }
  }
  if(odd_cnt % 2 == 0) {
    print(0);
    return;
  }
  print(min(min_e2o, min_o2e));

}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}

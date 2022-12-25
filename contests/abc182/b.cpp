#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define MOD 998244353
#define LL_MAX  (1LL << 62)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, a) ((a).find(x) != (a).end())
#define all(a) (a).begin(), (a).end()
#define sum(a)  (accumulate(all(a), 0LL))
#define mini(a) (min_element(all(a)) - (a).begin())
#define maxi(a) (max_element(all(a)) - (a).begin())
#define mine(a) (*min_element(all(a)))
#define maxe(a) (*max_element(all(a)))
#define lowb(x, a) (lower_bound(all(a), (x)) - (a).begin())
#define uppb(x, a) (upper_bound(all(a), (x)) - (a).begin())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define divl(n, m)  ((n+m)/(m)) 
#define divle(n, m) ((n+m-1)/(m)) 
#define divse(n, m) ((n)/(m)) 
#define divs(n, m)  ((n-1)/(m)) 
#define endl '\n'
#define printnl(z)      cout << (z) << ' '
#define println()       cout << endl
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
#define unordered_multiset multiset
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void solve() {
  ll n; cin >> n;
  v a(n); rep(i, n) {
    cin >> a[i];
  }

  ll max_val = maxe(a);
  ll max_k = 0;
  ll max_cnt = 0, cnt;
  repi(k, 2, max_val+1) {
    cnt = 0;
    for(ll val: a) {
      if(val % k == 0) {
        cnt++;
      }
    }
    if(cnt >= max_cnt) {
      max_cnt = cnt;
      max_k = k;
    }
  }
  print(max_k);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}

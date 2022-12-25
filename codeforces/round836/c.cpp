#include <bits/stdc++.h>
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)    for(ll x=0; x<n; x++)
#define repi(x, a, b) for(ll x=a; x<b; x++)
#define rrep(x, n)    for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define unordered_multiset multiset
#define unordered_set set
#define unordered_map map
#define mnl(N, i) ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns(N, i) ((N-1)/i) 
#define endl '\n'
#define print(z)    cout << (z) << endl
#define print2(x, y) cout << (x) << ' ' << (y) <<endl
#define print3(x, y, z) cout<<(x)<<' '<<(y)<<' '<<(z)<<endl
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void solve() {
  ll n, x; cin >> n >> x;
  v a(n+1);
  if(n % x) {
    print(-1);
  } else {
    a[1] = x;
    a[n] = 1;
    repi(i, 2, n) {
      if(i==x) {
        a[i] = n;
      } else {
        a[i] = i;
      }
    }
    ll idx = x, i = x+1;
    while(i <= n) {
      if(a[i]%idx == 0 && a[idx]%i == 0 && a[idx] > a[i]) {
        swap(a[i], a[idx]);
        idx = i;
        i = idx;
      }
      i++;
    }
    repi(i, 1, n+1) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}

int main(void) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t; cin >> t;
  rep(i, t) {
    solve();
  }
}

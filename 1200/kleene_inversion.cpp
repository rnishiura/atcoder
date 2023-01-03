#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define MOD 1000000007
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

ll inv(ll i) {
  if(i==1) return 1;
  return MOD - inv(MOD%i) * (MOD/i) % MOD;
}

void solve() {
  ll n, k; cin >> n >> k;
  v a(n); rep(i, n) {
    cin >> a[i];
  }
  v b(n), c(n);
  rep(i, n) {
    rep(j, n) {
      if(i < j && a[i] > a[j]) c[i]++;
      if(a[i] > a[j]) b[i]++;
    }
  }
  ll r=0;
  rep(i, n) {
    r += (2*c[i]+(k-1)*b[i])%MOD*k%MOD*inv(2)%MOD;
    r %= MOD;
  }

  print(r);
}

// a + (n-1)
// a + (n-1) * d

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
